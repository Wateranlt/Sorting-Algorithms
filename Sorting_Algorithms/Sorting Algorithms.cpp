#include "Sorting Algorithms.h"
#include <iostream>

void SortingAlgorithms::printList(int array[], size_t n)
{
	std::cout << "{";
	for (auto i = 0; i < n - 1; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << array[n - 1] << "}" << std::endl;
}


void SortingAlgorithms::swap(int* var1, int* var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

int* SortingAlgorithms::randomGenerator(size_t n)
{
	srand(time(0));
	int* resultArray = new int[10];
	for (size_t i = 0; i < n; i++)
	{
		resultArray[i] = rand() % 100;
	}
	return resultArray;
}

void SortingAlgorithms::insertionSort(int array[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; array[j] < array[j - 1]; j--)
		{
			swap(array + j, array + j - 1);
		}
	}
	printList(array, n);
}

void SortingAlgorithms::SelectionSort(int array[], size_t n)
{
	int minIndex = 0;
	for (size_t i = 0; i < n; i++)
	{
		minIndex = i;
		for (size_t j = i; j < n; j++)
		{
			if (array[minIndex] > array[j])
				minIndex = j;
		}
		swap(array + i, array + minIndex);
	}
	printList(array, n);
}

void SortingAlgorithms::BubbleSort(int array[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (array[j] > array[j + 1])
				swap(array + j, array + j + 1);
		}
	}
	printList(array, n);
}

void SortingAlgorithms::QuickSort(int array[], int low, int n)
{
	int min = low - 1; // Index of first number bigger than pivot which is array[n]
	if (low < n - 1) // when array size is greater than 1 --> As n and low are indexes, we count them from zero but n wasn't offseted (n = 10 and not 9) so we substract one to make the comparison logical  
	{
		for (int i = low; i < n - 1; i++)
		{
			if (array[i] < array[n - 1])
			{
				min++;
				swap(array + i, array + min); // Adding the number to the left of the minIndex number
			}
		}
		swap(array + min + 1, array + n - 1); // Swapping our pivot with the index plus one since array[min] is greater than the pivot
		SortingAlgorithms::QuickSort(array, low, min + 1); // quicksort left-side : we added 1 to min to cancel the offset done at line 65
		SortingAlgorithms::QuickSort(array, min + 1, n);// Quicksorting right-side : same thing concerning the "+ 1"
		std::cout << "Array : ";
		printList(array, n);
	}
}
