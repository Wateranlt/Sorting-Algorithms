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
	static void insertionSort(int array[], size_t n);
	static void SelectionSort(int array[], size_t n);
	static void BubbleSort(int array[], size_t n);
	static void QuickSort(int array[],int low, int n);
	//Heap Sort
	//Radix Sort
	//shell sort
	//Cocktail Shaker Sort
	//Gnome Sort
	//Bitonic Sort
	//Bogo Sort
};

#endif // !1