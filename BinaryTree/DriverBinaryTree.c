/*This code was created by:
Itzik rahamim - 312202351
Gil ben hamo - 315744557
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"BinaryTree.h"

int main()
{
	srand(time(NULL));
	node* root;
	int H, level, NumToSearch;
	root = randomTree();
	H = height(root);
	// First prints
	printf("\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);
	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);

	// Check function 'isEmpty'
	printf("\n\nThe tree is empty? : ");
	if (isEmpty(root))
		printf("Yes!");
	else printf("No!");

	// Check function 'printLeaves'
	printf("\n\nLeaves: ");
	printLeaves(root);
	
	// Check function 'contains'
	printf("\n\nEnter a number to search: ");
	scanf("%d", &NumToSearch);
	if (contains(root, NumToSearch))
		printf("This key is in the tree!\n");
	else printf("This key isn't found in the tree...\n");

	// Check function 'countNudes'
	printf("\nNumber of nodes: %d\n", countNodes(root));

	// Check function 'sumOfKeys'
	printf("\nSum of keys is: %d\n", sumOfKeys(root));
	
	// Check function 'levelStatistics'
	printf("\nEnter the level you want: ");
	scanf("%d", &level);
	printf("\nLevel statistics:");
	levelStatistics(root, level);

	// Check function 'isPerfect'
	printf("\nIs the tree perfect: ");
	if (isPerfect(root))
		printf("Yes!\n");
	else printf("No!\n");

	deleteTree(root);

	//printf("\nTree deleted\n");
	return 0;
}