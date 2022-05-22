#pragma once
#ifndef VISUALIZER_H_INCLUDED
#define VISUALIZER_H_INCLUDED
#include "SFML/Graphics.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 600
class Visualizer
{
public:

enum class ALGO
{
	INSERT = 0,
	SELECTION = 1,
	BUBBLE = 2,
	QUICKSORT = 3,
	SHELL = 4,
	RADIX = 5,
	COCKTAIL = 6,
	GNOME = 7,
	HEAP = 8,
	BITONIC = 9,
	MERGE = 10,
	BOGO = 11
};
	void setup(int array[], size_t n);
	void visualize(ALGO algo);
	void insertionSort();
	void selectionSort();
	void bubbleSort();
	void cokctailShakerSort();
	void shellSort();
	void gnomeSort();
	void quickSort(int low, int n);
	void radixSort();
private:
	sf::RenderWindow* window;
	int* array;
	size_t n;
	void countingSort(int digit);
	void render(size_t currentPos, size_t k = 0);


};

#endif