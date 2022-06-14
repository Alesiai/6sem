#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <process.h>
#include <Tlhelp32.h>
#include "../OS13_COMlib/HTlib.h"
#pragma comment(lib, "D:\\lab13\\Release\\OS13_COM.lib")

const wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	size_t outSize;
	mbstowcs_s(&outSize, wc, cSize, c, cSize - 1);
	return wc;
}

void killProcessByName(const wchar_t* filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);

    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (wcscmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

int main(int argc, char** argv)
{
	try
	{
        killProcessByName(L"OS13_START.exe");
        killProcessByName(L"OS_0402.exe");
        killProcessByName(L"OS_0403.exe");
        killProcessByName(L"OS_0404.exe");
	}
	catch (const char* error) { std::cout << "-- Error: " << error << std::endl; }
}
