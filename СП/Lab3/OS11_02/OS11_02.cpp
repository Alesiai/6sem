#include "../OS11_HTAPI/HT.h"
#include <iostream>
#include <string>
#include <sstream>
#include <wchar.h>
#include <ctime>
#pragma comment(lib, "D:\\6 סול\\ֿׁ\\Lab3\\x64\\Debug\\OS11_HTAPI.lib")

using namespace std;
using namespace HT;

void errorPrintString(char* str) {
	cerr << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		cerr << str[i];
		i++;
	}
	cerr << endl;
}

void tryGetElement(Element* el, HTHANDLE* HT) {
	cout << "\nGET" << endl;
	Element* el1 = Get(HT, el);
	el1 == NULL ? errorPrintString(GetLastErrorProg(HT)) : print(el);
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

			cout << "\nINSERT......" << endl;
			Element* el = new Element(key.c_str(), 3, "0", 2);
			!Insert(HT, el) ? errorPrintString(GetLastErrorProg(HT)) : tryGetElement(el, HT);
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
