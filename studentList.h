#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *Student struct, acts as node for DLL
 *Contains pointers for next and previous student in list
 */
typedef struct student{
	char *lastname;
	char *firstname;
	long id;
	char *year;
	int grad;
	struct student *next;
	struct student *prev;
}student_t;

/*
 *Prompts the user for student information then adds a new student to the end of the list
 */
void add();

/*
 *Prompts the user for a last name for student(s) to be removed
 *searches for students containng that last name, when found that student will be passed to removeNode()
 */
void removeStudent();

/*
 *Helper function for removeStudent
 *Removes and frees student passed from the DLL
 */
void removeNode(student_t student);

/*
 *Helper function for printFront() and printBack()
 *Prints the students information
 */
void printStudent(student_t *  student);

/*
 *Starting at the head of the list, iterates through all of the students passing each one to printStudent()
 */
void printFront();

/*
 *Starting at the tail of the list, iterates through all of the students passing each one to printStudent();
 */
void printBack();

/*
 *Iterates through the DLL starting at the head and frees all nodes
 */
void clearList();

int main();
