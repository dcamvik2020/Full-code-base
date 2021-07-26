CC=g++
CFLAGS= -Wall -Wextra -Werror -g

exe: main.o parser.o Factory.o Department.o Employee.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -c

clean:
	rm *.o exe
