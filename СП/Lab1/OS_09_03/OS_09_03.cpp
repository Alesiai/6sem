#include <iostream>
#include <Windows.h>
using namespace std;

bool insRowFileTxt(LPWSTR file, LPWSTR inputString, DWORD row) {
	HANDLE fileHandle = CreateFile(file, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    _BY_HANDLE_FILE_INFORMATION fileInformation;

    char buf[1024];
    char* reBuf = buf;
    DWORD readedBytes = NULL;

	if (fileHandle == INVALID_HANDLE_VALUE) return false;
    if (!GetFileInformationByHandle(fileHandle, &fileInformation)) return false;

    ZeroMemory(buf, sizeof(buf));
    
    if (!ReadFile(fileHandle, buf, fileInformation.nFileSizeLow + 1, &readedBytes, NULL))
        return false;

    LARGE_INTEGER newPointer;
    DWORD positionMode;
    
    wstring wStr = wstring(inputString);
    string writeString = string(wStr.begin(), wStr.end());

    DWORD writenSymbols = 0;

    if (row == -1) {
        writeString = "\n" + writeString;
        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);
    }
    else if (row == 0) {
        newPointer.QuadPart = 0;
        positionMode = FILE_BEGIN;
        writeString += "\n";

        SetFilePointerEx(fileHandle, newPointer, NULL, positionMode);

        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);

        WriteFile(fileHandle, reBuf, readedBytes, &writenSymbols, NULL);
    }
    else {
        DWORD nPosition = 0;
        for (DWORD j = 0; nPosition < sizeof(buf); nPosition++) {
            if (j == row - 1)  break;
            if (buf[nPosition] == '\n') j++;
        }

        writeString += "\n";
        newPointer.QuadPart = nPosition;
        positionMode = FILE_BEGIN;

        SetFilePointerEx(fileHandle, newPointer, NULL, positionMode);

        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);

        char* end = new char[fileInformation.nFileSizeLow - nPosition];

        int check = 0;
        int checkEnd = 0;
        while (*reBuf++) {
            if (check < nPosition)
                check++;
            else
            {
                end[checkEnd] = buf[check];
                checkEnd++;
                check++;
            }
        }
        writenSymbols = 0;

        WriteFile(fileHandle, end, checkEnd, &writenSymbols, NULL);
    }

	CloseHandle(fileHandle);
	return true;
}

bool printFileTxt(LPWSTR file) {
	HANDLE fileHandle = CreateFile(file, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
		return false;

	DWORD n = NULL;
	char buf[1024];

	ZeroMemory(buf, sizeof(buf));
	bool readFile = ReadFile(fileHandle, &buf, 350, &n, NULL);

	cout << buf;
	CloseHandle(fileHandle);
}

int main() {
    auto file = (LPWSTR)L"..\\Files\\OS09_01.txt",
        inputString = (LPWSTR)L"STRING";
    
    cout << "\n__________________________Befoe__________________________\n"; 
    printFileTxt(file);

    insRowFileTxt(file, inputString, 0);
    insRowFileTxt(file, inputString, -1);
    insRowFileTxt(file, inputString, 5);
    insRowFileTxt(file, inputString, 7);

    cout << "\n__________________________AFTER__________________________\n";
    if (!printFileTxt(file))
        cout << "Error";
    
    getchar();
    return 0;
}
