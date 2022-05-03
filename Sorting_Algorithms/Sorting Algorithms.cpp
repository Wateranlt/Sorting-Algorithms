#include "Sorting Algorithms.h"
#include <iostream>

void SortingAlgorithms::printList(int array[], size_t n)
{
	std::cout << "{";
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << array[n - 1] << "}" << std::endl;
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

void SortingAlgorithms::SelectionSort(int array[], size_t n)
{
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		minIndex = i;
		for (int j = i; j < n; j++)
		{
			if (array[minIndex] > array[j])
				minIndex = j;
		}
		swap(array[i], array[minIndex]);
	}
	printList(array, n);
}

void SortingAlgorithms::BubbleSort(int array[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
	printList(array, n);
}
