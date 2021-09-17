CC=g++
CFLAGS=-Wall -Wextra -Werror -g

exe: main.o number.o test.o
	$(CC) $^ -o $@

main.o: main.cpp number.h
	$(CC) $(CFLAGS) $< -c

number.o: number.cpp number.h
	$(CC) $(CFLAGS) $< -c

test.o: test.cpp
	$(CC) $(CFLAGS) $< -c

clean:  
	rm -rf *.o exe
