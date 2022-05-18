#include <iostream>
#include "Sorting Algorithms.h"
#include "Visualizer.h"

int main(int args, char** argv)
{
	Visualizer wind;
	int* array1 = SortingAlgorithms::randomGenerator(LENGTH);
	wind.setup(array1, LENGTH);
	wind.visualize(Visualizer::ALGO::INSERT);
	return 0;
}
