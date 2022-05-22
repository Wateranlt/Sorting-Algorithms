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

void Visualizer::visualize(Visualizer::ALGO algo)
{
	switch (algo)
	{
	case Visualizer::ALGO::INSERT:
		insertionSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::SELECTION:
		selectionSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::BUBBLE:
		bubbleSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::QUICKSORT:
		quickSort(0, n);
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::SHELL:
		shellSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::RADIX:
		radixSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::COCKTAIL:
		cokctailShakerSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::GNOME:
		gnomeSort();
		sf::sleep(sf::seconds(2));
		window->close();
		break;
	case Visualizer::ALGO::HEAP:
		break;
	case Visualizer::ALGO::BITONIC:
		break;
	case Visualizer::ALGO::MERGE:
		break;
	case Visualizer::ALGO::BOGO:
		break;
	default:
		break;
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
			window->clear();
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
}

void Visualizer::bubbleSort()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n - i - 1; j++)
		{
			window->clear();
			if (array[j] > array[j + 1])
				SortingAlgorithms::swap(array + j, array + j + 1);
			render(i, j + 1);
			window->display();
			sf::sleep(sf::milliseconds(10));
		}
	}
}

void Visualizer::cokctailShakerSort()
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (size_t j = 0; j < n - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				window->clear();
				SortingAlgorithms::swap(array + j, array + j + 1);
				render(j, j + 1);
				window->display();
				sf::sleep(sf::milliseconds(50));
				swapped = true;
			}
		}
		for (int u = n - 2; u != -1; u--) // using int since we cannot compare a size_t with a negative number
		{
			if (array[u + 1] < array[u])
			{
				window->clear();
				SortingAlgorithms::swap(array + u, array + u + 1);
				render(u + 1, u);
				window->display();
				sf::sleep(sf::milliseconds(50));
				swapped = true;
			}
		}
	} while (swapped);
}

void Visualizer::shellSort()
{
	for (int i = n / 2; i > 0; i /= 2)
	{
		for (size_t j = i; j < n; j++)
		{
			for (int k = j; array[k] < array[k - i] && k - i >= 0; k -= i)
			{
				window->clear();
				SortingAlgorithms::swap(array + k, array + k - i); // Moving number while it is possible 
				render(k, k - i); //TODO : Improve render function for earch sorting function
				window->display();
				sf::sleep(sf::milliseconds(50));
			}
		}
	}
}

void Visualizer::gnomeSort()
{
	int i = 0;
	do
	{
		window->clear();
		if (i == 0)
			i++;
		if (array[i] > array[i - 1])
			i++;
		else
		{
			SortingAlgorithms::swap(array + i, array + i - 1);
			i--;
		}
		render(i, i - 1);
		window->display();
		sf::sleep(sf::milliseconds(50));
	} while (i != n - 1);
}

void Visualizer::quickSort(int low, int n)
{
	int min = low - 1; // Index of first number bigger than pivot which is array[n]
	if (low < n - 1) // when array size is greater than 1 --> As n and low are indexes, we count them from zero but n wasn't offseted (n = 10 and not 9) so we substract one to make the comparison logical  
	{
		for (int i = low; i < n - 1; i++)
		{
			if (array[i] < array[n - 1])
			{
				window->clear();
				min++;
				SortingAlgorithms::swap(array + i, array + min); // Adding the number to the left of the minIndex number
				render(n - 1, i);
				window->display();
				sf::sleep(sf::milliseconds(50));
			}
		}
		SortingAlgorithms::swap(array + min + 1, array + n - 1); // Swapping our pivot with the index plus one since array[min] is greater than the pivot
		Visualizer::quickSort(low, min + 1); // quicksort left-side : we added 1 to min to cancel the offset done at line 65
		Visualizer::quickSort(min + 1, n);// Quicksorting right-side : same thing concerning the "+ 1
	}
}

void Visualizer::countingSort(int digit)
{
	int power = (int)std::pow(10, digit), powerLess = (int)std::pow(10, digit - 1), temp1 = 0, temp2 = 0;
	int* count = new int[n + 1], * output = new int[n];
	memset(count, 0, (n + 1) * sizeof(int));
	memset(output, 0, n * sizeof(int));

	for (size_t i = 0; i < n; i++)
	{
		window->clear();
		count[array[i] % power / powerLess]++;
		render(i);
		window->display();
		sf::sleep(sf::milliseconds(50));
	}
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
	{
		window->clear();
		array[i] = output[i];
		render(i);
		window->display();
		sf::sleep(sf::milliseconds(50));
	}
}

void Visualizer::radixSort()
{
	int max = *(std::max_element(array, array + n)), maxDivision = 0;
	for (maxDivision = 1; max % (int)std::pow(10, maxDivision) != max; maxDivision++);
	for (size_t i = 1; i <= maxDivision; i++)
		countingSort(i);
}
