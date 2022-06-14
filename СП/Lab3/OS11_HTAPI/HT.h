// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef OS11_HTAPI_EXPORTS
#define OS11_HTAPI_API __declspec(dllexport)
#else
#define OS11_HTAPI_API __declspec(dllimport)
#endif

#include <Windows.h>
#include<iomanip>
#include<iostream>


#define CREATE_HTFILE_ERROR "Create HTFile error";
#define CREATE_FILEMAPPING_ERROR "Create FileMapping error";
#define MAPPING_VIEW_ERROR "Mapping view failed";


namespace HT {
	extern "C" OS11_HTAPI_API struct HTHANDLE
	{
		OS11_HTAPI_API HTHANDLE();
		OS11_HTAPI_API HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int     Capacity;               // ������� ��������� � ���������� ��������� 
		int     SecSnapshotInterval;    // ������������� ���������� � ���. 
		int     MaxKeyLength;           // ������������ ����� �����
		int     MaxPayloadLength;       // ������������ ����� ������
		char    FileName[512];          // ��� ����� 
		HANDLE  File;                   // File HANDLE != 0, ���� ���� ������
		HANDLE  FileMapping;            // Mapping File HANDLE != 0, ���� mapping ������  
		LPVOID  Addr;                   // Addr != NULL, ���� mapview ��������  
		char    LastErrorMessage[512];  // ��������� �� ��������� ������ ��� 0x00  
		time_t  lastsnaptime;           // ���� ���������� snap'a (time())  

		HANDLE Mutex;
		int N;//������� ����������
		HANDLE SnapshotThread;
	};

	extern "C" OS11_HTAPI_API struct Element   // ������� 
	{
		OS11_HTAPI_API Element();
		OS11_HTAPI_API Element(const void* key, int keylength);                                             // for Get
		OS11_HTAPI_API Element(const void* key, int keylength, const void* payload, int  payloadlength);    // for Insert
		OS11_HTAPI_API Element(Element* oldelement, const void* newpayload, int  newpayloadlength);         // for update
		void* key;                 // �������� ����� 
		int             keylength;           // ������ �����
		void* payload;             // ������ 
		int             payloadlength;       // ������ ������
	};

	extern "C" OS11_HTAPI_API HTHANDLE * Create(int	  Capacity, int   SecSnapshotInterval, int   MaxKeyLength, int   MaxPayloadLength, const wchar_t  FileName[512]);

	extern "C" OS11_HTAPI_API HTHANDLE * Open(const wchar_t    FileName[512]);

	extern "C" OS11_HTAPI_API HTHANDLE * OpenExist(const wchar_t    FileName[512]);

	extern "C" OS11_HTAPI_API BOOL Snap(HTHANDLE * hthandle);

	extern "C" OS11_HTAPI_API BOOL Close(const HTHANDLE * hthandle);

	extern "C" OS11_HTAPI_API BOOL CloseExist(const HTHANDLE * hthandle);

	extern "C" OS11_HTAPI_API BOOL Insert(HTHANDLE * hthandle, Element * element);

	extern "C" OS11_HTAPI_API BOOL Delete(HTHANDLE * hthandle, Element * element);

	extern "C" OS11_HTAPI_API Element * Get(HTHANDLE * hthandle, Element * element);

	extern "C" OS11_HTAPI_API BOOL Update(HTHANDLE * hthandle, Element * oldelement, void* newpayload, int newpayloadlength);

	extern "C" OS11_HTAPI_API char* GetLastErrorProg(HTHANDLE * ht);

	extern "C" OS11_HTAPI_API void print(const Element * element);

	extern "C" OS11_HTAPI_API void printFileInfo(
		std::string action, 
		std::wstring filePath, 
		int snapshotIntervalSec, 
		int capacity, 
		int maxKeyLength, 
		int maxDataLength
	);
}