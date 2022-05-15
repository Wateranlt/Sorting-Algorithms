#include <iostream>
#include "Sorting Algorithms.h"
#include "Visualizer.h"
#define LENGTH 15

int main(int args, char** argv)
{
	int *array1 = SortingAlgorithms::randomGenerator(LENGTH);
	SortingAlgorithms::printList(array1, LENGTH);
	SortingAlgorithms::cocktailShakerSort(array1, LENGTH);
	SortingAlgorithms::printList(array1, LENGTH);
	return 0;
}
