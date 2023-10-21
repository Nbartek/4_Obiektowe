// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "SortingAll.h"

#include "SearchingAll.h"
#include "BullcrapEx.h"

//using namespace std;

int main()
{
    int tab[100];
    int dlugosc = 100;
                                                                    //Sortowania testowane
    SortingAll t1;
    t1.setLen(dlugosc);
    t1.fillRandom();
    //t1.BubbleSort();
    //t1.SelectionSort();
    //t1.InsertionSort();
    //t1.PrimeToFile();
    //t1.display();
                                                                    //Wyszukiwania testowane
    SearchingAll s1;
    //s1.fillRandom();
    //s1.VardenSearch(1);
    //s1.Jumpsearch(12);
    //std::cout<<"Wynik to: "<<s1.BinarySearch(10, 0, 24) << std::endl;
    //s1.display();
                                                                    //Egzaminy Wczesniejsze 2
    //std::cout << "Liczba zarejestrowanych osob to " << Osoba::instancjeKlasy << std::endl;
    //Osoba o2;
    //std::cout << "Wpisz imie ";
    //std::string name;
    //std::cin >> name;
    //std::cout << "Podaj identyfikator ";
    //int id;
    //std::cin >> id;
    //Osoba o3{ id,name };
    //Osoba o4{o3};

    //std::cout << "-----------------------Wyswietanlie---------------- - " << std::endl;
    ////o2.Wyswietl("Jan");
    ////o3.Wyswietl("Jan");
    ////o4.Wyswietl("Jan");

    //std::cout << "Liczba zarejestrowanych osob to " << Osoba::instancjeKlasy << std::endl;
                                                                    //Egzaminy Wczesniejsze 3
    PrzezWybieranie w1;
    w1.wypelnienieLosowe();
    w1.wyswietl();
    //w1.sortowaniePrzezWybieranie()
    //w1.WyszukiwanieZWartownikiem(16);
    std::cout << std::endl;
    w1.wyswietl();

}

