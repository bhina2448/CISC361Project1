#include "studentList.h"

#define BUFFERSIZE 128

student_t * head;
student_t * tail;

void add(){
	char buffer[BUFFERSIZE];
	student_t *student;
	int len;
	student=(student_t*)malloc(sizeof(student_t));
	printf("\nPlease enter the students LAST name: ");
	if(fgets(buffer, BUFFERSIZE, stdin) != NULL){
		len=(int)strlen(buffer);
		buffer[len-1]='\0';
		student->lastname= (char *)malloc(len);
		strcpy(student->lastname, buffer);
	}
	printf("%s",student->lastname);

	printf("\nPlease enter the students FIRST name: ");
	if(fgets(buffer, BUFFERSIZE, stdin) != NULL){
		len=(int)strlen(buffer);
		buffer[len-1]='\0';
		student->firstname= (char *)malloc(len);
		strcpy(student->firstname, buffer);
	}
	printf("%s", student->firstname);

	printf("\nPlease enter the current year of study for the student: ");
	if(fgets(buffer, BUFFERSIZE, stdin) != NULL){
		len=(int)strlen(buffer);
		buffer[len-1]='\0';
		student->year= (char *)malloc(len);
		strcpy(student->year, buffer);
	}
	printf("%s", student->year);

	char gradYear[6];
	printf("\nPlease enter the students expected graduation year: ");
	fgets(gradYear, 6, stdin);
	int yearVal= atoi(gradYear);
	student->grad= yearVal;
	printf("%d", student->grad);

	char idNum[BUFFERSIZE];
	printf("\nPlease enter the students ID number: ");
	if(fgets(idNum, BUFFERSIZE, stdin)!=NULL){
		int len= (int)strlen(idNum);
		idNum[len-1]='\0';;
		long idVal=strtol(idNum, NULL, 10);
		student->id=idVal;
	}
	printf("%lu", student->id);

	//add created student to the list
	student->next=NULL;
	if(head == NULL){
		head = student;
		tail= student;
	}
	else{
		student->prev = tail;
		tail->next= student;
		tail= student;
	}
	printf("\nAdded %s to the list!", student->firstname);
}

void removeStudent(){
	char buffer[BUFFERSIZE];
	char * name;
	int len;
	printf("\nPlease enter the last name of the student(s) who will be removed: ");
	if(fgets(buffer, BUFFERSIZE, stdin) != NULL){
		len= (int) strlen(buffer);
		buffer[len-1]='\0';
		name= (char *)malloc(len);
		strcpy(name,buffer);
	}
		
	student_t * current = head;
	//check if head
	int headCmp= strcmp(head->lastname,name);
	if(headCmp==0){
		if(head->next !=NULL){
			head=head->next;
			head->prev=NULL;
		}
		free(current->lastname);
		free(current->firstname);
		free(current->year);
		free(current);
	}
	else{//check if tail
		int tailCmp= strcmp(tail->lastname,name);
		if(tailCmp==0){
			if(tail->prev != NULL){
				tail=tail->prev;
				tail->next=NULL;
			}
			free(current->lastname);
			free(current->firstname);
			free(current->year);
			free(current);
		}
	}
	while(current != NULL){
		char * searchName= current->lastname;
		int compare= strcmp(searchName, name);
		if(compare == 0){
			removeNode(*current);
			free(current);
		}
		current=current->next;
	}
	free(name);
}
void removeNode(student_t  st){
	st.prev->next=st.next;
	st.next->prev=st.prev;
	free(st.lastname);
	free(st.firstname);
	free(st.year);
}
void printStudent(student_t *  st){
	printf("\nNAME: %s %s", st->firstname, st->lastname);
	printf("\nID: %li", st->id);
	printf("\nYear: %s", st->year);
	printf("\nExpected Graduation: %d", st->grad);
}

void printFront(){
	student_t * current = head;
	while(current != NULL){
		printStudent(current);
		current= current->next;
		printf("\n");
	}
}

void printBack(){
	student_t * current = tail;
	while(current != NULL){
		printStudent(current);
		current=current->prev;
		printf("\n");
	}
}

void clearList(){
	student_t * current = head;
	student_t * prev;
	while(current != NULL){
		free(current->firstname);
		free(current->lastname);
		free(current->year);
		prev=current;
		current= current->next;
		free(prev);
	}
}

int main(void){
	int run=1;
	while(run==1){
		char userInput[3];
		printf("\n1)Add a Student\n2)Remove a Student\n3)Print Student List from Front\n4)Print Student List from Back\n5)Exit");
		printf("\nHello! Please enter the number of the selection you would like to make:");
		fgets(userInput,3,stdin);
		int inputVal= atoi(userInput);
		printf("\nYou entered choice %d",inputVal);

		if(inputVal==1){
			add();
		}
		else if(inputVal==2){
			removeStudent();
		}
		else if(inputVal==3){
			printFront();
		}
		else if(inputVal==4){
			printBack();
		}
		else if(inputVal==5){
			clearList();
			run=0;
		}
		else{
			printf("\nINVALID INPUT");
		}
	}
	return 0;
}
