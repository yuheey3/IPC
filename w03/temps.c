
/*
Name:           Yuki Waka

Student Number: 141082180

Email:          YWAKA@myseneca.ca

Section:        IPC144-SJJ

Workshop:       3 (at home)

Date : Feb.4.2019

Descriptin: To display the high temperture and the low temperture each day.And also display the highest temperture and lowest temperture with days.
			Calculate overall temperture at the end.


*/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

//start the code,define the code

#include <stdio.h>

#define NUMS 4

int main(void)
{
	//declear int
	int day;
	int high[NUMS], low[NUMS];
	int highest, i , j , k;
	int lowest;
	int lowday;
	int highday;
	double average = 0;
	int totalhigh = 0;
	int totallow = 0;
	double highaverage = 0;
	double lowaverage = 0;

	// display description of this program
	printf("---=== IPC Temperature Analyzer ===---");

	//making repetive day(1-3day)
	for (day = 1; day <= NUMS; day++) {
		do {
			printf("\nEnter the high value for day %d: ", day);  //display and prompt the user enter
			scanf("%d", &high[day - 1]);  //input
			printf("\nEnter the low value for day %d: ", day); //display amd prompt the user enter
			scanf("%d", &low[day - 1]); //input
								 //checking condition

			if (high[day - 1] < low[day - 1] || high[day - 1] > 40 || low[day - 1] < -41) {
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");//display wrong messages
			}
			//checking conditon


		} while (high[day - 1] < low[day - 1] || high[day - 1] > 40 || low[day - 1] < -41);
	}

	highest = high[0]; //declear highest to store highest temperture
	    //checking condition
	for (i = 0; i < NUMS; i++) {
		totalhigh = high[i] + totalhigh;  //calulate total high
		totallow = low[i] + totallow;      //calcuate total low
	}

	lowest = low[0];   //declear to store lowest temperture
	  //checking condition
	for (j = 0; j < NUMS; j++) {
		if (highest < high[j])  // to store
		{
			highest = high[j];
			highday = j + 1;
		}
	}
	   //checking condition
	for (k = 0; k < NUMS; k++)
		if (lowest > low[k])
		{
			lowest = low[k];
			lowday = k + 1;
		}

	highaverage = (double)totalhigh / NUMS;   // calcuate high average
	lowaverage = (double)totallow / NUMS;    //calcuate low average
	average = (double)(totalhigh + totallow) / (NUMS * 2);  //calcuate average of total high and totlal low temperture

	printf("\nThe average (mean) LOW temperature was: %.2lf", lowaverage);   //output results
	printf("\nThe average (mean) HIGH temperature was: %.2lf", highaverage);
	printf("\nThe average (mean) temperature was: %.2lf", average);
	printf("\nThe highest temperature was %d, on day %d", highest, highday);
	printf("\nThe lowest temperature was %d, on day %d\n", lowest, lowday);


	return 0;
}