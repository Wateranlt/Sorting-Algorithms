#include "Sorting Algorithms.h"
#include <iostream>

void SortingAlgorithms::printList(int array[], size_t n)
{
	std::cout << "{";
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << array[n - 1] << "}";
}


void SortingAlgorithms::swap(int& var1, int& var2)
{
	int temp = var1;
	var1 = var2;
	var2 = temp;
}

void SortingAlgorithms::insertionSort(int array[], size_t n)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i; array[j] < array[j - 1]; j--)
		{
			swap(array[j], array[j - 1]);
		}
	}
	printList(array, n);
}