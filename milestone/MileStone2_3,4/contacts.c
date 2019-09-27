/* -------------------------------
Name: Yuki Waka
Student number: 141082180
Email: ywaka@myseneca.ca
Section: SJJ
Date: April.5
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+




// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name *name) {
	//char answer;
	int f;

	
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]s", name->firstName);     // This is for making 30 spaces inside string characters
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	f = yes();
	if (f == 1) {
		//if (answer == 'y' || answer == 'Y') { // user can input y or Y

		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s", name->middleInitial);

		clearKeyboard();
		//using [^\n], space will be accepted.
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", name->lastName);
}




// getAddress:
void getAddress(struct Address *address) {
	int a;
	int b;
	int c;

	printf("Please enter the contact's street number: ");

	do {
		a = getInt();

		if (a < 0)
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
	} while (a < 0);

	address->streetNumber = a;


	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);    // unsigined int


	printf("Do you want to enter an apartment number? (y or n): ");

	//if (answer == 'y' || answer == 'Y') {
	b = yes();
	if (b == 1) {
		printf("Please enter the contact's apartment number: ");
		// scanf(" %d", &address->apartmentNumber);

		do {
			c = getInt();
			if (c < 0)
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
		} while (c < 0);
		address->apartmentNumber = c;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", address->city);
}


// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers *numbers) {
	int d;
	//	printf("Do you want to enter a cell phone number? (y or n): ");
	//	scanf(" %c", &answer);// to get input from user, it needs to be character


		//if (answer == 'y' || answer == 'Y') {// user can input y or Y

	printf("Please enter the contact's cell phone number: ");
	//scanf(" %10[^\n]s", numbers->cell);
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");

	d = yes();
	if (d == 1) {
		//	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's home phone number: ");
		//scanf(" %10[^\n]s", numbers->home);
		getTenDigitPhone(numbers->home);
	}


	printf("Do you want to enter a business phone number? (y or n): ");

	d = yes();
	if (d == 1) {
		//if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's business phone number: ");
		//scanf(" %10[^\n]s", numbers->business);
		getTenDigitPhone(numbers->business);
	}
}


// getContact
void getContact(struct Contact *contact) {
	getName(&contact->name);

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&contact->address);

	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&contact->numbers);
}