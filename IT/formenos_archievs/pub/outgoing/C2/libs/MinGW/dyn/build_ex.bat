@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

gcc -c unit1.c
gcc -c unit2.c
gcc unit1.o unit2.o -shared -o libdyn.dll

gcc -c testdyn_ex.c
gcc testdyn_ex.o -o testdyn_ex.exe
