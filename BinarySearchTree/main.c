#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

int main()
{
	// SETUPS - build the tree
	BST* Tree = (BST*)malloc(sizeof(BST));
	Tree->root = NULL;
	int id_arr[] = { 6,15,11,3,1,22,5 };
	int id_size = sizeof(id_arr) / sizeof(int);
	for (int index = 0; index < id_size; index++)
		insert(Tree, id_arr[index]);

	// INDICATION - how the tree was builded after inserts
	printf("Binary search tree:\n");
	printBST(Tree);

	//UPDATE - fill students grades fields with value
	int grades_arr[] = { 81,52,15,95,60,89,90,100,90,73,26,45,55,75 };
	int grades_size = sizeof(grades_arr) / sizeof(int);
	for (int i = 0, j = 0; j < grades_size; i++)
	{
		updateMidtermGrade(Tree, id_arr[i], grades_arr[j++]);
		updateExamGrade(Tree, id_arr[i], grades_arr[j++]);
	}

	// PRINT - print required details
	printf("\nThe average grade in the course: %lf\n",getAverageGrade(Tree));
	printf("\nGrades report:");
	reportGrades(Tree);
	printf("\n\nThe number of failures: %d\n", getNumOfFails(Tree));
	ReportStatistics(Tree);

	// FREE - free allocated memory
	freeBST(&Tree);
	return 0;

}