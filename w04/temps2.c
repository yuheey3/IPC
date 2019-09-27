//--------------------------------------------------
// Name:           YUKI WAKA
// Student Number: 141082180
// Date:           Feb.11
// Email:          YWAKA@myseneca.ca
// Section:        SJJ
// Workshop:       4 (at-home)
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 10

int main(void)
{
	int i, j, k, s, y;
	int Hi[NUMS], Low[NUMS];
	int day;
	int highest, lowest;
	int highday, lowday;
	double average;
	int totalhigh, totallow;


	// Put your code below:
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);

	if (day < 3 || day > 10) {
		while (1) {
			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &day);

			if (day >= 3 && day <= 10)

				break;
		}
	}

	printf("\n");
	for (j = 1; j <= day; j++) {
		printf("Day %d - High: ", j);
		scanf("%d", &Hi[j - 1]);
		printf("Day %d - Low: ", j);
		scanf("%d", &Low[j - 1]);
	}

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < day; i++) {
		printf("%d    %d    %d\n", i + 1, Hi[i], Low[i]);

	}

	highest = Hi[0];
	for (k = 0; k < day; k++) {
		if (highest < Hi[k])
		{
			highest = Hi[k];
			highday = k + 1;
		}
	}
	lowest = Low[0];
	for (s = 0; s < day; s++) {
		if (lowest > Low[s])
		{
			lowest = Low[s];
			lowday = s + 1;
		}
	}

	printf("\nThe highest temperature was %d, on day %d", highest, highday);
	printf("\n");
	printf("The lowest temperature was %d, on day %d", lowest, lowday);
	printf("\n");

	do {
		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &day);

		while (day > 5 || day == 0) {
			printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &day);
		}

		totalhigh = totallow = 0;

		if (day >= 1 && day <= 5) {
			for (y = 0; y < day; y++) {
				totalhigh += Hi[y];
				totallow += Low[y];
			}
			average = (double)(totalhigh + totallow) / (day * 2);
			printf("\nThe average temperature up to day %d is: %.2lf\n", day, average);
		}
		else {
			printf("\nGoodbye!\n");
			break;
		}
	} while (day >= 1 && day <= 5);

	return 0;
}