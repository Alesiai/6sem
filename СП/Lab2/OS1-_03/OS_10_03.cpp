#include <iostream>
#include "../StaticLib1/HT.h"
using namespace std;
using namespace HT;

void printStr(char* str) {
	cout << "ERROR:\t" << str << endl;
}

int main()
{
	try {
		Element* el;
		Element* listOfElement[] = { new Element("1", 1, "first", 5),
			new Element("2", 1, "second", 6),
			new Element("3", 1, "third", 5) };

		HTHANDLE* HTFirst = Create(10, 2, 10, 10, L"first.ht");
		HTHANDLE* HTSecond = Create(10, 2, 10, 10, L"second.ht");

		cout << "INSERT CHECK\n";
		for (int i = 0; i < _countof(listOfElement); i++) {
			if (!Insert(HTFirst, listOfElement[i])) {
				printStr(lastError(HTFirst));
			}
			if (!Insert(HTSecond, listOfElement[i])) {
				printStr(lastError(HTSecond));
			}
			if ((el = Get(HTFirst, listOfElement[i])) == NULL)
				printStr(lastError(HTFirst));
			else
				print(el);
			if ((el = Get(HTSecond, listOfElement[i])) == NULL)
				printStr(lastError(HTSecond));
			else
				print(el);
		}
		cout << "________________________________________________________\n";


		cout << "\nUPDATE CHECK\n";
		for (int i = 0; i < _countof(listOfElement); i++) {
			if (i == 0) {
				if (!Update(HTFirst, listOfElement[0], listOfElement[2]->payload, listOfElement[2]->payloadlength)) {
					printStr(lastError(HTFirst));
				}
				if (!Update(HTSecond, listOfElement[1], listOfElement[2]->payload, listOfElement[2]->payloadlength)) {
					printStr(lastError(HTSecond));
				}
			}
			if ((el = Get(HTFirst, listOfElement[i])) == NULL)
				printStr(lastError(HTFirst));
			else
				print(el);
			if ((el = Get(HTSecond, listOfElement[i])) == NULL)
				printStr(lastError(HTSecond));
			else
				print(el);
		}
		cout << "________________________________________________________\n";

		cout << "\nSNAPSHOT CHECK\n";
		Sleep(4000);
		cout << "\n________________________________________________________\n";

		cout << "\nDELETE CHECK\n\n";

		for (int i = 0; i < _countof(listOfElement); i++) {
			Delete(HTFirst, listOfElement[i]);
			if ((el = Get(HTFirst, listOfElement[i])) == NULL)
				printStr(lastError(HTFirst));
			else
				print(el);
			Delete(HTSecond, listOfElement[i]);
			if ((el = Get(HTSecond, listOfElement[i])) == NULL)
				printStr(lastError(HTSecond));
			else
				print(el);
		}
		cout << "________________________________________________________\n";

		if (Close(HTFirst)) cout << "\nClose storage";
		if (Close(HTSecond)) cout << "\nClose storage";
	}
	catch (const char* mess) {
		cout << mess << endl;
	}

	return 0;
}