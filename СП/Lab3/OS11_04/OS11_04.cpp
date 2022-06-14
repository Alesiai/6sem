#include <iostream>
#include "../OS11_HTAPI/HT.h"
#include <wchar.h>
#include <string>
#include <sstream>
#include <ctime>

#pragma comment(lib, "D:\\6 сем\\СП\\Lab3\\x64\\Debug\\OS11_HTAPI.lib")

using namespace HT;
using namespace std;

void errorPrintString(char* str) {
	cerr << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		cerr << str[i];
		i++;
	}
	cerr << endl;
}

string generateNewPayload(Element* el) {

	string payload;
	stringstream oladPayloadConvert, newPayloadConvert;
	int num;

	oladPayloadConvert << *(char*)el->payload;
	oladPayloadConvert >> num;

	int newNum = num + 1;

	newPayloadConvert << newNum;
	cout << "\nold payload: " << *(char*)el->payload << "\nnew payload: " << newPayloadConvert.str() << "\n";

	return newPayloadConvert.str();
}

void checkingUpdate(HTHANDLE* HT, Element* el) {
	cout << "UPDATE SUCCESS" << endl;
	if (Get(HT, el) == NULL) errorPrintString(GetLastErrorProg(HT));
}

int main(int argc, char* argv[])
{
	wstring filePath(L"D:\\test.ht");
	try {
		HTHANDLE* HT = OpenExist(filePath.c_str());
		if (HT == NULL) throw "Invalid handle";

		while (true) {
			srand(time(0));
			stringstream convert;
			convert << (rand() % 50);
			string key = convert.str();

			Element* el;
			Element* el1 = new Element(key.c_str(), key.length() + 1);

			cout << "\nTry to get element for updte.....\n";

			if ((el = Get(HT, el1)) != NULL) {
				print(el);
				string payload = generateNewPayload(el);

				Element* newElement = new Element(key.c_str(), key.length() + 1, payload.c_str(), payload.length() + 1);
				Update(HT, el1, newElement->payload, newElement->payloadlength) ? checkingUpdate(HT, el1) : errorPrintString(GetLastErrorProg(HT));
			}
			else {
				errorPrintString(GetLastErrorProg(HT));
			}
			Sleep(1000);
		}

		getchar();
		CloseExist(HT);
	}
	catch (const char* err) {
		cerr << err << endl;
		return 1;
	}
	return 0;
}
