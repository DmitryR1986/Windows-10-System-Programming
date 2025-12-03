# Exercise 1  from "Windows 10 System Programming" (by Pavel Yosifovich), Chapter 1:

## TASK:
Write a console application that prints system information by calling the following APIs:
- 'GetNativeSystemInfo'
- 'GetComputerName'
- 'GetWindowsDirectory'
- 'QueryPerformanceCounter'
- 'GetProductInfo'
- 'GetVersionExW'
- 'GetComputerObjectNameW'


## BUILD:

### NOTE 1: GetVersionExW function
Make sure to create manifest.xml file for getting modern OS versions above 6th.
Project -> Properties -> Manifest Tool -> Input And Output -> Additional Manifest Files: manifest.xml
#define BUILD_WINDOWS in source code is to get correct windows version when using GetVersionExW()

### NOTE 2: GetComputerObjectNameW function 
1) include <security.h> header file and
2) add Secur32.lib to Additional Dependencies:
Project -> Properties -> Linker --> Input --> Additional Dependencies: Secur32.lib
3) add #define SECURITY_WIN32 in source code
