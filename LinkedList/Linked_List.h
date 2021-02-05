#ifndef _LINKED_LIST
#define _LINKED_LIST
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct List list;
struct List {
	int data;
	list* next;
};


list* BuildList();
void PrintList(list*);
list* BuildNode(int);
list* addToHead(list*, int);
list* addToTail(list*, int);
list* addToIndex(list*, int, int);
void SelectionSort(list*);
list* FreeList(list*);
list* Delete(list*, int);

int list_Length(list* head);//return the length of the list you sent.
list* add_Sorted_Value(list* head, int value);//get a value, and put it on the right spot in a sorted list.
void print_Index(list* head, int value);//if value exist in the list, print the index.
list* Reverse(list* head);//reverse the values in the list.
int sum(list* head);//return the sum of values in the list.
int mull_Even(list* head);//return the mull of values in the list that in the even indexes.
#endif
