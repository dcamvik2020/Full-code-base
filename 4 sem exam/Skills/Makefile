example : example.o unit.o
	g++ $^ -o $@
example.o : example.cpp unit.h
	g++ -Wall -Wextra -g -c $<
unit.o : unit.cpp
	g++ -Wall -Wextra -g -c $<
clean : 
	rm -f *.o example 
