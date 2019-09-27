/*
	Name:           YUKI WAKA
	Student Number: 141082180
	Email:          YWAKA@myseneca.ca
	Section:        IPC144
	Workshop:       2 (at-home)
*/


#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>
int main(void) {

	double amount, balance, GST;
	int Loonies, Quarters, Dimes, Nickels, Pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	GST = amount * .13 + .005;
	balance = amount + GST;
	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2f\n", balance);
	
	Loonies = (int)balance;
	balance = balance - (float)Loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, balance);
	
	Quarters = (balance * 100) / 25;
	balance = balance - Quarters * 0.25;
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, balance);
	
	Dimes = (int)(balance * 100) / 10;
	balance = balance - 0.1 * Dimes;
	printf("Dimes required: %d, balance owing $%.2lf\n", Dimes, balance);
	
	Nickels = (balance * 100) / 5;
	balance = balance - 0.05 * Nickels;
	printf("Nickels required: %d, balance owing $%.2lf\n", Nickels, balance);
	
	Pennies = (balance * 100) / 1;
	balance = balance - 0.01 * Pennies;
	printf("Pennies required: %d, balance owing $%.2lf\n", Pennies, balance);

	return 0;
}