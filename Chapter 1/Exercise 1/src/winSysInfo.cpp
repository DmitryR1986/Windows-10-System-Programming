/*	
	Exercise 1  from "Windows 10 System Programming" (by Pavel Yosifovich), Chapter 1

	Implements a console application that displays system information using various Windows API functions.

	Author: Dmitry Reshetnikov
	December 2025
*/

#define SECURITY_WIN32  //for GetComputerObjectNameW function 
#define BUILD_WINDOWS   //to get correct windows version when using GetVersionExW()
#include <Windows.h>
#include <security.h>   //for GetComputerObjectNameW function 
#include <stdio.h>
#include <iostream>

void ErrorCodeAndMeaning(DWORD* lastError) {
	PWSTR errorMeaning;
	DWORD chars = ::FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, *lastError, 0, (PWSTR)&errorMeaning, 0, nullptr);
	if (chars > 0) {
		printf("Error %lu: %ws\n", *lastError, errorMeaning);
		::LocalFree(errorMeaning);
	}
}

PCWSTR GetWindowsVersion(DWORD* productType)
{
	switch (*productType) {
	case PRODUCT_HOME_BASIC:
		return L"Windows Home";
		break;
	case PRODUCT_PROFESSIONAL:
		return L"Windows Professional";
		break;
	case PRODUCT_ENTERPRISE:
		return L"Windows Enterprise";
		break;
	case PRODUCT_EDUCATION:
		return L"Windows Education";
		break;
	default:
		return L"Unknown product type";
		break;
	}
}


int main(int argc, const char* argv[]) {

	DWORD lastError;

	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);

	printf("Processor Type: %lu\n", si.dwProcessorType);
	printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
	printf("Page size: %d Bytes\n", si.dwPageSize);
	//printf("Processor Mask: 0x%p\n", (PVOID)si.dwActiveProcessorMask);
#ifdef _WIN64
	printf("Processor Mask x64: 0x%016llX\n", si.dwActiveProcessorMask);
#else
	printf("Processor Mask x32: 0x%08X\n", si.dwActiveProcessorMask);
#endif
	printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
	printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);


	LARGE_INTEGER performanceCount;
	if (!::QueryPerformanceCounter(&performanceCount)) {
		lastError = ::GetLastError();
		ErrorCodeAndMeaning(&lastError);
	}
	else {
		printf("Performance Counter value: %llu\n", performanceCount.QuadPart);
	}


	WCHAR infoBuf[MAX_PATH];
	DWORD size = MAX_PATH;

	if (!::GetComputerName(infoBuf, &size)) {
		lastError = ::GetLastError();
		ErrorCodeAndMeaning(&lastError);
	}
	else {
		printf("Computer Name: %ws\n", infoBuf);
	}

	if (::GetUserNameW(infoBuf, &size))
		wprintf(L"User Account Name: %ws\n", infoBuf);
	else {
		lastError = ::GetLastError();
		ErrorCodeAndMeaning(&lastError);
	}
	

	if (!::GetWindowsDirectory(infoBuf, MAX_PATH)) {
		lastError = ::GetLastError();
		ErrorCodeAndMeaning(&lastError);
	}
	else {
		printf("Windows Directory: %ws\n", infoBuf);
	}

	OSVERSIONINFOW vi = { sizeof(vi) };
	::GetVersionEx(&vi);
	DWORD productType;
	if (::GetProductInfo(vi.dwMajorVersion, vi.dwMinorVersion, 0, 0, &productType)) {
		wprintf(L"%ws, ", GetWindowsVersion(&productType));
		printf("version: %lu.%lu.%lu\n", vi.dwMajorVersion, vi.dwMinorVersion, vi.dwBuildNumber);
	}

	//==========  GetComputerObjectName ==========
	ULONG size2 = 0;
	PWSTR pComputerName;
	//1. using nullptr instead of buffer (2nd parameter) gives us right size of NameDisplay according to Microsoft specification
	::GetComputerObjectName(NameDisplay, nullptr, &size2);
	pComputerName = new WCHAR[size2]; //allocate memory of right size for NameDisplay
	if (!pComputerName) {
		wprintf(L"Memory allocation failed\n");
		exit(0);
	}
	//2. finally save NameDisplay in allocated buffer
	if (::GetComputerObjectName(NameDisplay, pComputerName, &size2)) {
		wprintf(L"NameDisplay: %ws\n", pComputerName);
	}
	else {
		wprintf(L"NameDisplay -- ");
		lastError = ::GetLastError();
		ErrorCodeAndMeaning(&lastError);
	}
	delete[] pComputerName;


	return 0;
}
