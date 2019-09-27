//--------------------------------------------------
// Name:           YUKI WAKA
// Student Number: 141082810
// Email:          YWAKA@myseneca.ca
// Section:        SJJ
// Date   :        Feb.18
// Workshop:       5 (at home)
//--------------------------------------------------

/* description: using structure, store differnt types of data.
			   store Employee number and information and show their number,age and salary which already stored.*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4 //Define the number of employees

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
	int update = 0;
	int remove = 0;
	double newsalary;

	printf("---=== EMPLOYEE DATA ===---\n");
	do {
		printf("\n1. Display Employee Information\n"); //using do while, it will be shown once.
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");

		printf("\nPlease select from the above options: ");
		scanf("%d", &option); //input option number
		printf("\n");

		switch (option) { //selection construct
		case 1:
			//if you wnat to use for loop -> for (count = 0; count < 0; ++count);{

			printf("EMP ID  EMP AGE EMP SALARY\n");//display
			printf("======  ======= ==========\n");
			int i;

			for (i = 0; i < SIZE; i++) {
				if (emp[i].no > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].no, emp[i].age, emp[i].salary);//display the elements of the struct emp array
				}
			}


			break;
		case 2:

			printf("Adding Employee\n");//display output
			printf("===============\n");

			for (count = 0; count < SIZE; count++) {
				if (emp[count].no == 0) {
					printf("Enter Employee ID: ");
					scanf("%d", &emp[count].no); //input employee information
					printf("Enter Employee Age: ");
					scanf("%d", &emp[count].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[count].salary);
					break;
				}
			}

			
			if (count == SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached");
				printf("\n"); 
			}
				 //if the array is full, display the error message

			break;



		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");

			do {
				printf("Enter Employee ID: ");
				scanf(" %d", &update);

				for (count = 0; count < SIZE; count++) {   //checking condition, to find correct employee number
					if (update == emp[count].no) {  // to check update and employye number are the same or not 
						printf("The current salary is %.2lf\n", emp[count].salary); 
						printf("Enter Employee New Salary: ");
						scanf("%lf", &newsalary); 
						emp[count].salary = newsalary; // assign to left operand 
						break;
					}
				}
				if (count == SIZE) 
					printf("*** ERROR: Employee ID not found! ***\n");

			} while (count == SIZE); // to finish loop
			break;
		case 4:
			printf("Remove Employee\n");
			printf("===============\n");

			do {
				printf("Enter Employee ID: ");
				scanf("%d", &remove);

				for (count = 0; count < SIZE; count++) { //to check employee id
					if (remove == emp[count].no) {
						printf("Employee %d will be removed\n", emp[count].no);

						emp[count].no = 0;  // making employee information to be 0
						emp[count].age = 0;
						emp[count].salary = 0;
						break;
					}
				}
				if (count == SIZE)
					printf("*** ERROR: Employee ID not found! ***\n");
			} while (count == SIZE); //to finish loop

			break;
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n"); //display exiting sentence.
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n");

		}
	} while (option != 0); //finishing do while
	return 0;
}
