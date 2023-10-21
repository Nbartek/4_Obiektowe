#pragma once
#include <string>
#include <iostream>
class BullcrapEx
{
};
class Osoba {
	int id;
	std::string imie;
public:
	static int instancjeKlasy;

	Osoba() {
		this->id = 0;
		this->imie = "";
		instancjeKlasy++;
	};
	Osoba(int id, std::string imie) {
		this->id = id;
		this->imie = imie;
		instancjeKlasy++;
	}
	Osoba(Osoba &osoba) {
		this->id = osoba.id;
		this->imie = osoba.imie;
		instancjeKlasy++;
	};
	void Wyswietl(std::string nazwa) {
		if (imie!="")
		{
			std::cout << "Czesc " << nazwa << ", mam na imie " << imie << std::endl;
		}
		else {
			std::cout << "Brak Danych" << std::endl;
		}
		
	}

};
class PrzezWybieranie {
	int tab[101];
	int dlugosc = 100;
public:
	void wypelnienieLosowe() {
		srand(time(NULL));
		for (size_t i = 0; i < dlugosc; i++)
		{
			tab[i] = (rand() % 100) + 1;
		}
	}
	/**********************
	* nazwa funkcji:		znajdzNajmniejsze
	* parametry wejściowe:	poczatkowyIndex - liczba będąca wartościa początkową dla iteratora pętli
	* wartość zwracana:		liczba równa indexowi najmniejszej liczby w tablicy od poczatkowyIndex
	* autor:				Scornax
	**********************/
	int znajdzNajmniejsze(int poczatkowyIndex) {
		int index{poczatkowyIndex};
		for (size_t i = poczatkowyIndex; i < dlugosc; i++)
		{
			if (tab[i] < tab[index]) {
				index = i;
			}
		}
		return index;
	}
	void sortowaniePrzezWybieranie() {
		for (size_t i = 0; i < dlugosc; i++)
		{
			int temp;
			int minIndex = znajdzNajmniejsze(i);
			temp = tab[i];
			tab[i] = tab[minIndex];
			tab[minIndex] = temp;
		}
	}
	void WyszukiwanieZWartownikiem(int szukanaLiczba) {
		int indexSzukanej = dlugosc;
		tab[dlugosc] = szukanaLiczba;
		for (size_t i = 0; i <= dlugosc; i++)
		{
			if (tab[i] == szukanaLiczba) {
			indexSzukanej = i;
			break;
			} 
		}
		if (indexSzukanej == dlugosc) {
			std::cout << "Nie znaleziono liczby szukanej" << std::endl;
		}
		else {
			std::cout << "Znaleziono liczbe na miejscu: " << indexSzukanej << std::endl;
		}
	}
	void wyswietl() {
		for (size_t i = 0; i < dlugosc; i++)
		{
			std::cout << " " << tab[i] << " ";
		}
	}
};
