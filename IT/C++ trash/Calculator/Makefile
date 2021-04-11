FLAGS= -Wall -Wextra -Werror -g 

main : main.o calculator.o term.o functions.o
	g++ $(FLAGS) $^ -o $@
	mv *.o debug

%.o : %.cpp
	g++ -c $<
# one rule for all commented rules below
#main.o : main.cpp
#	g++ -c $<
#
#calculator.o : calculator.cpp
#	g++ -c $<
#
#term.o : term.cpp
#	g++ -c $<
#
#functions.o : functions.cpp
#	g++ -c $<


clean : 
	rm main ./debug/*
