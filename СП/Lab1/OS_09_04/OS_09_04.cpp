#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

auto FileName = (LPWSTR)L"..\\Files\\OS09_01.txt";

int getStringsCount() {
	char rbuf[10240];
	Sleep(1000);
	HANDLE hf = CreateFile(FileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD n = NULL;

	ZeroMemory(rbuf, sizeof(rbuf));
	BOOL b = ReadFile(hf, &rbuf, sizeof(rbuf), &n, NULL);

	int i = 0;
	int strCount = 0;
	while (rbuf[i] != '\0') {
		if (rbuf[i] == '\n')
			strCount++;
		i++;
	}

	CloseHandle(hf);
	return strCount + 1;
}

void task(LPCWSTR FileName) {

	wstring wFilePath = wstring(FileName);
	string file = string(wFilePath.begin(), wFilePath.end());

	string dir = string(wFilePath.begin(), wFilePath.end());

	for (int i = dir.length() - 1; i >= 0; i--) {
		if (dir[i] != '\\')
			dir.pop_back();
		else {
			break;
		}
	}
	
	//Начинаем отслеживать изменения в заданной папке посредством специальной функции
	HANDLE hNotification = FindFirstChangeNotificationA(dir.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE); 
	if (hNotification == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"Wrong path", L"Error", MB_OK);
	}

	int fileStrsCount = getStringsCount();

	while (true)
	{
		FindNextChangeNotification(hNotification); // ожидание следующего изменения в папке
		
		DWORD dwResult = WaitForSingleObject(hNotification, INFINITE);
		int newfileStrsCount = getStringsCount();
		if (fileStrsCount != newfileStrsCount) {
			cout << "\nIt was changed to:  " << newfileStrsCount << "\n";
			fileStrsCount = newfileStrsCount;
		}
	}
	FindCloseChangeNotification(hNotification);
}

BOOL printWatchRowFileTxt(DWORD mlsec)
{
	cout <<"Count of strings in the beginning: " << getStringsCount();
	
	HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)task, (LPVOID)FileName, NULL, FALSE);
	WaitForSingleObject(thread2, mlsec);
	TerminateThread(thread2, -1);

	return true;
}

void main()
{
	printWatchRowFileTxt(40000);
}
