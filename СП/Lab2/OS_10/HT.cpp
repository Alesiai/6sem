#include "HT.h";

using namespace std;

namespace HT {

	const int DELETED = -1;

#pragma region HELPERS
	int generateHash(const Element* element, int size, int p)
	{
		char* arrKeyBytes = new char[element->keylength];
		memcpy(arrKeyBytes, element->key, element->keylength);
		int sumBytes = 0;
		for (int i = 0; i < element->keylength; i++) {
			sumBytes += arrKeyBytes[i];
		}
		double key2 = 5 * ((0.6180339887499 * sumBytes) - int((0.6180339887499 * sumBytes)));
		delete[] arrKeyBytes;
		return (p + sumBytes) % size;
	}

	int nextHash(int hash, int size, int p)
	{
		return (hash + p + p * p) % size;
	}

	DWORD WINAPI SnapShotCycle(HTHANDLE* ht) {
		while (true)
		{
			if (ht) {
				if (time(NULL) >= ht->lastsnaptime + ht->SecSnapshotInterval)
				{
					if (!FlushViewOfFile(ht->Addr, NULL)) {
						cout << "Snapshot error";
						return FALSE;
					}
					else {
						ht->lastsnaptime = time(NULL);
						cout << "\nSnapshot crated";
					}

					ReleaseMutex(ht->Mutex);
				}
			}
			else
				break;
		}
		return TRUE;
	}

	wchar_t* GenerateMutexName(const wchar_t* pathToHT) {
		wchar_t mutexName[MAX_PATH];
		ZeroMemory(mutexName, sizeof(mutexName));
		int j = 0;
		for (int i = 0; i < wcslen(pathToHT); i++) {
			if (pathToHT[i] == L'\\') {
				continue;
			}
			else {
				mutexName[j++] = pathToHT[i];
			}
		}
		return mutexName;
	}

	Element* getElementByHT(HTHANDLE* ht, int n) {
		void* elementAddr = (char*)(ht + 1) + ((ht->MaxKeyLength + ht->MaxPayloadLength + 2 * sizeof(int)) * n);
		int keyLength = *(int*)((char*)elementAddr + ht->MaxKeyLength);
		if (keyLength != 0) {
			Element* element = new Element();
			element->key = elementAddr;
			element->keylength = keyLength;
			element->payload = ((char*)elementAddr + ht->MaxKeyLength + sizeof(int));
			element->payloadlength = *(int*)((char*)elementAddr + ht->MaxKeyLength + sizeof(int) + ht->MaxPayloadLength);
			return element;
		}
		return NULL;
	}

	BOOL setElementToHt(HTHANDLE* ht, Element* element, int n) {
		void* elementAddr = (char*)(ht + 1) + (ht->MaxKeyLength + ht->MaxPayloadLength + 2 * sizeof(int)) * n;

		memcpy(elementAddr, element->key, element->keylength);
		memcpy(((char*)elementAddr + ht->MaxKeyLength), &element->keylength, sizeof(int));
		memcpy(((char*)elementAddr + ht->MaxKeyLength + sizeof(int)), element->payload, element->payloadlength);
		memcpy(((char*)elementAddr + ht->MaxKeyLength + sizeof(int) + +ht->MaxPayloadLength), &element->payloadlength, sizeof(int));
		return TRUE;
	}

	BOOL delatedElement(Element* ptr) { return (*(int*)ptr->key == -1) ? TRUE : FALSE; }

	BOOL equalKeys(Element* el1, Element* el2) { return !memcmp(el1->key, el2->key, el2->keylength) ? TRUE : FALSE; }

	void SetErrorMessage(HTHANDLE* ht, const char* message, int messageLen) { memcpy(ht->LastErrorMessage, (char*)message, messageLen); }

	void setFlagDelation(Element* ptr) { memcpy(ptr->key, &DELETED, sizeof(DELETED)); }

	void UpdateElement(HTHANDLE* ht, Element* el, void* newpayload, int newpayloadlength) {
		ZeroMemory(el->payload, ht->MaxPayloadLength + sizeof(int));
		memcpy(el->payload, newpayload, newpayloadlength);
		memcpy((char*)el->payload + ht->MaxPayloadLength, &newpayloadlength, sizeof(int));
	}

#pragma endregion

#pragma region CONSTRUCTORS
	Element::Element() {
		this->key = nullptr;
		this->keylength = NULL;
		this->payload = nullptr;
		this->payloadlength = NULL;
	}
	Element::Element(const void* key, int keylength) {
		Element();
		this->key = (void*)key;
		this->keylength = keylength;
	}
	Element::Element(const void* key, int keylength, const void* payload, int  payloadlength) {
		this->key = (void*)key;
		this->keylength = keylength;
		this->payload = (void*)payload;
		this->payloadlength = payloadlength;
	}
	Element::Element(Element* oldelement, const void* newpayload, int  newpayloadlength) {
		this->key = oldelement->key;
		this->keylength = oldelement->keylength;
		this->payload = (void*)payload;
		this->payloadlength = payloadlength;
	}

	HTHANDLE::HTHANDLE() { }

	HTHANDLE::HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512])
	{
		this->Capacity = Capacity;
		this->SecSnapshotInterval = SecSnapshotInterval;
		this->MaxKeyLength = MaxKeyLength;
		this->MaxPayloadLength = MaxPayloadLength;
		this->N = 0;
		memcpy(this->FileName, FileName, sizeof(this->FileName));
	}
#pragma endregion

	HTHANDLE* Create(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512])
	{
		HANDLE hf = CreateFile(FileName, GENERIC_WRITE, NULL, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

		HANDLE hm = CreateFileMapping(hf, NULL, PAGE_READWRITE, 0, 360, NULL);//создать объект ядра 
		if (!hm)return NULL;

		LPVOID lp = MapViewOfFile(hm, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (!lp)return NULL;

		HTHANDLE* ht = new(lp) HTHANDLE(Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName); //создать объект ядра 

		ht->File = hf;
		ht->FileMapping = hm;
		ht->Addr = lp;
		ht->lastsnaptime = time(NULL);
		ht->Mutex = CreateMutex(NULL, FALSE, GenerateMutexName(FileName));//MAX_PATH LIMIT

		DWORD SnapShotThread = NULL;
		if (!(ht->SnapshotThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SnapShotCycle, ht, 0, &SnapShotThread))) return NULL;
		return ht;
	}

	HTHANDLE* Open(const wchar_t FileName[512])
	{
		HANDLE hf = CreateFile(FileName, GENERIC_WRITE | GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		HANDLE hm = CreateFileMapping(hf, NULL, PAGE_READWRITE, 0, 0, NULL); //создать объект ядра 
		if (!hm)return NULL;

		LPVOID lp = MapViewOfFile(hm, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (!lp)return NULL;

		HTHANDLE* ht = (HTHANDLE*)lp;
		ht->File = hf;
		ht->FileMapping = hm;
		ht->Addr = lp;
		ht->Mutex = CreateMutex(NULL, FALSE, GenerateMutexName(FileName));

		DWORD SnapShotThread = NULL;
		if (!(ht->SnapshotThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SnapShotCycle, ht, 0, &SnapShotThread))) return NULL;
		return ht;
	}

	BOOL Snap(HTHANDLE* hthandle)
	{
		if (!FlushViewOfFile(hthandle->Addr, NULL))
		{
			ReleaseMutex(hthandle->Mutex);
			SetErrorMessage(hthandle, "Snapshot error", 15);
			return FALSE;
		}
		else
		{
			cout << "\nSNAPSHOT\n";
			hthandle->lastsnaptime = time(NULL);
			ReleaseMutex(hthandle->Mutex);
			return TRUE;
		}
	}

	BOOL Close(const HTHANDLE* hthandle)
	{
		HANDLE mapping, file, mutex;

		memcpy(&mapping, &hthandle->FileMapping, sizeof(HANDLE));
		memcpy(&file, &hthandle->File, sizeof(HANDLE));
		memcpy(&mutex, &hthandle->Mutex, sizeof(HANDLE));

		TerminateThread(hthandle->SnapshotThread, 0);

		UnmapViewOfFile(hthandle->Addr);
		CloseHandle(mapping);
		CloseHandle(file);
		CloseHandle(mutex);

		return TRUE;
	}

	BOOL Insert(HTHANDLE* hthandle, Element* element)
	{
		if (hthandle->N != hthandle->Capacity)
		{
			for (int i = 0, j = generateHash(element, hthandle->Capacity, 0);
				i != hthandle->Capacity;  j = nextHash(j, hthandle->Capacity, ++i))
			{
				Element* elFromHT = getElementByHT(hthandle, j);

				if (elFromHT == NULL || delatedElement(elFromHT))
				{
					setElementToHt(hthandle, element, j);
					hthandle->N++;

					ReleaseMutex(hthandle->Mutex);
					return TRUE;
				}
				if (elFromHT != NULL && equalKeys(elFromHT, element)) {
					SetErrorMessage(hthandle, "key\n", 12);

					ReleaseMutex(hthandle->Mutex);
					return FALSE;
				}
			}
		}
	}

	Element* Get(HTHANDLE* hthandle, Element* element)
	{
		if (hthandle->N != 0)
		{
			for (int i = 0, j = generateHash(element, hthandle->Capacity, 0);
				getElementByHT(hthandle, j) != NULL && i != hthandle->Capacity;
				j = nextHash(j, hthandle->Capacity, ++i))
			{
				Element* elFromHT = getElementByHT(hthandle, j);
				if (!delatedElement(elFromHT) && equalKeys(elFromHT, element))
				{
					ReleaseMutex(hthandle->Mutex);
					return getElementByHT(hthandle, j);
				}
			}
		}

		SetErrorMessage(hthandle, "Not found", 15);
		ReleaseMutex(hthandle->Mutex);
		return NULL;
	}

	BOOL Delete(HTHANDLE* hthandle, Element* element)
	{
		if (hthandle->N != 0)
		{
			for (int i = 0, j = generateHash(element, hthandle->Capacity, 0);
				getElementByHT(hthandle, j) != NULL && i != hthandle->Capacity;
				j = nextHash(j, hthandle->Capacity, ++i))
			{
				Element* elFromHT = getElementByHT(hthandle, j);
				if (!delatedElement(elFromHT))
				{
					if (equalKeys(elFromHT, element))
					{
						setFlagDelation(getElementByHT(hthandle, j));
						hthandle->N--;
						ReleaseMutex(hthandle->Mutex);
						return TRUE;
					}
				}
			}
		}
		SetErrorMessage(hthandle, "Not found key\n", 15);
		ReleaseMutex(hthandle->Mutex);
		return FALSE;
	}

	BOOL Update(HTHANDLE* hthandle, Element* oldelement, void* newpayload, int newpayloadlength)
	{
		int indexInHT = -1;
		if (hthandle->N != 0)
			for (int i = 0, j = generateHash(oldelement, hthandle->Capacity, 0);
				getElementByHT(hthandle, j) != NULL && i != hthandle->Capacity;
				j = nextHash(j, hthandle->Capacity, ++i)) {
			Element* elFromHT = getElementByHT(hthandle, j);

			if (!delatedElement(elFromHT))
			{
				if (equalKeys(elFromHT, oldelement))
				{
					UpdateElement(hthandle, getElementByHT(hthandle, j), newpayload, newpayloadlength);
					ReleaseMutex(hthandle->Mutex);
					return TRUE;
				}
			}
		}

		SetErrorMessage(hthandle, "Not found key\n", 15);
		ReleaseMutex(hthandle->Mutex);
		return FALSE;
	}

	char* lastError(HTHANDLE* ht) {
		return ht->LastErrorMessage;
	}

	void print(const Element* element) {
		char* key = (char*)element->key;
		for (int i = 0; i < element->keylength; i++) {
			cout << key[i] << " ";
		}

		char* payload = (char*)element->payload;
		for (int i = 0; i < element->payloadlength; i++) {
			cout << payload[i];
		}
		cout << endl;
	}
}