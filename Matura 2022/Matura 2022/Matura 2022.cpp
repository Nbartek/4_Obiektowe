// Matura 2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Zadanie4_1();
void Zadanie4_2();
void Zadanie4_3();
int main()
{
	//Zadanie4_1();
	//Zadanie4_2();
	Zadanie4_3();

}

void Zadanie4_1() {
	std::string pierwsza;
	int wszystkie = 0;
	int dlugosc = 0;
	char a, b;
	std::string tekst;
	std::ifstream Plik("przyklad.txt");
	while (getline(Plik, tekst))
	{
		dlugosc = tekst.length() - 1;
		a = tekst[dlugosc];
		b = tekst[0];
		if (tekst[0] == tekst[dlugosc]) {
			wszystkie++;
			if (pierwsza.empty()) {
				pierwsza = tekst;
			}

		}
	}
	std::cout << pierwsza << std::endl;
	std::cout << wszystkie << std::endl;
	Plik.close();
	}
void Zadanie4_2() {
	std::string najwiekszaLiczba;
	int najwiekszeWspolczynnikow = 0;
	std::string roznaLiczba;
	int rozneWspolczynniki = 0;
	std::vector<int> zbor;
	std::vector<int>zbiorRoznych;
	int wszystkie = 0;
	int dlugosc = 0;
	std::string tekst;
	std::ifstream Plik("przyklad.txt");
	while (getline(Plik, tekst))
	{
		int i = 2;
		int number = std::stoi(tekst);
		while (number > 1) {
			if (number % i == 0) {
				number = number / i;
				zbor.push_back(i);
				if (zbiorRoznych.size() == 0) { zbiorRoznych.push_back(i); }
			}
			else { i++; }
		}
		if (zbor.size()>najwiekszeWspolczynnikow) {
			najwiekszeWspolczynnikow = zbor.size();
			najwiekszaLiczba = tekst;
		}

		for (size_t i = 0; i < zbor.size(); i++)
		{
			for (size_t j = 0; j < zbiorRoznych.size(); j++)
			{
				if (zbor[i] == zbiorRoznych[j]) break;
				else {
					zbiorRoznych.push_back(zbor[i]);
					break;
				}
			}
		}
		if (zbiorRoznych.size() > rozneWspolczynniki) {
			rozneWspolczynniki = zbiorRoznych.size();
			roznaLiczba = tekst;
		}
		zbor.clear();
		zbiorRoznych.clear();
	}
	std::cout << najwiekszaLiczba + " " + std::to_string( najwiekszeWspolczynnikow )+ " " + roznaLiczba + " " +std::to_string( rozneWspolczynniki) << std::endl;
	Plik.close();
}
void Zadanie4_3() {
	int troiki = 0;
	int piontki = 0;
	std::vector<int> liczby;
	std::string tekst;
	std::ofstream Zapis("trojki.txt");
	std::ifstream Plik("przyklad.txt");
	while (getline(Plik, tekst))
	{
		int liczba = std::stoi(tekst);
		liczby.push_back(liczba);
	}
	for (size_t d = 0; d < liczby.size(); d++)
	{
		for (size_t i = 0; i < liczby.size(); i++)
		{
			if (liczby[i] % liczby[d] == 0 && liczby[i] !=liczby[d]) {
				for (size_t j = 0; j < liczby.size(); j++)
				{
					if (liczby[j] % liczby[i] == 0 && liczby[i] != liczby[j]){
						troiki++;
						Zapis << std::to_string(liczby[d]) + " " + std::to_string(liczby[i]) + " " + std::to_string(liczby[j]) + "\n ";
						for (size_t k = 0; k < liczby.size(); k++)
						{
							if (liczby[k] % liczby[j] == 0 && liczby[k] != liczby[j]) {
								for (size_t l = 0; l < liczby.size(); l++)
								{
									if (liczby[l] % liczby[k] == 0 && liczby[l] != liczby[k]) {
										piontki++;
									}
								}
							}
						}
					}
				}
			}
		}

	}
	std::cout << troiki << std::endl;
	std::cout << piontki << std::endl;
	Plik.close();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
