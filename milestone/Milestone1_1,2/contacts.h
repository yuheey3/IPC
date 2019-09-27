
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




#pragma once
// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];


};

// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];

};