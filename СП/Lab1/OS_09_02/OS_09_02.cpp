#include <iostream>
#include <Windows.h>
using namespace std;

   _BY_HANDLE_FILE_INFORMATION fileInformation;
   DWORD readOrWriteSymols;
   char buf[1024];

   bool printFileTxt(LPWSTR filename)
   {
        HANDLE fileHandle = CreateFile(filename, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == INVALID_HANDLE_VALUE) {
            cout << GetLastError() << "\n";
            return false;
        }
        readOrWriteSymols = NULL;
        ZeroMemory(buf, sizeof(buf));

        ReadFile(fileHandle, &buf, 350, &readOrWriteSymols, NULL);

        cout << "\n" << buf << "\n";
        CloseHandle(fileHandle);
   }


   bool delRowFileTxt(LPWSTR filename, DWORD row)
    {
       char* reBuf = buf;
       ZeroMemory(buf, sizeof(buf));
       DWORD nPosition = 0;
       readOrWriteSymols = NULL;

       cout << "Try to delate string number:" << row + 1 << "\n";
        
        HANDLE fileHandle = CreateFile(filename, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        GetFileInformationByHandle(fileHandle, &fileInformation);

        if (ReadFile(fileHandle, buf, fileInformation.nFileSizeLow + 1, &readOrWriteSymols, NULL))
        {
            DWORD numOfStrings = 0;

            for (DWORD i = 0; i < sizeof(buf); i++)
            {
                if (buf[i] == '\n')
                    numOfStrings++;
            }

            if (numOfStrings < row) {
                CloseHandle(fileHandle);
                return false;
            }

            for (DWORD j = 0; nPosition < sizeof(buf); nPosition++) {
                if (j == row)
                    break;

                if (buf[nPosition] == '\n')
                    j++;
            }
            
            LARGE_INTEGER newPointer;
            newPointer.QuadPart = nPosition;

            SetFilePointerEx(fileHandle, newPointer, NULL, FILE_BEGIN);
            SetEndOfFile(fileHandle);
            DWORD endStr = nPosition;
            
            for (DWORD j = nPosition; endStr < sizeof(buf); endStr++)
            {
                if (buf[endStr] != '\n')
                    j++;
                else
                    break;
            }
            endStr++;
            char* end = new char[fileInformation.nFileSizeLow - endStr];

            int check = 0;
            int checkEnd = 0;

            while (*reBuf++) {
                if (check < endStr){
                    check++;
                }
                else
                {
                    end[checkEnd] = buf[check];
                    checkEnd++;
                    check++;
                }
            }

            readOrWriteSymols = NULL;

            WriteFile(fileHandle, end, checkEnd, &readOrWriteSymols, NULL);
            CloseHandle(fileHandle);

            cout << "Result:";
            printFileTxt(filename);
            return true;
        }
    }

int main()
{
    auto filename = (LPWSTR)L"..\\Files\\OS09_01.txt";

    cout << "Read file:\n";
    printFileTxt(filename);

    if (!delRowFileTxt(filename, 0))
        cout << "\nCan't delate string: 1\n";
    else {
        if (!delRowFileTxt(filename, 2))
            cout << "\nCan't delate string: 3\n";
        else {

            if (!delRowFileTxt(filename, 7))
                cout << "\nCan't delate string: 8\n";

            else {
                if (!delRowFileTxt(filename, 9))
                    cout << "\nCan't delate string: 10\n";
            }
        }
    }

    getchar();
}
