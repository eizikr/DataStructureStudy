#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<stdlib.h>

typedef struct StudentNode student;
struct StudentNode {
	// Student node structure
	int id;
	int middle_Test;
	int final_Test;
	student* parent;
	student* left;
	student* right;
};

typedef struct Node BST;
struct Node {
	// Students tree structure
	student* root;
};

// Mission functions
void insert(BST* tree, int ID);	// Add a new student to the tree
void updateMidtermGrade(BST* tree, int ID, int newGrade);	// Set middle-test value of the student
void updateExamGrade(BST* tree, int ID, int newGrade);	// Set final-test value of the student
int getFinalGrade(BST* tree, int ID);	// Return the final grade of the student
double getAverageGrade(BST* tree);	// Calculate the avarage of the whole students final grades
void reportGrades(BST* tree);	// Print all students details
int getNumOfFails(BST* tree);	// Return the number of fails students
void ReportStatistics(BST* tree);	// Prints the number of students whose grades are in each field

// Help functions
student* new_Student(int id_);	// Create a new student
student* SearchRet(student* node, int id_);	// Search student on the tree
int getFG(student* node);	// Calculate final grade
int sumFinalGrades(student* node);	// Calculate the sum of all final grades
int countStudents(student* node);	// Count how many students are in the tree
void printStudent(student* node);	// Print a single student details
void printAllStudents(student* node);	// Print all students details
int countFails(student* node);	// Count how many fails students are in the tree
int count56_75(student* node);	// Count how many students got final score between (56-75)
int count76_94(student* node);	// Count how many students got final score between (76-94)
int count95_100(student* node);	// Count how many students got final score between (94-100)
void freeStudents(student* stud);	// Free all nodes on the tree
void freeBST(BST** tree);	// Free nodes and the tree
void printStudentNode(student* node);	// Print students keys (id's)
void printBST(BST* tree);	// Print the whole tree

#endif // !STUDENT_H
