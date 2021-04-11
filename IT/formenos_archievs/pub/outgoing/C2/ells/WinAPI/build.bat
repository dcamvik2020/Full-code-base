@PATH=%PATH%;C:\Qt\Tools\mingw482_32\bin

gcc -c ells.c
gcc -Wl,-subsystem,windows ells.o iconres.o -o ells.exe -lgdi32 -lcomctl32
