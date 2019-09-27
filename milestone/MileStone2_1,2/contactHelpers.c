

/* -------------------------------
Name: Yuki Waka
Student number: 141082180
Email: ywaka@myseneca.ca
Section: SJJ
Date: Mar26
----------------------------------
Assignment: 2
Milestone:  2
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {

	printf("(Press Enter to Continue)");

	clearKeyboard();


}


// getInt: Empty function definition goes here:
int getInt(void) {


	char NL = 'x';
	int value;

	while (NL != '\n') {
		scanf("%d%c", &value, &NL);

		if (NL != '\n') {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();

		}

	}
	return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max) {

	int i = getInt();
	while (min > i || max < i) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		i = getInt();
	}
	return i;
}


// yes: Empty function definition goes here:
int yes(void) {
	char answer = 'x', NL = 'x';

	do {
		scanf(" %c%c", &answer, &NL);

		if (NL != '\n') {
			
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else if (answer == 'y' || answer == 'Y')
			return 1;
		else if (answer == 'n' || answer == 'N')
			return 0;
		else {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		

	} while (1);
}

// menu: Empty function definition goes here:
int menu(void) {

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
	
	int j;
	int featurenum;
	
	do {
		int i = menu();
		if (i > 0 && i <= 6) {
			for (j = 1; j <= i; j++) {
				if (j == i) {
					featurenum = i;
					printf("\n<<< Feature %d is unavailable >>>", featurenum);
					printf("\n\n");
					pause();
					printf("\n");
				}
			}
		}

		else if (i == 0) {
			printf("\nExit the program? (Y)es/(N)o: ");
			
			if (yes()) {
				printf("\nContact Management System: terminated\n");
				break;
			}
			else
				printf("\n");
		}
		
	} while (1);

}