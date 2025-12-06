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


### Before Build:
To make following 2 functions work these 2 steps must be done.
### NOTE 1: for 'GetVersionExW' function
Make sure to add manifest.xml file for getting modern OS versions above 6th.
#### Project -> Properties -> Manifest Tool -> Input And Output -> Additional Manifest Files: manifest.xml
Also '#define BUILD_WINDOWS' is already included in source code.

### NOTE 2: for 'GetComputerObjectNameW' function 
1) add Secur32.lib to Additional Dependencies:
#### Project -> Properties -> Linker --> Input --> Additional Dependencies: Secur32.lib
2) <security.h> and '#define SECURITY_WIN32' are also included in source code.

### NOTE 3: for 'GetUserNameW' function 
1) add Advapi32.lib to Additional Dependencies:
#### Project -> Properties -> Linker --> Input --> Additional Dependencies: Advapi32.lib
