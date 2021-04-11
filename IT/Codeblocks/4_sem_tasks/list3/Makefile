main : main.o
	g++ -Wall -Wextra -Werror -g -fsanitize=address $< -o $@
main.o : main.cpp
	g++ -Wall -Wextra -Werror -g -fsanitize=address -c $<
clean :
	rm -f *.o main	
