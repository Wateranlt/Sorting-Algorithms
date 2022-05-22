#include <iostream>
#include "Sorting Algorithms.h"
#include "Visualizer.h"

int main(int args, char** argv)
{
	Visualizer wind;
	int* array1 = SortingAlgorithms::randomGenerator(LENGTH);
	SortingAlgorithms::printList(array1, LENGTH);
	wind.setup(array1, LENGTH);
	wind.visualize(Visualizer::ALGO::SHELL);
	return 0;
}
