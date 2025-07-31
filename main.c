#include <stdlib.h>
#include <stdio.h>
#include "RecursiveFuncs.h"
#include "Arrays&Pointers.h"


/*
	The goal is learning and understanding the basics of pointers arrays and recursive functions
	like pointer arithmetic by creating some functions with pointers / arrays as parameters.
*/

/*
	Example for how to use a pointer:
	int x=42;
	int *ptr = &x;
	--> *ptr = 42, ptr = address of x, &ptr = address of ptr

	Use &x if you use a function with a pointer as a parameter. You will work with the original x, not a copy
*/

int main() {

	int grades[] = { 2, 1, 6, 5, 2, 1, 4 };

	int result = searchElement(grades, 4, 6);
	printf("%i\n", result);

	int max = findmax(grades, 4);
	printf("%i\n", max);
	float avg = calcAvg(grades, 4);
	printf("%.2f\n", avg);

	int min = grades[0];
	int maximum = grades[0];
	findMinMaxByReference(&maximum, &min, grades, 4);
	printf("Min: %i, Max: %i\n", min, maximum);

	printf("Enter 2 Values:\n");
	int n1;
	int n2;
	scanf("%i", &n1);
	scanf("%i", &n2);
	float average;
	updateAvg(&n1, &n2, &average);
	printf("%.2f\n", average);

	int arr[] = { 2,5,7,9,67 };
	int check = checkIsSortedRecursive(grades, 4);
	printf("%i\n", check);

	reverseArrayRecursive(arr, 5);
	displayArray(arr, 5);


	countFrequencyOfElement(grades, 7);

	int secondSmallestNumber = getSecondSmallestNum(grades, 7);
	printf("Second smallest number: %i\n", secondSmallestNumber);

	int index1;
	int index2;
	int equalSum = findSumValueBF(grades, &index1, &index2, 7, 8);
	printf("Index 1: %i, Index 2: %i, True?: %i\n", index1, index2, equalSum);

	int sortedArr[] = { 1,3,4,6,8,12 };
	int index3;
	int index4;
	int equalSum2 = findSumValueOptimized(sortedArr, 6, &index3, &index4, 7);
	printf("Index 1: %i, Index 2: %i, True?: %i\n", index3, index4, equalSum2);

	int size2;
	int* arr2 = createArray(&size2);
	displayArray(arr2, size2);
	free(arr2); // You need to use free if you have used malloc, calloc or realloc to avoid memory leaks

	int palArr[] = { 1,2,3,3,2 };
	int isPalindrome = isPalindromeRecursive(palArr, 5);
	printf("True?: %i\n", isPalindrome);

	int neighbors[] = { 1,-3,2,-5,9 };
	int opposite = checkIfOppositeNeighborRecursive(neighbors, 5);
	printf("True?: %i\n", opposite);

	int maxSum = findAdjacentSum(grades, 7);
	printf("Max Adjacent Sum: %i\n", maxSum);

	printArrFromLeft(grades, 7);
	printf("\n");
	printArrFromRight(grades, 7);
	printf("\n");

	float arrAvg = countAverage(grades, 7);
	printf("Average: %.2f\n", arrAvg);

	float floatArray[] = { 1.5,2.3,3.1 };
	int specialSort = isSpecialSort(floatArray, 3);
	printf("Is the array sorted?: %i\n", specialSort);

	convertToBinary(100000);
	printf("\n");
}
