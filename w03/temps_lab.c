
/*
	Name:           Yuki Waka
	Student Number: 141082180
	Email:          YWAKA@myseneca.ca
	Section:        IPC144-SJJ
	Workshop:       3 (in-lab)
	Date : Feb.1.2019
	Descriptin: To show the high temperture and the low temperture each day.
*/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

//start the code,define the code

#include <stdio.h>
#define NUMS 3

int main(void)
{
	//declear int
	int day, high, low;
	high = 0;
	low = 0;

	// display description of this program
	printf("---=== IPC Temperature Analyzer ===---");

	//making repetive day(1-3day)
	for (day = 1; day <= NUMS; day++) {

		do {
			printf("\nEnter the high value for day %d: ", day);  //display and prompt the user enter
			scanf("%d", &high);  //input
			printf("\nEnter the low value for day %d: ", day); //display 
			scanf("%d", &low); //input


			//checking condition
			if (high < low || high > 40 || low < -41) {
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");//display wrong messages
			}

			//checking conditon
		} while (high < low || high > 40 || low < -41);



	}




	return 0;




}