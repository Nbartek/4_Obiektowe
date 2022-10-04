#include <cstdlib>
#include <iostream>
#include <ctime>
#include <array>
#include <string>
#pragma once
using namespace std;
class sentinel
{
private:
	int length;
	int *arr;
public:
	sentinel(int length) {
		this->length = length;
		arr = new int[length+1];
		fillArr(); 
		displayArr();
	}
	void sentinelSearch(int searchedItem) {
		arr[length+1] = searchedItem;
		int i = 0;
		while (arr[i] != searchedItem)
			i++;

		if (i == length+1) {
			cout << "Nie znaleziono szukanej liczby:(" << endl;
		}
		else {
			cout << "Znaleziono szukana liczbe na miejscu " << i << endl;
		}
	}
private:
	void fillArr() {
		srand(NULL);
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = ((rand() % 100)+1);
		}
	}

	void displayArr() {
		for (size_t i = 0; i < length; i++)
		{
			cout << "Na miejscu " << i << " jest " << arr[i] << endl;
		}
	}
};

