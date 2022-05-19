#include <iostream>
#include "Sorting Algorithms.h"
#include "Visualizer.h"

int main(int args, char** argv)
{
	Visualizer wind;
	int* array1 = SortingAlgorithms::randomGenerator(LENGTH);
	wind.setup(array1, LENGTH);
	wind.visualize(Visualizer::ALGO::QUICKSORT);
	// ------------------------------------------------
	/*SortingAlgorithms::shellSort(array1, LENGTH);
	SortingAlgorithms::printList(array1, LENGTH);
	Analysing shellSort, which is currently not working*/
	return 0;
}
