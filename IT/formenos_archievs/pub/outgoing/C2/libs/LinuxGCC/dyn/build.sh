gcc -c -fPIC unit1.c
gcc -c -fPIC unit2.c
gcc unit1.o unit2.o -shared -o libdyn.so

gcc -c test.c
gcc test.o -L. -ldyn -o testdyn

export LD_LIBRARY_PATH=.
./testdyn
