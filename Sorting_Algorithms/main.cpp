#include <iostream>
#include "Sorting Algorithms.h"

int main(int args, char** argv)
{
	int *array1 = SortingAlgorithms::randomGenerator(10);
	SortingAlgorithms::QuickSort(array1,0,10);
	SortingAlgorithms::printList(array1, 10);
	return 0;
}
