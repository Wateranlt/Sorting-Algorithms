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
	COUNTING = 5,
	RADIX = 6,
	COCKTAIL = 7,
	GNOME = 8,
	HEAP = 9,
	BITONIC = 10,
	MERGE = 11,
	BOGO = 12
};
	void setup(int array[], size_t n);
	void visualize(ALGO);
	void insertionSort();
	void selectionSort();
private:
	sf::RenderWindow* window;
	sf::Event ev;
	int* array;
	size_t n;
	void render(size_t currentPos, size_t k);


};

#endif