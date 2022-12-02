// SortowaniePrzezWstawianie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class InsertionSort {
    std::vector<int> tablica;
    int dlugosc =0;
public:
    void enterNumbers(int length = 10) {
        for (size_t i = 0; i < length; i++)
        {
            int number;
            std::cout << "Wprowadz liczbe o indexie " << i << std::endl;
            std::cin >> number;
            tablica.push_back(number);
        }
    }
    void setDlugosc() {
        dlugosc = tablica.size();
        std::cout << "Wielkosc tablicy to " << dlugosc << std::endl;
    }
    void displayArray() {
        for (size_t i = 0; i < dlugosc; i++)
        {
            std::cout << tablica[i] << " ";
        }
        std::cout << std::endl;
    }
    void sort() {
        for (size_t i = 1; i < dlugosc-1; i++)
        {
            int temp = tablica[i];
            int j = i - 1;
            while (j >= 0 && tablica[j] > temp) {
                int temp2 = tablica[j + 1];
                tablica[j + 1] = tablica[j];
                tablica[j] = temp2;
                j++;
            }
            tablica[i + 1] = temp;
        }
    }
};
int main()
{
    InsertionSort is1;
    is1.enterNumbers();
    is1.setDlugosc();
    is1.displayArray();
    is1.sort();
    is1.displayArray();
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
