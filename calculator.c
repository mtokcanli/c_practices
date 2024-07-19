#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	float* storedValue = NULL;
	char firstValue[100];
	char* secondValue[100];
	*secondValue = (char*)malloc(sizeof(char[100]));
	int op;
	char str[] = "Result : %f";
	do{
		printf("Example: 500 -1000\n");
		if (storedValue == NULL) {
			printf("Enter first value:\n");
			scanf_s("%s", &firstValue, (unsigned)100);
			if (strcmp(firstValue, "q") == 0)
				break;
			printf("Enter second value:\n");
			scanf_s("%s", *secondValue, (unsigned)100);
		}
		else {
			printf("Enter a value: \n");
			scanf_s("%s", &firstValue, (unsigned)100); // _countof(firstValue) || 100 
		}
		printf("If you want to quit from program type \"q\"");
		printf("Select an operation: 1:+\n2:-\n3:*\n4:/\n\n");
		scanf_s("%d", &op);
		switch (op)
		{
		case 1:
			if (storedValue == NULL) {
				storedValue = malloc(sizeof(float));
				*storedValue = (strtof(firstValue, NULL) + strtof(*secondValue, NULL));
				printf_s(str, (*storedValue));
				break;
			}
			printf_s(str, (*storedValue + strtof(firstValue, NULL)));
			break;
		case 2:
			if (storedValue == NULL) {
				storedValue = malloc(sizeof(float));
				*storedValue = (strtof(firstValue, NULL) - strtof(*secondValue, NULL));		
				printf_s(str, (*storedValue));
				break;
			}
			printf_s(str, (*storedValue - strtof(firstValue, NULL)));
			break;
		case 3:
			if (storedValue == NULL) {
				storedValue = malloc(sizeof(float));
				*storedValue = (strtof(firstValue, NULL) * strtof(*secondValue, NULL));
				printf_s(str, (*storedValue));
				break;
			}
			printf_s(str, (*storedValue * strtof(firstValue, NULL)));
			break;
		case 4:
			if (storedValue == NULL) {
				storedValue = malloc(sizeof(float));
				*storedValue = (strtof(firstValue, NULL) / strtof(*secondValue, NULL));
				printf_s(str, (*storedValue));
				break;
			}
			printf_s(str, (*storedValue / strtof(firstValue, NULL)));
			break;
		default:
			printf("Undefined operation.");
			break;
		}
		if (secondValue != NULL && storedValue != NULL) {
			for(int i =0; i < 100;i++ )
			{
				//printf("Value: %c\n", (char)secondValue[i]);
				if (strcmp(secondValue[i], "") == 0)
					break;
				free(secondValue[i]);
			}
			//secondValue = NULL;
		}
	} while (strcmp("q", firstValue)!=0);
	
	return 0;
}
