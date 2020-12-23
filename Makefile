CC=gcc
CFLAGS=-I.

linkedlist:
	mkdir -p bld
	$(CC) -g -c linkedlist.c -I linkedlist.h
	mv linkedlist.o bld/linkedlist.o
	ar rcs bld/liblinkedlist.a bld/linkedlist.o
	$(CC) linkedlistTest.c -L bld -llinkedlist -o bld/test

clean:
	rm -rf bld
