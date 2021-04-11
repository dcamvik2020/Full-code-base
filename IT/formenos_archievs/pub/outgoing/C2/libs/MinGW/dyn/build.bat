@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

gcc -c unit1.c
gcc -c unit2.c
gcc unit1.o unit2.o -shared -o libdyn.dll

gcc -c test.c
gcc test.o -L. -ldyn -o testdyn.exe
