#pragma once
#include <stdio.h>
#include <stdlib.h>

int checkIsSortedRecursive(int* arr, int size) {
	// Checking if the array is sorted by using a recursive function that "splits" the array 
	// The goal is to learn how to use recursive functions even though for this example the brute force approach would be more efficient

	int result;
	if (size == 1) return 1; // If there is only one element in the array, it is sorted

	result = checkIsSortedRecursive(arr, size - 1); // Here starts the recursion. It keeps going until size equals to 1

	if (result && arr[size - 1] < arr[size - 2]) return 0;

	return result;
}

void reverseArrayRecursive(int* arr, int size) {
	// A recursive function to reverse the array in place
	// It swaps the outer elements and then recursively processes the subarray in between

	if (size > 1) {
		int tmp;
		// arr[0] refers to the first element of the current subarray
		// In each recursive call, arr is incremented (arr + 1), so arr[0] moves one element forward
		tmp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = tmp;

		// Move the pointer forward and reduce the size by 2 to focus on the inner subarray
		reverseArrayRecursive(arr + 1, size - 2);
	}
}


int isPalindromeRecursive(int* arr, int size) {
	// A recursive function to check if the array is a palindrome or not
	// The function is not more efficient that comparing the values in a for-loop e. g. The purpose is to learn how to use recursive functions

	if (size <= 1) return 1; // If size <= 1 is reached, we know that the array is a palindrome since return 0 was never called

	if (arr[0] != arr[size - 1])
		return 0;

	return isPalindromeRecursive(arr + 1, size - 2); //The return keyword gives a value back to the caller, so the result can be used or passed on
}

int checkIfOppositeNeighborRecursive(int* arr, int size) {
	// Recursively checks if all adjacent elements have opposite signs

	if (size == 1) return 1; // If we reach this statement, we know that all adjacent elements have opposite signs

	if ((arr[0] < 0 && arr[1] < 0) || (arr[0] > 0 && arr[1] > 0)) return 0;
	// Alternative statement: if(arr[0] * arr[1] >= 0) return 0;

	return checkIfOppositeNeighborRecursive(arr + 1, size - 1);
}

int findAdjacentSum(int* arr, int size) {
	// Finds the highest sum of two adjacent elements in the array

	// Base case: if only two elements left, return their sum
	if (size == 2) return arr[0] + arr[1];

	int currentSum;
	int currentMaxSum;

	currentSum = arr[0] + arr[1];
	currentMaxSum = findAdjacentSum(arr + 1, size - 1);

	// Return the greater of the current sum and the max sum of the rest
	if (currentMaxSum > currentSum) return currentMaxSum;
	else return currentSum;
}

void printArrFromLeft(int* arr, int size) {
	// A recursive function to print an array from the left most value

	if (size == 0) return; // Base case: stop recursion when size is 0

	printf("%i, ", *arr);
	printArrFromLeft(arr + 1, size - 1);

}

void printArrFromRight(int* arr, int size) {
	// A recursive function to print an array from the rightmost value

	if (size == 0) return;

	printArrFromRight(arr + 1, size - 1);
	printf("%i, ", arr[0]);
}

float countAverage(int* arr, int size) {
	// Find the average of an array using recusrive function

	float avgSoFar;

	if (size == 1) return arr[0]; // Base case: if there is only 1 element in the array, this element is the average

	avgSoFar = countAverage(arr + 1, size - 1);

	return (avgSoFar * (size - 1) + arr[0]) / size; // The formula we need to calculate the average using the recursive function

}

int isSpecialSort(float* arr, int size) {
	// Recursive function to check if the integer part of the array is in ascending order and the fractional part in descending order
	// The numbers in the array should be > 0

	if (size <= 1) return 1;

	if ((int)arr[0] >= (int)arr[1] || arr[0] - (int)arr[0] <= arr[1] - (int)arr[1]) return 0;

	// Recursion
	return isSpecialSort(arr + 1, size - 1);
}

void convertToBinary(int n) {
	// Convert decimal to binary

	if (n == 0) return;

	convertToBinary(n / 2);

	printf("%i", n % 2);
	// If we placed the print function before the recursive call, the binary number would be printed in reverse order
}
