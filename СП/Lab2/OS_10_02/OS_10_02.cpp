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

		HTHANDLE* HT = Create(10, 2, 10, 10, L"OS_10.ht");

		cout << "INSERT CHECK\n";
		for (int i = 0; i < _countof(listOfElement); i++) {
			if (!Insert(HT, listOfElement[i])) {
				printStr(lastError(HT));
			}
			if ((el = Get(HT, listOfElement[i])) == NULL)
				printStr(lastError(HT));
			else
				print(el);
		}
		cout << "________________________________________________________\n";


		cout << "\nUPDATE CHECK\n";
		for (int i = 0; i < _countof(listOfElement); i++) {
			if (i == 0) {
				if (!Update(HT, listOfElement[0], listOfElement[2]->payload, listOfElement[2]->payloadlength)) {
					printStr(lastError(HT));
				}
			}
			if ((el = Get(HT, listOfElement[i])) == NULL)
				printStr(lastError(HT));
			else
				print(el);
		}
		cout << "________________________________________________________\n";

		cout << "\nSNAPSHOT CHECK\n";
		Sleep(4000);
		cout << "\n________________________________________________________\n";

		cout << "\nDELETE CHECK\n\n";

		for (int i = 0; i < _countof(listOfElement); i++) {
			Delete(HT, listOfElement[i]);
			if ((el = Get(HT, listOfElement[i])) == NULL)
				printStr(lastError(HT));
			else
				print(el);
		}
		cout << "________________________________________________________\n";

		if (Close(HT)) cout << "\nClose storage";
	}
	catch (const char* mess) {
		cout << mess << endl;
	}

	return 0;
}