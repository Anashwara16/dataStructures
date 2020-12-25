CC=gcc
CFLAGS=-I.

linkedlist:
	./format.sh
	mkdir -p bld
	$(CC) -g -c linkedlist.c -I linkedlist.h
	$(CC) -g -c stack.c -I stack.h
	$(CC) -g -c queue.c -I queue.h
	$(CC) -g -c tree.c -I tree.h
	$(CC) -g -c utils.c -I utils.h
	mv *.o bld/
	ar rcs bld/liblinkedlist.a bld/linkedlist.o
	ar rcs bld/libstack.a bld/stack.o
	ar rcs bld/libqueue.a bld/queue.o
	ar rcs bld/libtree.a bld/tree.o
	ar rcs bld/libutils.a bld/utils.o
	$(CC) linkedlistTest.c -L bld -llinkedlist -o bld/testll
	$(CC) stackTest.c -L bld -lstack -llinkedlist -o bld/testst
	$(CC) queueTest.c -L bld -lqueue -llinkedlist -o bld/testqu
	$(CC) treeTest.c -L bld -ltree -lutils -o bld/testtre

clean:
	rm -rf bld

dot:
	dot -Tps bld/treeDot.dot -o bld/outfile.ps
	evince bld/outfile.ps
