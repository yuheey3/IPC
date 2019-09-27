/* -------------------------------------------
Name: YUKI WAKA
Student number: 141082180
Email:  ywaka@myseneca.ca
Section: IPC 144 -SJJ
Date: Mar.11.2019
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"   //declear header file




// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main(void)
{
	// Declare variables here:

	struct Name name;
	struct Address address;
	struct Numbers number;
	char answer;
	// Display the title

	printf("Contact Management System\n");
	printf("-------------------------\n");


	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %30s", name.firstName);     // This is for making 30 spaces inside string characters


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &answer);   // to get input from user, it needs to be character

	if (answer == 'y' || answer == 'Y') { // user can input y or Y

		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]6s", name.middleInitial);   //using [^\n], space will be accepted. 

	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", name.lastName);


	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf(" %d", &address.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]40s", address.street);    // unsigined int


	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &answer);

	if (answer == 'y' || answer == 'Y') {

		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address.apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]7s", address.postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]40s", address.city);



	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's cell phone number: ");
		scanf(" %[^\n]10s", number.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's home phone number: ");
		scanf(" %[^\n]10s", number.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &answer);// to get input from user, it needs to be character


	if (answer == 'y' || answer == 'Y') {// user can input y or Y
		printf("Please enter the contact's business phone number: ");
		scanf(" %[^\n]10s", number.business);
	}

	// Display Contact Summary Details
	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", name.firstName);
	printf("Middle initial(s): %s\n", name.middleInitial);
	printf("Last name: %s\n\n", name.lastName);
	printf("Address Details\n");
	printf("Street number: %d\n", address.streetNumber);
	printf("Street name: %s\n", address.street);
	printf("Apartment: %d\n", address.apartmentNumber);
	printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n\n", address.city);
	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", number.cell);
	printf("Home phone number: %s\n", number.home);
	printf("Business phone number: %s\n\n", number.business);

	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");


	return 0;
}

/*  SAMPLE OUTPUT:

	Contact Management System
	-------------------------
	Please enter the contact's first name: Tom
	Do you want to enter a middle initial(s)? (y or n): y
	Please enter the contact's middle initial(s): L. A.
	Please enter the contact's last name: Wong Song
	Please enter the contact's street number: 20
	Please enter the contact's street name: Keele Street
	Do you want to enter an apartment number? (y or n): y
	Please enter the contact's apartment number: 40
	Please enter the contact's postal code: A8A 4J4
	Please enter the contact's city: North York
	Do you want to enter a cell phone number? (y or n): Y
	Please enter the contact's cell phone number: 9051116666
	Do you want to enter a home phone number? (y or n): Y
	Please enter the contact's home phone number: 7052227777
	Do you want to enter a business phone number? (y or n): Y
	Please enter the contact's business phone number: 4163338888
	Contact Details
	---------------
	Name Details
	First name: Tom
	Middle initial(s): L. A.
	Last name: Wong Song
	Address Details
	Street number: 20
	Street name: Keele Street
	Apartment: 40
	Postal code: A8A 4J4
	City: North York
	Phone Numbers:
	Cell phone number: 9051116666
	Home phone number: 7052227777
	Business phone number: 4163338888
	Structure test for Name, Address, and Numbers Done!
*/