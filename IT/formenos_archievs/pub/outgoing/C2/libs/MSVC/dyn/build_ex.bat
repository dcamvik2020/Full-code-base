@set MSVC_PATH=\Program Files\Microsoft Visual Studio 9.0\VC
@set SDK_PATH=\Program Files\Microsoft SDKs\Windows\v6.0A
@PATH=%PATH%;%MSVC_PATH%\bin;%MSVC_PATH%\..\Common7\IDE
@set INCLUDE=%MSVC_PATH%\include;%SDK_PATH%\Include
@set LIB=%MSVC_PATH%\lib;%SDK_PATH%\Lib
@set CFLAGS=/nologo
@set LFLAGS=/nologo

cl %CFLAGS% /c unit1.c
cl %CFLAGS% /c unit2.c
link %LFLAGS% /dll /out:dyn.dll unit1.obj unit2.obj
@del dyn.lib dyn.exp

cl %CFLAGS% /c testdyn_ex.c
link %LFLAGS% testdyn_ex.obj
