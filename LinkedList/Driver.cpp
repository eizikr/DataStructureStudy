#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Linked_List.h"


int main()
{
	list* head = NULL;
	int num, index;
	head = BuildList();

	PrintList(head);
	printf("The lenth is:%d\n", list_Length(head));
	printf("\nEnter a number for new head node: ");
	scanf("%d", &num);
	head = addToHead(head, num);
	PrintList(head);
	printf("The lenth is:%d\n", list_Length(head));
	printf("\nEnter a number for new tail node: ");
	scanf("%d", &num);
	head = addToTail(head, num);
	PrintList(head);
	printf("The lenth is:%d\n", list_Length(head));
	printf("\nEnter a number and an index for new node: ");
	scanf("%d%d", &num, &index);
	head = addToIndex(head, num, index);
	PrintList(head);
	printf("\nEnter a value for find: ");
	scanf("%d", &num);
	print_Index(head, num);
	printf("\nEnter a value for find: ");
	scanf("%d", &num);
	print_Index(head, num);
	printf("\nSorted List: ");
	SelectionSort(head);
	PrintList(head);
	printf("\nEnter a number for new node Sort List: ");
	scanf("%d", &num);
	add_Sorted_Value(head, num);
	PrintList(head);
	printf("The lenth is:%d\n", list_Length(head));
	printf("\nReversed list:\n");
	head = Reverse(head);
	PrintList(head);
	printf("\nEnter a value for delete: ");
	scanf("%d", &num);
	head = Delete(head, num);
	PrintList(head);
	printf("The lenth is:%d\n", list_Length(head));
	printf("\nSum of list is %d\n", sum(head));
	printf("\nProduct of even index values of list is %d\n", mull_Even(head));
	head = FreeList(head);
	return 0;
}