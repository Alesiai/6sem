#include <iostream>
#include "../OS11_HTAPI/HT.h"
#include <wchar.h>
#pragma comment(lib, "D:\\6 сем\\СП\\Lab3\\x64\\Debug\\OS11_HTAPI.lib")
#pragma warning(disable : 4996)
using namespace std;
using namespace HT;

wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int main(int argc, char* argv[])
{
	wstring filePath(L"D:\\test.ht");

	if (argv[1]) {
		wchar_t* fileName = GetWC(argv[1]);
		filePath = (L"D:\\") + wstring(fileName);
	}

	try {
		HTHANDLE* HT = Open(filePath.c_str());
		HT ? printFileInfo("Opened ", filePath, HT->SecSnapshotInterval, HT->Capacity, HT->MaxKeyLength, HT->MaxPayloadLength) : throw "Invalid handle";

		getchar();
		Close(HT);
	}
	catch (const char* err) {
		cerr << err << "\n";
		return 1;
	}
	return 0;
}
