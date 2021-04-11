main : arrayT.o
	g++ -Wall -Wextra -Werror -g $^ -o $@
arrayT.o : arrayT.cpp
	g++ -Wall -Wextra -Werror -g -c $<
clean : 
	rm -f *.o main
