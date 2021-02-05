#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int value)
{	// Create a new node
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* Left(node* root)
{	// Returns the left node
	return root->left;
}

node* Right(node* root)
{	// Returns the right node
	return root->right;
}

node* randomInsertInto(node* root, int value)
{	// Puts a value in a random leaf on tree
	if (root == NULL)
		root = NewNode(value);
	else if (rand() % 2 == 0)
		root->left = randomInsertInto(root->left, value);
	else
		root->right = randomInsertInto(root->right, value);
	return root;
}

node* randomTree()
{	// Create a new tree with random size(1-15) and random values(1-50)
	node* root = NULL;
	int size = 1 + rand() % 15;
	printf("\nsize=%d\n", size);
	int i;
	for (i = 1; i <= size; i++)
		root = randomInsertInto(root, 1 + rand() % 50);
	return root;
}

void deleteTree(node* root)
{	// Deleting the tree
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int height(node* root)
{	// Returns the height of the tree
	int Lh, Rh;
	if (root == NULL)
		return -1;
	Lh = height(root->left);
	Rh = height(root->right);
	if (Lh > Rh)
		return Lh + 1;
	else
		return Rh + 1;
}

void PrintGivenLevel(node* root, int level)
{	//	Printing the whole level of the tree (Root level is 1)
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d  ", root->data);
	else if (level > 1)
	{
		PrintGivenLevel(root->left, level - 1);
		PrintGivenLevel(root->right, level - 1);
	}
}

void PrintLevelOrder(node* root)
{	// Printing the whole tree
	int h = height(root);
	int i;
	for (i = 1; i <= h + 1; i++) // start from 1 and not 0
	{
		PrintGivenLevel(root, i);
		printf("\n");
	}
}

void pre_order_traversal(node* root)
{	// Print pre-order (root - left - right)
	if (root != NULL)
	{
		printf("%d  ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void in_order_traversal(node* root)
{	// Print in-order (left - root - right)
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d  ", root->data);
		in_order_traversal(root->right);
	}
}

////	Mission functions	/////

			//1//
int isEmpty(node* root) 
{	// Returns 1 or 0 if root is null
	return root == NULL;
}

			//2//
void printLeaves(node* root)
{	// Printing the leaves of the tree
	if (root == NULL) //
		return;
	if (root->left == NULL && root->right == NULL)// If its a leaf
		printf("%d ", root->data);
	printLeaves(root->left);
	printLeaves(root->right);
}

			//3//
int contains(node* root, int key)
{	// Return 1 if key is in the tree, else return 0
	if (root == NULL)
		return 0;
	if (root->data == key) // If this is the key
		return 1;
	if (contains(root->left, key) + contains(root->right, key))	// In case that we have more then 1 cells with this key
		return 1;
	return 0;
}

			//4//
int countNodes(node* root)
{	// Return the size of the tree
	if (root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

			//5//
int sumOfKeys(node* root)
{	// Return the sum of all keys in the tree
	if (root == NULL)
		return 0;
	return root->data + sumOfKeys(root->left) + sumOfKeys(root->right);
}

			//6//
void levelStatistics(node* root, int level)
{	// Printing the nodes keys and the number of nodes on the level
	printf("\nNodes on level %d: ", level);
	PrintGivenLevel(root, level+1);
	printf("\nNumber of nodes on level %d is: %d\n", level, countNodesInLevel(root, level));
}

			//HelpFunction 1//
int countNodesInLevel(node* root, int level)
{	// A halp function to calculate and return the number of nodes on tree 
	if (root == NULL)
		return 0;
	if (level == 0)
		return 1;
	else if (level > 0)
	{
		return countNodesInLevel(root->left, level - 1) + countNodesInLevel(root->right, level - 1);
	}
}

			//7//
int isPerfect(node* root)
{	// Return 1 if tree is perfect, else return 0			
		/*	If number of nudes on the last level equal to power of 2 by 
			the height of the tree, it means the binary tree is perfect*/
	if (pow(2,height(root)) == countNodesInLevel(root,height(root)))
		return 1;
	return 0;
}
			//HelpFunction 2//
int pow(int number, int power)
{	// Help function to calculate power
	if (power == 0)	// Check power = 0 case
		return 1;

	for (int i = 1; i < power; i++) // calculate
		number *= number;
	return number;
}