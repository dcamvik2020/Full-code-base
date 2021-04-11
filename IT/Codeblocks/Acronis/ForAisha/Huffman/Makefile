main : String.o Tree.o HuffmanCoding.o Compress.o Decompress.o main.o
	g++ -Wall -Wextra -Werror -g $^ -o main
main.o : main.cpp Vector.h String.h Tree.h
	g++ -Wall -Wextra -Werror -g -c $<
HuffmanCoding.o : HuffmanCoding.cpp
	g++ -Wall -Wextra -Werror -g -c $<
Compress.o : Compress.cpp
	g++ -Wall -Wextra -Werror -g -c $<
Decompress.o : Decompress.cpp
	g++ -Wall -Wextra -Werror -g -c $<
String.o : String.cpp String.h
	g++ -Wall -Wextra -Werror -g -c $<
Tree.o : Tree.cpp
	g++ -Wall -Wextra -Werror -g -c $<
clean : 
	rm -f main *.o output* CodesTable*.txt decompressed*.txt
