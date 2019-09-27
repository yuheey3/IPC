/* -------------------------------------------
Name: Yuki Waka
Student number: 141082180
Email: ywaka@myseneca.ca
Section: IPC SJJ
Date: Mar.15
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name) {
	char answer;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]30s", name->firstName);     // This is for making 30 spaces inside string characters


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);   // to get input from user, it needs to be character

	if (answer == 'y' || answer == 'Y') { // user can input y or Y

		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]6s", name->middleInitial);   //using [^\n], space will be accepted.

	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", name->lastName);



}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Address *address) {
	char answer;
	printf("Please enter the contact's street number: ");
	scanf(" %d", &address->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]40s", address->street);    // unsigined int


	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &answer);

	if (answer == 'y' || answer == 'Y') {

		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]7s", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]40s", address->city);


}


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbers) {
	char answer;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's cell phone number: ");
		scanf(" %[^\n]10s", numbers->cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's home phone number: ");
		scanf(" %[^\n]10s", numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's business phone number: ");
		scanf(" %[^\n]10s", numbers->business);
	}
}