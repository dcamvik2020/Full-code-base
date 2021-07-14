CC=g++
CFLAGS= -Wall -Wextra -Werror -g

exe: main.o parser.o Factory.o Department.o Employee.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp Factory.h parser.h
	$(CC) $(CFLAGS) $< -c

parser.o: parser.cpp parser.h
	$(CC) $(CFLAGS) $< -c

Factory.o: Factory.cpp Factory.h
	$(CC) $(CFLAGS) $< -c

Department.o: Department.cpp Department.h
	$(CC) $(CFLAGS) $< -c

Employee.o: Employee.cpp Employee.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm *.o exe
