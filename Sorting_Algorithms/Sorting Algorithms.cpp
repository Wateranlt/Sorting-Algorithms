#include "Sorting Algorithms.h"
#include <iostream>
#include <algorithm>
#include <cmath>

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
}

void SortingAlgorithms::selectionSort(int array[], size_t n)
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
}

void SortingAlgorithms::bubbleSort(int array[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (array[j] > array[j + 1])
				swap(array + j, array + j + 1);
		}
	}
}

void SortingAlgorithms::quickSort(int array[], int low, int n)
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
		SortingAlgorithms::quickSort(array, low, min + 1); // quicksort left-side : we added 1 to min to cancel the offset done at line 65
		SortingAlgorithms::quickSort(array, min + 1, n);// Quicksorting right-side : same thing concerning the "+ 1"
	}
}

void SortingAlgorithms::shellSort(int array[], size_t n)
{
	for (size_t i = n / 2; i > 0; i /= 2)
	{
		for (size_t j = i; j < n; j++)
		{
			for (size_t k = j; array[k] < array[k - i] && k - i > 0; k -= i)
			{
				swap(array + k, array + k - i); // Moving number while it is possible 
			}
		}
	}
}

void SortingAlgorithms::countingSort(int array[], size_t n, int digit)
{
	int power = (int)std::pow(10, digit), powerLess = (int)std::pow(10, digit - 1), temp1 = 0, temp2 = 0;
	int *count = new int[n + 1], *output = new int[n];
	memset(count, 0, (n+ 1) * sizeof(int));
	memset(output, 0, n * sizeof(int));

	for (size_t i = 0; i < n; i++)
		count[array[i] %  power / powerLess]++;
	for (size_t i = 1; i < n; i++)
		count[i] += count[i - 1];
	temp1 = count[0];
	count[0] = 0;
	for (size_t i = 1; i < n; i++)
	{
		temp2 = count[i];
		count[i] = temp1;
		temp1 = temp2;
		
	}

	for (int i = 0; i < n; i++)
	{
		output[count[array[i] % power / powerLess]] = array[i];
		++count[array[i] % power / powerLess];
	}
	for (size_t i = 0; i < n; i++)
		array[i] = output[i];
}

void SortingAlgorithms::radixSort(int array[], size_t n)
{
	int max = *(std::max_element(array, array + n)), maxDivision = 0;
	for (maxDivision = 1; max % (int)std::pow(10, maxDivision) != max; maxDivision++);
	for (size_t i = 1; i <= maxDivision; i++)
		countingSort(array, n, i);
}
