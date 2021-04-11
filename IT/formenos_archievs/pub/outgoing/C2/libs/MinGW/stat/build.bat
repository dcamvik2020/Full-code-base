@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

gcc -c unit1.c
gcc -c unit2.c
ar -rc libstat.a unit1.o unit2.o
@REM ranlib libstat.a

gcc -c test.c
gcc test.o -L. -lstat -o teststat.exe
