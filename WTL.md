### Here i will show how to install WTL properly and avoid possible errors, that i already encountered using Visual Studio 2022.

### Step 1. WTL download:
- https://sourceforge.net/projects/wtl/
  After you download WTL zip file there will be ReadMe.html file that explains how to install WTL

### Step 2. Installation issues:
- https://learn.microsoft.com/en-us/answers/questions/1321701/unable-to-install-wtl-10-with-visual-studio-2022
- https://sourceforge.net/p/wtl/discussion/374433/thread/f00ccfa770/
 In short: Setup.js doesn't know about Visual Studio 2022. You have to manually add info about it. Link above shows how to do it.

### Step 3. Add WTL include files to project:
As ReadMe.html says:  "Please be sure to add the WTL\include directory to the list of include directories in VC++, so that the compiler can find them when you include them in your projects."
- Project -> Properties -> C/C++ -> General -> Additional Include Directories: WTL\include;
  In my case the location is C:\Dev\WTL\include;

### Step 4. Fix nuget packages errors:
I had build errors when tried to run ready book samples (https://github.com/zodiacon/Win10SysProgBookSamples) that use WTL.  
The error looked like this: "The missing file is ..\..\packages\wtl.10.0.9163\build\native\wtl.targets."  

  Solution to problem:  
  1. Update nuget packages: Tools -> NuGet Package Manager -> Manage NuGet Packages for Solution.
     WTL packages and possibly Microsoft.Windows.ImplementationLibrary
  3. Right click on Project --> 'Unload Project'
  4. Right click on Project --> 'Edit Project File' (.vcxproj)
     - Find "<Import Project="..\packages\wtl.10.0.9163\build\native\wtl.targets" and  "" <Error Condition="!Exists('..\packages\wtl.10.0.9163\build\native\wtl.targets"  and delete or substitute with new packages versions: ..\packages\wtl.10.0.9163..  --> ..\packages\wtl.10.0.10320..
 5. Save this file, Right click on Project --> Reload Project and then Rebuild
 6. Inside solution folder in folder packages delete old wtl packages
