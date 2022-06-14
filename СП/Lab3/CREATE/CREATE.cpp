#include "../OS11_HTAPI/HT.h"
#include <iostream>
#include <wchar.h>
#include <string>
#pragma comment (lib, "D:\\6 сем\\СП\\Lab3\\Debug\\OS11_HTAPI.lib")
#pragma warning(disable : 4996)

using namespace HT;
using namespace std;

wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int main(int argc, char* argv[])
{
	int capacity = 2000;
	int snapshotIntervalSec = 3;
	int maxKeyLength = 4;
	int maxDataLength = 4;
	wstring filePath(L"D:\\test.ht");
	
	if (argv[1] && argv[2] && argv[3] && argv[4] && argv[5]) {		
		wchar_t* fileName = GetWC(argv[1]);
		filePath = (L"D:\\") + wstring(fileName);
		
		capacity = stoi(argv[2]);
		snapshotIntervalSec = stoi(argv[3]);
		maxKeyLength = stoi(argv[4]);
		maxDataLength = stoi(argv[5]);
	}

	try {
		HTHANDLE* HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxDataLength, filePath.c_str());
		HT ? printFileInfo("Created", filePath, snapshotIntervalSec, capacity, maxKeyLength, maxDataLength) : throw "Cant create ht file, maybe it was created earlyer";

		Close(HT);
	}
	catch (const char* err) {
		cerr << err << "\n";
		return 1;
	}
	return 0;
}