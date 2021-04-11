gcc -c -fPIC unit1.c
gcc -c -fPIC unit2.c
gcc unit1.o unit2.o -shared -o libdyn.so

gcc -c testdyn_ex.c
gcc testdyn_ex.o -ldl -o testdyn_ex
