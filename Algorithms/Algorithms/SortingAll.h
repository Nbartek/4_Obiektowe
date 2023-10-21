#pragma once
#include <time.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
class SortingAll {
	int array[100];
	int length = 100;
public:
	void setLen(int n) {
		length = n;
	}
	void fillRandom() {
		srand(time(NULL)); 
		for (int i = 0; i < length; i++)
		{
			array[i] = (rand() % 100) + 1;
		}
	}
	void InsertionSort() {
		for (size_t i = 1; i < length; i++) //Petla idąca po każdym indexie w tablicy
		{
			int temp = array[i]; // ustawiamy teraźniejszą liczbę z tablicy jako temp
			int j = i - 1; //ustawiamy j na mniejsze od i, while idzie do tyłu, żeby nie zaczynał od terazniejszej liczby z tablicy
			while (j >= 0 && array[j] > temp){ //musi  byc wieksze lub równe, sprawdzamy czy teraźniejsza liczba jest mniejsza od liczby rotacyjnej z while-a
					array[j + 1] = array[j]; //jeśli tak; liczbę o 1 index większą od rotacyjnej ustawiamy na miejsce liczby rotacyjnej 
					//iter 1: np 17,56,9... a temp to arr[2] czyli 9 a j to 1 -> 17,56,56...
					//iter 2: 17,56,56... temp to dalej 9 a j to teraz 0 -> 17>9 czyli 17,17,56...
					j = j - 1; //iteracja zmiejszająca
				}
			array[j + 1] = temp; //iter 3: j<0 czyli while skonczony, ustawienie tempa czyli teraźniejszej liczby na ostatnie miejsce z iteracji while(w tym przyoadku 0) -> 9,17,56
		}
	}
	void BubbleSort() {
		int temp;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length-i; j++)
			{
				if (array[j] > array[j+1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
	void PrimeToFile() {
		std::vector<int> tablica;
		bool is_Prime;
		for (size_t i = 0; i < length; i++)
		{
			is_Prime = true;
			if (array[i] == 0 || array[i] == 1) is_Prime = false;
			else {
				for (size_t j = 2; j <= array[i]/2; j++)
				{
					if (array[i] % j == 0) {
						is_Prime = false;
						break;
					}
				}
			}
			if (is_Prime) {
				tablica.push_back(array[i]);
			}
		}
		std::ofstream Plik("pierwsze.txt",std::ios::app);
		for (size_t i = 0; i < tablica.size(); i++)
		{
			Plik << " " << tablica[i] << " ";
		}
		Plik << "\n";
		Plik.close();
		//Wyświetlenie
		for (size_t i = 0; i < tablica.size(); i++)
		{
			std::cout << tablica[i] << " ";
		}
		std::cout << "\n ODczytywanie z pliku \n";
		std::ifstream Odczyt;
		std::string zapis;
		Odczyt.open("pierwsze.txt");
		if (Odczyt.is_open()) {
			while (std::getline(Odczyt, zapis)) {
				std::cout << zapis << "\n";
			};

		}
		Odczyt.close();
	}
	void SelectionSort(bool how = true) {
		int temp,minIndex;
		for (size_t i = 0; i < length-1; i++)
		{
			minIndex = i;
			for (size_t j = i+1; j < length; j++)
			{
					if (array[j] < array[minIndex])
					{
						minIndex = j;
					}
			}
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
	void display() {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << array[i] << " ";
		}
	}
};

