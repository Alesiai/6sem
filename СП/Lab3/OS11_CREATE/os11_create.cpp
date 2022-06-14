#include "../OS11_HTAPI/HT.h"
#include <iostream>
#pragma comment (lib, "D:\\6 סול\\ֿׁ\\Lab3\\Debug\\OS11_HTAPI.lib")
#include <wchar.h>
#include <string>
using namespace HT;
using namespace std;

int main(int argc, char* argv[])
{
	int capacity = 2000;
	int snapshotIntervalSec = 3;
	int maxKeyLength = 4;
	int maxDataLength = 4;
	wstring filePath(L"D:\\test.ht");
	
	try {
		HTHANDLE* HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxDataLength, filePath.c_str());
		HT? printFileInfo("Created", filePath, snapshotIntervalSec, capacity, maxKeyLength, maxDataLength): throw "Cant create ht file, maybe it was created earlyer";
		
		Close(HT);
	}
	catch (const char* err) {
		cerr << err << "\n";
		return 1;
	}
	return 0;
}