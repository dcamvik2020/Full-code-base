@set MSVC_PATH=\Program Files\Microsoft Visual Studio 9.0\VC
@set SDK_PATH=\Program Files\Microsoft SDKs\Windows\v6.0A
@PATH=%PATH%;%MSVC_PATH%\bin;%MSVC_PATH%\..\Common7\IDE
@set INCLUDE=%MSVC_PATH%\include
@set LIB=%MSVC_PATH%\lib;%SDK_PATH%\Lib
nmake /nologo %*