CC=g++
CFLAGS=-I.

linkedlist:
	$(CC) -c linkedlist.cpp -I linkedlist.h
	ar rcs liblinkedlist.a linkedlist.o
	$(CC) test.cpp -L . -llinkedlist -o test

clean:
	rm linkedlist.o liblinkedlist.a test
