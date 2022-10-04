// sentinelSearchVol2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "sentinel.h"
#include <iostream>

int main()
{
	std::cout << "Jak duza liste chesz stworzyc: ";
	int length;
	cin >> length;
	sentinel lista1(length);
	std::cout << "Jakia liczbe chesz wyszukac";
	int cd;
	cin >> cd;
	lista1.sentinelSearch(cd);
	int change;
	int numChanged;
	std::cout << "Ktora miejsce chialbys mienic: ";
	cin >> change;
	if (change > length) {
		change = 0;
	}
	std::cout << "Na jaka liczbe: ";
	cin >> change;

}


