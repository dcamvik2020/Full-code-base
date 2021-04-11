main : main.o node.o database.o condition_parser.o condition_parser_test.o token.o date.o
	g++ -Wall -Wextra -Werror -g $^ -o main
main.o : main.cpp
	g++ -Wall -Wextra -Werror -g -c $<
node.o : node.cpp
	g++ -Wall -Wextra -Werror -g -c $<
database.o : database.cpp
	g++ -Wall -Wextra -Werror -g -c $<
condition_parser.o : condition_parser.cpp
	g++ -Wall -Wextra -Werror -g -c $<
condition_parser_test.o: condition_parser_test.cpp
	g++ -Wall -Wextra -Werror -g -c $<
token.o : token.cpp
	g++ -Wall -Wextra -Werror -g -c $<
date.o : date.cpp
	g++ -Wall -Wextra -Werror -g -c $<
clean : 
	rm -f main *.o
