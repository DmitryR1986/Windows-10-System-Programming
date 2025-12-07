## Here i will show how to install WTL properly and avoid possible errors, that i already encountered using Visual Studio 2022.
### Step 1. WTL download:
- https://sourceforge.net/projects/wtl/
After you download WTL zip file there will be ReadMe.html file that explains how to install WTL

### Step 2. Installation issues:
- https://learn.microsoft.com/en-us/answers/questions/1321701/unable-to-install-wtl-10-with-visual-studio-2022
- https://sourceforge.net/p/wtl/discussion/374433/thread/f00ccfa770/
  In short Setup.js doesn't know about Visual Studio 2022. You have to manually add info about it. Link above shows how to do it.

### Step 3. Add WTL include files to project:
As ReadMe.html says:  "Please be sure to add the WTL\include directory to the list of include directories in VC++, so that the compiler can find them when you include them in your projects."
- Project -> Properties -> C/C++ -> Additional Include Directories: WTL\include
In my case the location is C:\Dev\WTL\include;
