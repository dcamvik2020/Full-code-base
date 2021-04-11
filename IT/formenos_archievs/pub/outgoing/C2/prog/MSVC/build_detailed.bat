@set MSVC_PATH=\Program Files\Microsoft Visual Studio 9.0\VC
@set SDK_PATH=\Program Files\Microsoft SDKs\Windows\v6.0A
@PATH=%PATH%;%MSVC_PATH%\bin;%MSVC_PATH%\..\Common7\IDE
@set INCLUDE=%MSVC_PATH%\include
@set LIB=%MSVC_PATH%\lib;%SDK_PATH%\Lib
@set CFLAGS=/nologo
@set LFLAGS=/nologo

@REM *** Preprocessor ***
cl %CFLAGS% /EP prog.c > prog1.c
@REM *** Compiler ***
cl /nologo /FA /c prog1.c
@REM *** Assembler ***
ml %CFLAGS% /c prog1.asm

@REM *** Preprocessor ***
cl %CFLAGS% /EP unit.c > unit1.c
@REM *** Compiler ***
cl /nologo /FA /c unit1.c
@REM *** Assembler ***
ml %CFLAGS% /c unit1.asm

@REM *** Linker ***
link %LFLAGS% prog1.obj unit1.obj
