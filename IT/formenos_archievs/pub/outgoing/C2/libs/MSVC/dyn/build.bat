@set MSVC_PATH=\Program Files\Microsoft Visual Studio 9.0\VC
@set SDK_PATH=\Program Files\Microsoft SDKs\Windows\v6.0A
@PATH=%PATH%;%MSVC_PATH%\bin;%MSVC_PATH%\..\Common7\IDE
@set INCLUDE=%MSVC_PATH%\include
@set LIB=%MSVC_PATH%\lib;%SDK_PATH%\Lib
@set CFLAGS=/nologo
@set LFLAGS=/nologo

cl %CFLAGS% /c unit1.c
cl %CFLAGS% /c unit2.c
link %LFLAGS% /dll /out:dyn.dll unit1.obj unit2.obj

cl %CFLAGS% /c test.c
link %LFLAGS% /out:testdyn.exe test.obj dyn.lib
