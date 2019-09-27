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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>
// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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

// getIntInRange:
int getIntInRange(int min, int max) {
	int i = getInt();
	while (min > i || max < i) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		i = getInt();
	}
	return i;
}
// yes:
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

// menu:
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
	clearKeyboard();
	printf("\n");

}

// contactManagerSystem:

void contactManagerSystem(void) {

	struct Contact contact[MAXCONTACTS] = {
  {
	{ "Rick", {'\0'}, "Grimes" },
   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
   { "4161112222", "4162223333", "4163334444" } },
   {
   { "Maggie", "R.", "Greene" },
   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
   { "9051112222", "9052223333", "9053334444" } },
   {
   { "Morgan", "A.", "Jones" },
   { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
   { "7051112222", "7052223333", "7053334444" } },
   {
   { "Sasha", {'\0'}, "Williams" },
   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
   { "9052223333", "9052223333", "9054445555" } },
	};


	int j;

	do {
		int i = menu();
		if (i > 0 && i <= 6) {
			for (j = 1; j <= i; j++) {
				if (j == i) {

					if (i == 1) {
						displayContacts(contact, MAXCONTACTS);
						pause();
					}
					else if (i == 2) {
						addContact(contact, MAXCONTACTS);
						pause();
					}
					else if (i == 3) {
						updateContact(contact, MAXCONTACTS);
						pause();
					}
					else if (i == 4) {
						deleteContact(contact, MAXCONTACTS);
						pause();
					}
					else if (i == 5) {
						searchContacts(contact, MAXCONTACTS);
						pause();
					}
					else {
						printf("\n<<< Feature to sort is unavailable >>>\n\n");
						//sortContacts(contact[MAXCONTACTS);
						pause();
					}
				}
			}
			printf("\n");
		}

		else if (i == 0) {
			printf("\nExit the program? (Y)es/(N)o: ");


			if (yes()) {
				//printf("\nContact Management System: terminated\n");
				break;
			}
			else
				printf("\n");
		}

	} while (1);
	printf("\nContact Management System: terminated\n");
}
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i;

	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10) {
			needInput = 0;
			for (i = 0; i <= 9; i++) {
				if (phoneNum[i] < 48 || phoneNum[i] > 57)
					needInput = 1;

			}
			if (needInput == 1)
				printf("Enter a 10-digit phone number: ");
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int k;
	int i = 0;
	int find = -1;

	do {
		k = strcmp(contacts[i].numbers.cell, cellNum);
		if (k == 0) {
			find = i;
		}
		i++;
	} while (i < size);

	return find;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}



// displayContactFooter

void displayContactFooter(int size) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d", size);
	printf("\n\n");

}
// displayContact:

void displayContact(const struct Contact *contact) {
	if (contact->name.middleInitial[0] != '\0')
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	else 
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	if (contact->address.apartmentNumber > 0) {
		printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
		printf("Apt# %d, ", contact->address.apartmentNumber);
		printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	}
	else {
		printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
		printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	}
}



// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {

	int i = 0, j = 0;
	int lengh;
	displayContactHeader();

	for (i = 0; i < size; i++) {
		lengh = strlen(contacts[i].numbers.cell);
		if (lengh > 0) {
			displayContact(&(contacts[i]));
			j++;
		}
	}displayContactFooter(j);
}
// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
	int i;
	char cellNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	i = findContactIndex(contacts, size, cellNum);
	if (i >= 0 && i < size) {
		printf("\n");
		displayContact(&(contacts[i]));
		printf("\n");
	}
	else 
		printf("*** Contact NOT FOUND ***\n\n");
}


// addContact:
void addContact(struct Contact contacts[], int size) {
	int i, available = -1;

	printf("\n");
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			available = i;
			break;
		}
	}
	if (available > -1)
	{
		getContact(&contacts[available]);
		printf("--- New contact added! ---\n");
		printf("\n");
	}
	else
		printf("*** ERROR: The contact list is full! ***\n\n");
}


// updateContact:
void updateContact(struct Contact contacts[], int size) {
	int index;
	char cellNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	index = findContactIndex(contacts, size, cellNum);
	if (index == -1) 
		printf("*** Contact NOT FOUND ***\n\n");
	else {
		printf("\nContact found:\n");
		displayContact(&(contacts[index]));
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes()) {
			strcpy(contacts[index].name.firstName, "\0");
			strcpy(contacts[index].name.middleInitial, "\0");
			strcpy(contacts[index].name.lastName, "\0");
			getName(&(contacts[index].name));
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes()) {
			strcpy(contacts[index].address.city, "\0");
			strcpy(contacts[index].address.postalCode, "\0");
			strcpy(contacts[index].address.street, "\0");
			contacts[index].address.streetNumber = 0;
			getAddress(&(contacts[index].address));
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes()) {
			strcpy(contacts[index].numbers.cell, "\0");
			strcpy(contacts[index].numbers.business, "\0");
			strcpy(contacts[index].numbers.home, "\0");
			getNumbers(&(contacts[index].numbers));
		}
		printf("--- Contact Updated! ---\n");
		printf("\n");

	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {

	int index;
	char cellNum[11];
	printf("\n");
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	index = findContactIndex(contacts, size, cellNum);

	if (index == -1) {
		printf("\n");
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&(contacts[index]));
		printf("\nCONFIRM: Delete this contact? (y or n): ");
	}
	if (yes()) {
		strcpy(contacts[index].name.firstName, "\0");
		strcpy(contacts[index].name.middleInitial, "\0");
		strcpy(contacts[index].name.lastName, "\0");
		strcpy(contacts[index].address.city, "\0");
		strcpy(contacts[index].address.postalCode, "\0");
		contacts[index].address.apartmentNumber = 0;
		strcpy(contacts[index].address.street, "\0");
		contacts[index].address.streetNumber = 0;
		strcpy(contacts[index].numbers.cell, "\0");
		strcpy(contacts[index].numbers.business, "\0");
		strcpy(contacts[index].numbers.home, "\0");
		printf("--- Contact deleted! ---\n\n");
	}
	else
		printf("\n");
}


/*
// sortContacts:
void sortContacts(struct Contact contacts[], int size); {

printf("--- Contacts sorted! ---\n");
}
*/

