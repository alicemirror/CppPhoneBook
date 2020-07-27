# Makefile for the PhoneBook class and terminal test application
#
# Version 0.1
# Tested on Raspbian Buster
# Compiles with g++ 8.x C++11

all:
	g++ -g -c main.cpp -o main.o
	g++ -g -c phonebook.cpp -o phonebook.o
	g++ main.o -L. phonebook.o -o PhoneBook
	
clean:
	rm -rf *.o
	
	
