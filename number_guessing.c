#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int generateRandomInt(int maxValue, int minValue) {
	srand((unsigned int) time(NULL));
	return (int)((rand() % (maxValue - minValue + 1)) + minValue);
}


int main() {
	int value = generateRandomInt(100, 0),
		chances = 5,
		userInput;
	while (chances != 0) {
		printf("Guess the number:");
		scanf_s("%d", &userInput);
		chances--;
		if (userInput != value)
			continue;
		else
			break;
	}
	if (value == userInput)
		printf("Congratulations, you've guessed the number!");

	else
		printf("You couldn't guess the number! The number was %d ", value);
	return 0;
}
