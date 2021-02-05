#ifndef _BINARY_TREE
#define _BINARY_TREE
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};

node* NewNode(int);
node* Left(node*);
node* Right(node*);
node* randomInsertInto(node*, int);
node* randomTree();
void deleteTree(node*);
int height(node*);
void PrintGivenLevel(node*, int);
void PrintLevelOrder(node*);
void pre_order_traversal(node*);
void in_order_traversal(node*);

// Mission functions
int isEmpty(node* root);
void printLeaves(node* root);
int contains(node* root, int key);
int countNodes(node* root);
int sumOfKeys(node* root);
void levelStatistics(node* root, int level);
int isPerfect(node* root);

// Help functions
int countNodesInLevel(node* root, int level);
int pow(int number, int power);

#endif
