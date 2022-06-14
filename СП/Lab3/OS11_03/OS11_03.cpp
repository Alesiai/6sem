#include <iostream>
#include "../OS11_HTAPI/HT.h"
#include <wchar.h>
#include <string>
#include <sstream>
#pragma comment(lib, "D:\\6 סול\\ֿׁ\\Lab3\\x64\\Debug\\OS11_HTAPI.lib")

using namespace std;
using namespace HT;

void errorPrintString(char* str) {
	cout << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		cout << str[i];
		i++;
	}
	cout << endl;
}

void successDeletion() {
	cout << "\nDELETE SUCCESS\n";
}

int main(int argc, char* argv[])
{
	std::wstring filePath(L"D:\\test.ht");
	try {
		HTHANDLE* HT = OpenExist(filePath.c_str());
		if (HT == NULL)	throw "Invalid handle";

		while (true) {
			srand(time(0));
			stringstream convert;
			convert << (rand() % 50);
			string key = convert.str();

			Element* el2 = Get(HT, new Element(key.c_str(), key.length() + 1, "0", 2));
			el2 == NULL ? errorPrintString(GetLastErrorProg(HT)) : print(el2);

			el2 != NULL && Delete(HT, el2) ? successDeletion() : errorPrintString(GetLastErrorProg(HT));

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
