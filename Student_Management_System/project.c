/**************************************************************************************************
 Name        : project.c
 Author      : Esraa Hesham
 Description : student_management_system_project
 **************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EXIT 8
struct student
{
	int id;        /*student id*/
	char name[50];  /*student name*/
	int age;       /*student age*/
	float gpa;    /*student GPA*/
}st;

struct node
{
	struct student data;
	struct node *next;
};
struct node *head = NULL;

void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);


int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
		setvbuf(stderr,NULL,_IONBF,0);
	struct student *ptr=&st;
	int ID ,choice;
	do{
	printf("*****************************************************\n");
	//display menu option and take user input
	printf("1. Add Student \n");
	printf("2. Display Students \n");
	printf("3. Search Student by ID \n");
	printf("4. Update Student Information \n");
	printf("5. Delete Student \n");
	printf("6. Calculate Average GPA \n");
	printf("7. Search For Student With Highest GPA  \n");
	printf("8. Exit\n");
	printf("enter your choice :\t");
	scanf("%d" , &choice);
	printf("*****************************************************\n");

	switch (choice)
	{
	case 1:
		printf("enter student ID : ");
				scanf("%d", &ptr->id);
				printf("enter student AGE : ");
				scanf("%d",&ptr->age);
				printf("enter student name : ");
				scanf("%s",ptr->name);
				printf("enter student GPA : ");
				scanf( "%f" , &ptr->gpa);
		addStudent(ptr);
    break;
	case 2:
		displayStudents();
		break;
	case 3:
		printf("Enter student ID to search\n");
		scanf("%d",&ID);
		searchStudentByID(ID);
		break;
	case 4:
		printf("Enter student ID to update\n");
		scanf("%d",&ID);
		updateStudent(ID);
		break;
	case 5 :
			printf("Enter student ID to delete\n");
			scanf("%d",&ID);
			deleteStudent(ID);
			break;
	case 6 :
		printf(" Average GPA = %f", calculateAverageGPA());
		break;
	case 7 :
		searchHighestGPA();
		break;

	}
	}while(choice != EXIT);
	printf("Exiting....\n");
	return 0;
}

       /*******************************************************************/

/*
 * This function collects new student details from the user and adds them to the student linked list.
 * It adds a new student to the linked list. It first checks if the student's ID already exists.
 * If the ID exists, it prints an error message and returns. If the ID does not exist, it attempts to allocate memory for a new node.
 * If memory allocation fails, it prints an error message and returns.
 * If memory allocation is successful, it copies the student data to the new node and adds the node to the end of the linked list.
 */

       /*******************************************************************/
void addStudent( const struct student *const ptr)
{

struct node *current = NULL;


	// Allocate memory for new node
	struct node *link = (struct node*) malloc(sizeof(struct node));
	if(link==NULL)
	{
		printf("*****************************************************\n");
		printf("Error to allocate new node\n");
		printf("*****************************************************\n");

		return;
	}

	link->data=*ptr;
	link->next = NULL;

	//check if the list is empty , (add first node)
	if(head==NULL)
	{
		head = link ;
		return;
	}
	//list isn^t empty
	current=head;
	//check if the id is used or not
	while( current !=NULL)
	{
		if(current->data.id == link->data.id)
		{
			printf("*****************************************************\n");
			printf(" this ID is already exists.\n");
			printf("*****************************************************\n");
			return;
		}
		current=current->next;
	}
	current=head;

	// loop until reach the last node in the old list
	while(current->next != NULL)
	{
		current = current->next;
	}

	// Make the last node in the old list point to new node
	current->next = link;
}






     /*******************************************************************/

/*
 * This function displays the details of all students currently in the system.
 * If the list is empty, it prints a message indicating no students are present.
 * Otherwise, it traverses the list and prints the details of each student.
*/

     /*******************************************************************/

void displayStudents(void)
{
	struct node *ptr=head;
	//check if the list is empty
	if(head == NULL)
	{
		printf("*****************************************************\n");
		printf("there is no student information to display\n");
		printf("*****************************************************\n");
		return ;
	}

	while(ptr!=NULL)
	{
		printf("*****************************************************\n");
		printf("student ID  %d\n", ptr->data.id );
		printf("student NAME :%s\n" ,ptr->data.name);
		printf("student AGE  :  %d\n",ptr->data.age);
		printf("student GPA  %f \n",ptr->data.gpa );
		printf("*****************************************************\n");
		ptr=ptr->next;
	}
}
      /*******************************************************************/

/*
 * This function searches for a student by their ID and displays their details if found.
 * It searches for a student by their ID in the linked list.
 * If the student is found, it prints their details.
 *If the student is not found, it prints a message indicating the student was not found
*/

     /*******************************************************************/

void searchStudentByID(int id)
{
	struct node *ptr=head;
	if(head== NULL)
	{
		printf("*****************************************************\n");
		printf("list is empty\n");
		printf("*****************************************************\n");
		return;
	}
	while(ptr!=NULL)
	{
		if( ptr->data.id == id)
		{
			printf("*****************************************************\n");
			printf("student ID   : %d \n" ,ptr->data.id);
			printf("student NAME : %s \n" ,ptr->data.name);
			printf("student AGE  : %d \n" ,ptr->data.age);
			printf("student GPA  : %f \n" ,ptr->data.gpa);
			printf("*****************************************************\n");
			return;
		}
		ptr=ptr->next;
	}
	printf("*****************************************************\n");
	printf("ID not found\n");
	printf("*****************************************************\n");

}




   /*******************************************************************/

/*
 * This function updates the details of a student with the given ID in the linked list.
 * If the student is found, then update the student's information (student name, age, GPA ).
 * If the student is not found, it prints a message indicating the student was not found.
 */

    /*******************************************************************/

void updateStudent(int id)
{
	struct node *ptr=head;

	if(head==NULL)
	{
		printf("*****************************************************\n");
		printf("empty list\n");
		printf("*****************************************************\n");
		return;
	}
	while(ptr!=NULL)
	{
		if( ptr->data.id == id)
		{
			printf("*****************************************************\n");
			printf(" Student New  NAME :  \n" );
			 scanf("%s",ptr->data.name);
			printf(" Student New  AGE  :  \n" );
			scanf("%d",&ptr->data.age);
			printf(" Student New GPA  : \n" );
			scanf("%f",&ptr->data.gpa);
			printf("*****************************************************\n");
			return;
		}
		ptr=ptr->next;
	}
	printf("*****************************************************\n");
	printf("ID not found\n");
	printf("*****************************************************\n");


}
     /*******************************************************************/

/*
 * This function calculates and returns the average GPA of all students in the linked list .
 * It traverses the list to sum the GPAs of all students and counts the number of students.
 * If the list is empty, it returns 0.0.
 * Otherwise, it computes and returns the average GPA by dividing the total sum of GPAs by the number of students.
 */

       /*******************************************************************/


float calculateAverageGPA(void)
{
	float average;
	int sum=0 ,count=0;
	struct node *ptr=head;
	if(head==NULL)
	{
		printf("*****************************************************\n");
		printf("empty list \n");
		printf("*****************************************************\n");
		return 0.0;
	}
	while(ptr!=NULL)
	{
		sum+=ptr->data.gpa;
		count++;
		ptr=ptr->next;
	}
	average = (float ) sum/count;
	return average;
}

       /*******************************************************************/

/*
 * This function finds and displays the student with the highest GPA.
 * Searches for the student with the highest GPA in the linked list.
 * It traverses the list, keeping track of the student with the highest GPA encountered.
 * If the list is empty, it prints a message indicating that there are no students.
 * After finding the student with the highest GPA, it prints the details of that student
 */

      /*******************************************************************/


void searchHighestGPA(void)
{
	float highestgpa=head->data.gpa;
	struct node *ptr=head;
	if(head== NULL)
	{
		printf("*****************************************************\n");
		printf("list is empty there is no student \n");
		printf("*****************************************************\n");
		return;
	}
	while(ptr->next->next !=NULL)
	{
		if( highestgpa < ptr->next->data.gpa)
		{
			highestgpa=ptr->next->data.gpa;
		}
		ptr=ptr->next;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		if( highestgpa == ptr->data.gpa)
		{
			printf("*****************************************************\n");
			printf("Highest GPA student INFO\n");
			printf("student ID   : %d \n" ,ptr->data.id);
			printf("student NAME : %s \n" ,ptr->data.name);
			printf("student AGE  : %d \n" ,ptr->data.age);
			printf("student GPA  : %f \n" ,ptr->data.gpa);
			printf("*****************************************************\n");
			return;
		}
		ptr=ptr->next;
	}
}

           /*******************************************************************/
/*
 * This function deletes a student from the linked list by their ID.
 * Iterates through the linked list of students starting with the Head of it to find the student with the given ID.
 * If the student is found, it adjusts the pointers to remove the node from the list, frees the memory allocated for the node, and prints a success message.
 * If the student is not found, it prints a message indicating the student was not found.
 */

           /*******************************************************************/




void deleteStudent(int id)
{
	struct node *current=head;
	struct node *prev=NULL;
	struct node *del_node=NULL;
	if(head== NULL)
		{
		printf("*****************************************************\n");
			printf("list is empty\n");
			printf("*****************************************************\n");
			return;
		}
		while(current!=NULL)
		{
			if( current->data.id == id)
			{
				del_node=current;
				prev->next=current->next;
				free(del_node);
				printf("deleted successfully\n");
				return;
			}
			prev=current;
			current=current->next;
}
	printf("*****************************************************\n");
   printf(" ID not found\n");
	printf("*****************************************************\n");

}
