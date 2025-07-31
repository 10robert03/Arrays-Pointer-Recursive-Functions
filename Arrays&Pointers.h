#pragma once
#include <stdlib.h>
#include <stdio.h>


int sumArray(int* arr, int size) {//*ptr pointer to first element in array. grades is also a ptr to the first element in the array

	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i]; // The same as grades[i] or arr[i]
	}

	return sum;
}

int searchElement(int* arr, int size, int value) {

	for (int i = 0; i < size; i++) {
		if (*(arr + i) == value) return 1;
	}
	return 0;
}

int findmax(int* arr, int size) {

	if (size <= 0) return -1235;
	// Check if size > 0, so we can iterate. -1235 is an error message because the highest value might be 0

	int max = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) > max) max = arr[i];
	}

	return max;
}

float calcAvg(int* arr, int size) {
	float sum = (float)sumArray(arr, size);
	return sum / size;
}

void inputArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("Put in your %i. number: \n", i + 1);
		scanf("%i", &arr[i]); // scanf wants an address where it can store the value
	}
}

void displayArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%i, ", *(arr + i));
	}
	printf("\n");
}

void findMinMaxByReference(int* max, int* min, int* arr, int size) { // Find the maximum and minimum in an array by reference
	for (int i = 1; i < size; i++) {
		if (arr[i] > *max) *max = arr[i];
		if (arr[i] < *min) *min = arr[i];
	}
}

void updateAvg(int* n1, int* n2, float* avg) {
	*avg = (*n1 + *n2) / 2.0;
}

int positiveNeighbors(int* arr, int size) {
	// Check if there is a number which equals the sum of the two numbers next to it

	for (int i = 1; i < size - 1; i++) {
		if (arr[i - 1] + arr[i + 1] == arr[i]) return 1;
	}
	return 0;
}

int checkIsSortedBF(int* arr, int size) {
	// Brute force algorithm to check if the array is sorted

	for (int i = 1; i < size; i++) {
		if (arr[i - 1] > arr[i]) return 0;
	}

	return 1;
}


void reverseArray(int* arr, int size) {
	// A function to reverse the given array with a brute force algorithm

	int j = size - 1;
	int tmp;
	for (int i = 0; i < size / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		j--;
	}
}


void countFrequencyOfElement(int* arr, int size) {
	int* checked = (int*)calloc(size, sizeof(int));
	// Checks if the element was already counted and initializes the array with zeros
	// Assumes that the input array does not contain zero as a valid value
	// If zeros are allowed in the input, we should use a different marker value (e.g., -1)

	for (int i = 0; i < size; i++) {
		if (checked[i]) continue; // Already counted

		int count = 1;
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				count++;
				checked[j] = 1; // Mark as counted
			}
		}

		if (count > 1) printf("Value %i appears %i times\n", arr[i], count);
		else printf("Value %i appears once\n", arr[i]);
	}
}

int getSecondSmallestNum(int* arr, int size) {

	int num = 100; // A random high number which we know is greater than at least one value in the array
	int result = 100; // I assume that 100 is not the smallest number in the array, if you want to be safe use "__INT_MAX__" from the limits.h library
	// num will be the smallest number. We need it for comparison later. result will be the actual result we want in the end

	for (int i = 0; i < size; i++) {
		if (arr[i] < num) {
			num = arr[i]; // Get the lowest number, so we can skip it in the next for-loop
		}
	}

	for (int j = 0; j < size; j++) {
		if (arr[j] == num) continue;

		if (arr[j] < result) result = arr[j];
	}

	if (result == 100) return num; // If there is no second smallest number, return the smallest number 
	return result;
}

int findSumValueBF(int* arr, int* index1, int* index2, int size, int value) {
	// The function should find if there is a sum of two numbers that equals to the given value
	// If so it should return 1 and pass the indexes 
	// This is a brute force version of the function
	// We do not care, if there are multiple sums which are equal to the value, we just want one pair

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] + arr[j] == value) {
				*index1 = i;
				*index2 = j;
				return 1;
			}
		}
	}


	*index1 = 0;
	*index2 = 0;
	// If there is no sum equal to the given value, the indexes are set to 0

	return 0;
}

int findSumValueOptimized(int* arr, int size, int* index1, int* index2, int value) {
	// The given array needs to be a sorted array for this function to work
	// Depending on the size of the array it might be worth to sort the array instead of doing a brute force search


	int j = size - 1;
	int i = 0;
	while (i < j) {
		if (arr[i] + arr[j] == value) {
			*index1 = i;
			*index2 = j;
			return 1;
		}
		else if (arr[i] + arr[j] > value) j--;
		else if (arr[i] + arr[j] < value) i++;
	}

	*index1 = 0;
	*index2 = 0;
	return 0;
}

int* createArray(int* size) {
	// We need the size for later to iterate through the array

	printf("Enter the size of your array:\n");
	scanf("%i", size);

	int* arr = (int*)malloc(*size * sizeof(int)); // Allocate memory for the array 
	if (!arr) return NULL; // Test for errors

	for (int i = 0; i < *size; i++) {
		printf("Enter the %i. number of the array: \n", i + 1);
		scanf("%i", &arr[i]); // Fill the array with the values given by the user
	}

	return arr;
}


