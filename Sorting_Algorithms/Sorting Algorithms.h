#pragma once
#ifndef SORTALGO_H_DEFINED
#define SORTALGO_H_DEFINED

#include <stdlib.h>

class SortingAlgorithms
{
public:
	static void printList(int array[], size_t n);
	static void swap(int* var1, int* var2);
	static int* randomGenerator(size_t n);
	static bool isSorted(int array[], size_t n);
	static void insertionSort(int array[], size_t n);
	static void selectionSort(int array[], size_t n);
	static void bubbleSort(int array[], size_t n);
	static void quickSort(int array[],int low, int n);
	static void shellSort(int array[], size_t n);
	static void countingSort(int array[], size_t n, int digit);
	static void radixSort(int array[], size_t n);
	static void cocktailShakerSort(int array[], size_t n);
	static void gnomeSort(int array[], size_t n);
	//Bitonic sort
	//Heap Sort
	//mergeSort
	//Bogo Sort
};

#endif // !1