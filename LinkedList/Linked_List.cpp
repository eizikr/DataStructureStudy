#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct List list;
struct List {
	int data;
	list* next;
};

list* BuildNode(int num1)
{//creat list with 1 organ and returns a pointer
	list *node = (list*)malloc(sizeof(list));
	node->data = num1;
	node->next = NULL;
	return node;
}

list* BuildList()
{//Build a new list
	list *head = NULL, *temp = head;
	int num;
	printf("Enter numbers for list, -1 for end: ");
	scanf("%d ", &num);
	while (num != -1)//run untill user input is '-1'
	{
		if (head == NULL)
		{
			head = BuildNode(num);
			temp = head;
		}
		else
		{
			temp->next = BuildNode(num);
			temp = temp->next;
		}
		scanf("%d", &num);
	}
		return head;
}

void PrintList(list *head)
{//printing the list organs
	list *temp = head;
	printf("\nThe list is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

list* addToHead(list* head, int num1)
{//create a new element and make him the head of the list.
	list *new_elem = BuildNode(num1);
	new_elem->next = head;
	return new_elem;
}

list* addToTail(list *head, int num1)
{//create a new organ and put him on the tail of the list.
	list *temp, *new_elem;
	new_elem = BuildNode(num1);
	if (head == NULL)
		return new_elem;
	for (temp = head; temp->next != NULL; temp = temp->next);
	temp->next = new_elem;
	return head;
}

list* addToIndex(list* head, int num1, int index)
{//add value to an index and move forword the rest of the list
	list *temp, *new_elem;
	new_elem = BuildNode(num1);
	int i;
	if (head == NULL || index == 1)//if index is the first or list is emptey
	{
		new_elem->next = head;
		return new_elem;
	}
	for (i = 1, temp = head; temp->next != NULL && i < index - 1; temp = temp->next, i++);
	new_elem->next = temp->next;
	temp->next = new_elem;
	return head;
}

void SelectionSort(list* head)
{//sorting the list from smaller to bigger
	list* i;
	list* j = (list*)malloc(sizeof(list));
	list* min = (list*)malloc(sizeof(list));
	list* temp = (list*)malloc(sizeof(list));
	i = head;
	for (; i; i=i->next)	//for all i
	{
		min = i;
		for (j = i->next; j; j = j->next)	//for all j
			if ((j->data) < (min->data))
				min = j;
		SWAP(i->data, min->data, temp->data); //1.temp = i , 2.i = min , 3.min = temp
	}
}

list* FreeList(list *head)
{//free allocated memory of the list
	list *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}

list* Delete(list* head, int value)
{
	list *previous=head, *current=head->next;
	if (head == NULL)//if list is emptey
		return head;
	if (head->data == value)//if the head of the list is the value
	{
		list *temp = head;
		head = head->next;
		free(temp);
		return head;
	}											 
	while (previous!=NULL)//find the value in the list
	{
		if (previous->data == value)
			break;
		current = previous;
		previous = previous->next;
	}
	if (previous != NULL)
		current->next = previous->next;
	free(previous);
	return head;
}

int list_Length(list* head) {
	if (head == NULL)
		return 0;
	int count;
	list* current = head;
	for (count = 1; current->next != NULL; count++, current = current->next);
	return count;
}

list* add_Sorted_Value(list* head, int value) {
	list* new_value = BuildNode(value);	//create a singel value list
	if (head == NULL)//check if list is emptey
		return new_value;
	else if (head->data > value)//check if the first value on the list is lower then the value
	{
		new_value->next = head;
		head = new_value;
	}
	else//find the right spot for the new organ
	{
		list* temp = head;
		for (; temp->next != NULL && value > (temp->next)->data; temp = temp->next);
		new_value->next = temp->next;
		temp->next = new_value;
	}
	return head;
}

void print_Index(list* head, int value)
{
	int index = 1, flag = 0;
	list* temp = head;
	for (; temp != NULL; temp = temp->next, index++)	//for all values in the list
	{
		if (temp->data == value)	//if there is a much, flag on and break
		{
			flag = 1;
			break;
		}
	}
	if (flag)	//if found
		printf("Index of value %d is %d\n", value, index);
	else if (head == NULL)	//if list is emptey
		printf("The list is emptey!\n");
	else  //value is not in the list
		printf("Value %d did not found\n", value);
}

list* Reverse(list* head) //result of this function is a reversed list
{   //set help pointers
	list* before = NULL, * curr = head, * after = head;
	//switching addres places
	while (curr != NULL) // go until the current cell isnt NULL
	{
		after = curr->next; //increment the after pointer
		curr->next = before;	//the next pointer of the cuurent cell will point on the cell before
		before = curr;		//increment the before pointer to the next cell in the list
		curr = after;		//increment the current pointer to the next cell in the list
	}
	head = before;
	return head;
}

int sum(list* head)
{	//set help values
	list* temp = head;
	int sum = 0;
	//calculate sum
	while (temp != NULL)
	{
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

int mull_Even(list* head)
{
	if (head == NULL)//check if list is emptey
		return 0;
	//set help values
	int index = 1, resault = 1;
	list* temp = head;
	//calculate resault
	for (; temp != NULL; temp = temp->next, index++)
	{
		if (index % 2 == 0)
			resault *= temp->data;
	}
	return resault;
}