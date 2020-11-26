#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node nodeT;

struct list
{
    struct node *head;
    struct node *tail;
    int totalNodes;
};
typedef struct list listT;

void append(listT *l, int value);
/*
append()	Adds an element at the end of the list
append(elmnt)
clear()	    Removes all the elements from the list
clear( list )
copy()		Returns a copy of the list
copy( list )
count( list )		Returns the number of elements with the specified value
count(value)
extend()	Add the elements of a list (or any iterable), to the end of the current list
extend( list1, list2 )
index()		Returns the index of the first element with the specified value
list.index(elmnt)
insert()	Adds an element at the specified position
insert(list, pos, elmnt)
remove()	Removes the first item with the specified value
remove(list, elmnt)
reverse()	Reverses the order of the list
reverse( list )
sort()		Sorts the list
sort( list, reverse=True|False, key=myFunc)
*/
