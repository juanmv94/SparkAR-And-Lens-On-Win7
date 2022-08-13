# SparkAR Studio and Lens Studio on Windows 7

The most actual AR tools for PC are only available for Windows 10. But what can I do if I want to keep using Windows 7/8?

## Lens Studio

You will be able to install Lens Studio on Windows 7, but once installed, when you try to open it, it will fail and won't boot due to system DLLs missing procedures that exists on w10 but doesn't on w7.

On Lens Studio 4.16.1 these procedures are:

* kernel32.dll
  * GetSystemTimePreciseAsFileTime
* dnsapi.dll
  * DnsServiceConstructInstance
  * DnsServiceFreeInstance
  * DnsServiceRegister
  * DnsServiceDeRegister
  * DnsServiceRegisterCancel

To fix the first one, we can just find **GetSystemTimePreciseAsFileTime** string in a HEX editor and replace it with **GetSystemTimeAsFileTime** adding 0x00's to the end of the string to fill the same size. This similar procedure returns the same data type, and works on win7.

To fix the **dnsapi** ones... Well, is not as simple, but since I didn't found where the application really uses these procedures, I've just make a mocked DLL (source attached) **dnsap7.dll** that implements these methods and in case they are called it would show a pop-up with "a","b","c","d","e" depending on the called procedure... but after some testing I've never seen any pop-up.
So just look for **DNSAPI.dll** string in the HEX editor, and replace it with **DNSAP7.dll** and copy **DNSAP7.dll** to Lens Studio installation dir.

After that, Lens Studio should open and work!
But if you notice it sometimes crashes on the project selection screen, then replace **mediaservice/dsengine.dll** with a previous version (that you can find in this git) and after that, it will work fine

## SparkAR Studio

The problem with SparkAR Studio is that you are not allowed to install it on Windows versions prior to Windows 10, and you need to force the installation.
To do that, you must drag and drop the downloaded \*.msi installer to **InstallSparkARWin78.bat** and you will be able to install it.

Once installed, SparkAR should open and work fine for non-script projects. It's still possible that SparkAR won't boot if you have a very old GPU (You'll have the same problem on win10).

To make scripting to work on projects, you should replace the **node-win-x64.exe** from the SparkAR installation folder (that is not compatible with Windows 7) with the latest Windows 7 compatible version of Node.js (14.17.6) that you can find here in this git with the same file name, and then add a new user environment variable with name: **NODE_SKIP_PLATFORM_CHECK** and value **1**

To make it work for latest SparkAR versions, you'll also need to use the same **dnsapi** patch created for Lens Studio, and also replace **GetHostNameW** API call that doesn't exists for win7:
With a HEX editor replace on **ARStudioWindows.exe** the strings **GetHostNameW** with... I've used **GetHostName** and it's working, and **DNSAPI.dll** with **DNSAP7.dll** and copy **DNSAP7.dll** to SparkAR installation dir.