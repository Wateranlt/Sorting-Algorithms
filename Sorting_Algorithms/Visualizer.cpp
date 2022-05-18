#include "Visualizer.h"
#include <SFML/Graphics.hpp>
#include "Sorting Algorithms.h"
#include <iostream>

void Visualizer::setup(int array[], size_t n)
{
	 window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);
	 this->array = new int[n];
	 for (size_t i = 0; i < n; i++)
		 this->array[i] = array[i];
	 this->n = n;
}

void Visualizer::visualize(Visualizer::ALGO)
{

	while (window->isOpen())
	{
		while (window->pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			default:
				break;
			}
		}
		selectionSort();
	}
}

void Visualizer::render(size_t currentPos, size_t k)
{
	sf::RectangleShape rect(sf::Vector2f(0, 0));
	int x = 0;
	for (size_t i = 0; i < n; i++)
	{
		x +=10;
		if (i == k)
			rect.setFillColor(sf::Color::Red);
		else if (i == currentPos)
			rect.setFillColor(sf::Color::Green);
		else
			rect.setFillColor(sf::Color::White);
		rect.setPosition(sf::Vector2f(x, WINDOW_HEIGTH));
		rect.setSize(sf::Vector2f(10, -array[i] * 5));
		window->draw(rect);
		x += 2;
	}
}

void Visualizer::insertionSort()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; array[j] < array[j - 1]; j--)
		{
			window->clear();
			SortingAlgorithms::swap(array + j, array + j - 1);
			render(i, j - 1);
			window->display();
			sf::sleep(sf::milliseconds(50));
		}
	}
	sf::sleep(sf::seconds(2));
	window->close();
}

void Visualizer::selectionSort()
{
	int minIndex = 0;
	for (size_t i = 0; i < n; i++)
	{
		window->clear();
		minIndex = i;
		for (size_t j = i; j < n; j++)
		{
			if (array[minIndex] > array[j])
				minIndex = j;
			render(i, minIndex);
			window->display();
			sf::sleep(sf::milliseconds(10));
		}
		SortingAlgorithms::swap(array + i, array + minIndex);
		render(i, minIndex);
		window->display();
		sf::sleep(sf::milliseconds(50));
	}
	sf::sleep(sf::seconds(2));
	window->close();
}

