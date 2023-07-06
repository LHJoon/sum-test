#Makefile
all: sum-test

sum-test: sum.o main.o
	g++ -o sum-test sum.o main.o

main.o: sum.h main.cpp
	g++ -c -o sum.o sum.cpp

sum.o: sum.h sum.cpp
	g++ -o sum-test main.o sum.o
clean:
	rm -f sum-test
	rm -f *.o

