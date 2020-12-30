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
	$(CC) -g -c maxheap.c -I maxheap.h
	$(CC) -g -c hashTable.c -I hashTable.h
	$(CC) -g -c graph.c -I graph.h
	mv *.o bld/
	ar rcs bld/liblinkedlist.a bld/linkedlist.o
	ar rcs bld/libstack.a bld/stack.o
	ar rcs bld/libqueue.a bld/queue.o
	ar rcs bld/libtree.a bld/tree.o
	ar rcs bld/libutils.a bld/utils.o
	ar rcs bld/libmaxheap.a bld/maxheap.o
	ar rcs bld/libhashTable.a bld/hashTable.o
	ar rcs bld/libgraph.a bld/graph.o
	$(CC) linkedlistTest.c -L bld -llinkedlist -lutils -o bld/testll
	$(CC) stackTest.c -L bld -lstack -llinkedlist -lutils -o bld/testst
	$(CC) queueTest.c -L bld -lqueue -llinkedlist -lutils -o bld/testqu
	$(CC) treeTest.c -L bld -ltree -lutils -o bld/testtre
	$(CC) maxheapTest.c -L bld -lmaxheap -lutils -o bld/testmax
	$(CC) hashTest.c -L bld -lhashTable -lutils -o bld/testhash
	$(CC) graphTest.c -L bld -lgraph -lutils -o bld/testgraph

clean:
	rm -rf bld

dot:
	dot -Tps bld/graph.dot -o bld/graph.ps
	evince bld/graph.ps
