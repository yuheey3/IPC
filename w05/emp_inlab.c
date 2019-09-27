//--------------------------------------------------
// Name:           YUKI WAKA
// Student Number: 141082810
// Email:          YWAKA@myseneca.ca
// Section:        SJJ
// Workshop:       5 (in-lab)
//--------------------------------------------------

// description: using structure, store differnt types of data.
               //store Employee number and information and show their number,age and salary which already stored.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2 //Define the number of employees

// Declare Struct Employee 

struct Employee { //store data of different types
	int no;               //An identification number stored in an int
	int age;              //Age stored in an int
	double salary;        //Salary stored in a double
};

int main(void)
{
	int option; //declear option
	struct Employee emp[SIZE] = { {0} }; //declear an array of Employee that can hold SIZE elements. Initialize all of the elements and their member variables to be 0
	int count = 0; //declear count

	printf("---=== EMPLOYEE DATA ===---\n"); //display output
	do {
		printf("\n1. Display Employee Information\n"); //using do while, it will be shown once.
		printf("2. Add Employee\n");
		printf("0. Exit\n");

		printf("\nPlease select from the above options: ");
		scanf("%d", &option); //input option number
                printf("\n");

		switch (option) { //selection construct
		case 1:
			//if you wnat to use for loop -> for (count = 0; count < 0; ++count);{
			if (emp[0].no > 0) {
				printf("EMP ID  EMP AGE EMP SALARY\n");//display
				printf("======  ======= ==========\n");
				printf("%6d%9d%11.2lf\n", emp[0].no, emp[0].age, emp[0].salary);//display the elements of the struct emp array
				printf("%6d%9d%11.2lf\n", emp[1].no, emp[1].age, emp[1].salary);
			}

			break;
		case 2:
			printf("Adding Employee\n");//display output
			printf("===============\n");
			if (count < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[count].no); //input employee information
				printf("Enter Employee Age: ");
				scanf("%d", &emp[count].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[count].salary); 
				count++; //increase the number

			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached");
                                printf("\n");
			} //if the array is full, display the error message
			break;
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n"); //display exiting sentence.
			break;

		default:
			printf("You put the wrong number!\n");
		}
	} while (option != 0); // if input is not 0, go back.

	return 0;
}