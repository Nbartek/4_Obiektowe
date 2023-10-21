#pragma once
#include <time.h>
#include <iostream>
class SearchingAll
{
private:
	int tablica[100];
	int tab[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int dlg = 25;
	int length = 100;
public:
	void fillRandom() {
		srand(time(NULL));
		for (size_t i = 0; i < length; i++)
		{
			tablica[i] = (rand() % 100) + 1;
		}
	}
	void display() {
		for (size_t i = 0; i < length; i++)
		{
			std::cout << tablica[i] << ", ";
		}
	}
		/******************************************************
		nazwa funkcji : WardenSearch
		argumenty : parametr typu numerycznego sNumber - przechowuje wyszukiwana liczbę
		typ zwracany : void, wyświetla w konsoli całą tablicę podzieloną przez przecinki i  czy znalazł liczbe szukaną, jesli tak to na jakim indexie
		informacje : Wyszukiwanie z wartownikiem robione na podstawowej tablicy c++, nie mozna w niej modyfikowac długości dlatego podmieniałem ostatnią liczbę na szukaną, a wartość z ostatniego indexu wporwadzałem do doatkowej zmiennej ktrórą sprawdzałem na końcu
		autor : 0
		*****************************************************/
	void VardenSearch(int sNumber) {
		int indexFounded =-1;
		int temp = tablica[length - 1];
		tablica[length - 1] = sNumber;
		for (size_t i = 0; i < length; i++)
		{
			if (tablica[i] == sNumber) {
				indexFounded = i;
				break;
			}
		}
		tablica[length - 1] = temp;
		display();
		if (indexFounded == length-1&& temp!=sNumber) {
			std::cout << "Nie znaleziono liczby szukanej" << std::endl;
		}
		else {
			std::cout << "Znaleziono liczbe na miejscu: " << indexFounded << std::endl;
		}
	}
	void Jumpsearch(int sNumber) {
		int jumpedDistance = sqrt(25);
		int wczesniejsza = 0;
		int indexWynik = -1;
		for (size_t i = 0; i <= 25; i+=jumpedDistance)
		{
			if (sNumber>=tab[wczesniejsza] && sNumber<tab[i]) {
				for (size_t j = wczesniejsza; j < i; j++)
				{
					if (tab[j] == sNumber) {
					indexWynik = j;
					goto exit;
					};
					
				
				}

			}
			wczesniejsza = i;
		}
		exit:
		if (indexWynik == -1) {
			std::cout << "Nie znaleziono liczby szukanej" << std::endl;
		}
		else {
			std::cout << "Znaleziono liczbe na miejscu: " << indexWynik << std::endl;
		}
  	}
	int BinarySearch(int sNumber,int start, int end) {
		while (end>=start)
		{
			int middle = (end+start) / 2;
			if (tab[middle] == sNumber) return middle;
			if (sNumber < tab[middle]) {
				end = middle - 1;
				return BinarySearch(sNumber, start, end);
			}
			if (sNumber > tab[middle]) {
				start = middle + 1;
				return BinarySearch(sNumber, start, end);
			}
		}

		return -1;
	}
};

