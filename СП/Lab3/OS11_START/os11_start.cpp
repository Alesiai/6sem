#include <iostream>
#include "../OS11_HTAPI/HT.h"
#include <wchar.h>
#pragma comment(lib, "D:\\6 סול\\ֿׁ\\Lab3\\x64\\Debug\\OS11_HTAPI.lib")
using namespace std;
using namespace HT;

int main(int argc, char* argv[])
{
	wstring filePath(L"D:\\test.ht");
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
