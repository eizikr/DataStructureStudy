#include "student.h"

			//	Mission functions	//

void insert(BST* tree, int ID)
{	// Create new student and help pointers
	student* stud = new_Student(ID);
	student *p = NULL;
	student *check = tree->root;

	// Look for the right place in the tree for the new student
	while (check != NULL)
	{
		p = check;	// Update parent pointer
		if (ID < check->id)
			check = check->left;
		else if (ID > check->id)
			check = check->right;
		else
		{	// Already exists case
			printf("This id is already exsist in the tree!\n");
			return;
		}
	}
	// Set the student on right place
	stud->parent = p;
	if (p == NULL)
		tree->root = stud;
	else if (stud->id < p->id)
		p->left = stud;
	else
		p->right = stud;
}

void updateMidtermGrade(BST* tree, int ID, int newGrade)
{
	// Find the student by the id and point him
	student* checkNode = SearchRet(tree->root, ID);
	if (checkNode == NULL)	// Not on the tree case
		return;
	else // Set middle test grade
		checkNode->middle_Test = newGrade;
}

void updateExamGrade(BST* tree, int ID, int newGrade)
{
	// Find the student by the id and point him
	student* checkNode = SearchRet(tree->root, ID);
	if (checkNode == NULL)	// Not on the tree case
		return;
	else // Set final test grade
		checkNode->final_Test = newGrade;
}

int getFinalGrade(BST * tree, int ID)
{
	// Find the student by the id and point him
	student* check = SearchRet(tree->root, ID);
	if (check == NULL)	// Not on the tree case
		return 0;
	return getFG(check); // Return the final grade
}

double getAverageGrade(BST * tree)
{	// Calculate the avarage of the whole students final grades
	return (double)sumFinalGrades(tree->root)/countStudents(tree->root);
}

void reportGrades(BST* tree)
{	// Print all students details
	printf("\nid   midterm   test    final");
	printAllStudents(tree->root);
}

int getNumOfFails(BST* tree)
{	// Return the number of fails students
	return countFails(tree->root);
}

void ReportStatistics(BST * tree)
{	// Prints the number of students whose grades are in each field
	printf("\nReport Statistics:");
	printf("\n\t  Degree\t Amount\n");
	printf("Good\t  (56-75)\t   %d\n",count56_75(tree->root));
	printf("Very good (76-94)\t   %d\n", count76_94(tree->root));
	printf("Excellent (95-100)\t   %d\n", count95_100(tree->root));
}


			//	Help functions	//

student* new_Student(int id_) {
	// Create a new student and init values
	student* s = (student*)malloc(sizeof(student));
	s->id = id_;
	s->middle_Test = 0;
	s->final_Test = 0;
	s->parent = NULL;
	s->left = NULL;
	s->right = NULL;
	return s;
}

void freeStudents(student* stud)
{	// Free all students allocated memory
	if (stud == NULL)
		return;
	freeStudents(stud->left);
	freeStudents(stud->right);
	free(stud);
}

void freeBST(BST** tree)
{	// Free nodes and tree
	freeStudents((*tree)->root);
	free(*tree);
}

void printStudentNode(student* node)
{	// Print students id nodes
	if (node == NULL)
		return;
	printf("(");
	printStudentNode(node->left);
	printf("%d", node->id);
	printStudentNode(node->right);
	printf(")");
}

void printBST(BST* tree)
{	// Print the whole tree
	printStudentNode(tree->root);
	printf("\n");
}

student* SearchRet(student* node, int id_)
{	
	if (node == NULL)	// Student not found case
	{
		printf("This ID dont exsist in the TREE!\n");
		return NULL;
	}
	if (node->id == id_)	// Student found case
		return node;
	if (id_ <= node->id)
		return SearchRet(node->left, id_);
	else
		return SearchRet(node->right, id_);
}

int getFG(student * check)
{	// Calculate the final grade by the formula
	float final_grade = check->middle_Test * 0.3 + check->final_Test * 0.7;
	// Trasform to int - then multiply by 10 - than check the reminder to round the score
	if ((int)(final_grade * 10) % 10 >= 5)
		return (int)(final_grade)+1;
	else
		return (int)(final_grade);
}

int sumFinalGrades(student* node)
{	// Calculate the sum of all the final grades
	if (node == NULL)
		return 0;
	return getFG(node) + sumFinalGrades(node->left) + sumFinalGrades(node->right);
}

int countStudents(student * node)
{	// Count the number of students on the tree
	if (node == NULL)
		return 0;
	return 1 + countStudents(node->left) + countStudents(node->right);
}

void printStudent(student * node)
{	// Print student details by (id) - (middle_test) - (final_test) - (final_grade)
	if (node == NULL)
		return;
	else
		printf("\n%d \t%d \t%d \t%d", node->id, node->middle_Test, node->final_Test, getFG(node));
}

void printAllStudents(student * node)
{	// Print all students details by (id) - (middle_test) - (final_test) - (final_grade)
	if (node != NULL)
	{
		printAllStudents(node->left);
		printStudent(node);
		printAllStudents(node->right);
	}
}

int countFails(student * node)
{	// Calculate number of failed students
	if (node == NULL)
		return 0;
	if(getFG(node)<56)	// Failed case
		return 1 + countFails(node->left) + countFails(node->right);
	return 0 + countFails(node->left) + countFails(node->right);
}

int count56_75(student * node)
{	// Calculate how many students final grades are between 56-75
	if (node == NULL)
		return 0;
	if (getFG(node) >= 56 && getFG(node) <= 75)
		return 1 + count56_75(node->left) + count56_75(node->right);
	return 0 + count56_75(node->left) + count56_75(node->right);
}

int count76_94(student * node)
{	// Calculate how many students final grades are between 76-94
	if (node == NULL)
		return 0;
	if (getFG(node) >= 76 && getFG(node) <= 94)
		return 1 + count76_94(node->left) + count76_94(node->right);
	return 0 + count76_94(node->left) + count76_94(node->right);
}

int count95_100(student * node)
{	// Calculate how many students final grades are between 95-100
	if (node == NULL)
		return 0;
	if (getFG(node) >= 95 && getFG(node) <= 100)
		return 1 + count95_100(node->left) + count95_100(node->right);
	return 0 + count95_100(node->left) + count95_100(node->right);
}
