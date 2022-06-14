#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
using namespace std;

_BY_HANDLE_FILE_INFORMATION fileInformation;

bool printFileTxt(LPWSTR fileName) {
	cout << "\n_______________________________________________________________\nTask 2" << endl;

	HANDLE fileHandle = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	try {
		DWORD n = NULL;
		char buf[1024];

		ZeroMemory(buf, sizeof(buf));
		bool readFile = ReadFile(fileHandle, &buf, 1023, &n, NULL);

		wcout << "Read strings from file:\n" << buf << endl;
	}
	catch (exception) {
		return false;
	};
}

string GetTypeOfFile(HANDLE fileHandle) {

	DWORD fileType = GetFileType(fileHandle);
	switch (fileType) {
	case FILE_TYPE_CHAR: return "CHAR"; break;
	case FILE_TYPE_DISK: return "DISK"; break;
	case FILE_TYPE_PIPE: return "PIPE"; break;
	case FILE_TYPE_REMOTE: return  "REMOTE"; break;
	default: return  "UNKNOWN"; break;
	}
}

bool WriteTime(SYSTEMTIME time) {
	cout << "\t\tYear:" << time.wYear
		<< "\n\t\tMonth:" << time.wMonth
		<< "\n\t\tDay:" << time.wDay
		<< "\n\t\tTime:" << time.wHour << ":" << time.wMinute
		<< endl;

	return true;
}

bool printFileInfo(LPWSTR fileName) {
	cout << "\n_______________________________________________________________\nTask 1" << endl;

	HANDLE fileHandle = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	cout << "File name:" << fileName;
	cout << "\nFile type:" << GetTypeOfFile(fileHandle);

	LARGE_INTEGER lFileSize;


	if (GetFileSizeEx(fileHandle, &lFileSize))
		cout << "\nFile size:" << lFileSize.QuadPart << " bytes\n";

	GetFileInformationByHandle(fileHandle, &fileInformation);

	FILETIME createFile = fileInformation.ftCreationTime,
		lastUpdate = fileInformation.ftLastWriteTime;
	SYSTEMTIME createFileToSystemTime, lastUpdateToSysTime;

	FileTimeToSystemTime(&createFile, &createFileToSystemTime);
	cout << "WHEN CREATED:\n";
	WriteTime(createFileToSystemTime);

	FileTimeToSystemTime(&lastUpdate, &lastUpdateToSysTime);
	cout << "WHEN UPDATED:\n";
	WriteTime(lastUpdateToSysTime);
	
	return true;
}

int main() {
	auto fileName = (LPWSTR)L"..\\Files\\OS09_01.txt";
	HANDLE fileHandle = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		cerr << "File dont'n fount, check it";
		return -1;
	}

	printFileInfo(fileName);
	printFileTxt(fileName);
	CloseHandle(fileHandle);

	getchar();

	return 0;
}