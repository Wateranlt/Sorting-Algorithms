#include <iostream>
#include "Sorting Algorithms.h"
#include "Visualizer.h"

int main(int args, char** argv)
{
	int *array1 = SortingAlgorithms::randomGenerator(10);
	SortingAlgorithms::printList(array1, 10);
	SortingAlgorithms::radixSort(array1, 10);
	SortingAlgorithms::printList(array1, 10);
	return 0;
}
