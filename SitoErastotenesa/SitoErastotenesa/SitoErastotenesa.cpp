// SitoErastotenesa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Sieve {
private:
    static const int maxNumber = 120;
    bool numbers[maxNumber + 1];

    void delateNumber();
public:
    Sieve() {
        delateNumber();
    }
    void outputPrimaryNum();
    std::string isPrimary(int n);
};

int main()
{
    std::cout << "Hello World!\n";
    Sieve sito;
    sito.outputPrimaryNum();
}

std::string isPrimary(int n) {
    if (n != 1||n!=0) {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 1) return "Nie jest liczba pierwsza";
            return "jest liczba pierwsza";
        }
    }

}
void Sieve::outputPrimaryNum() {
    cout << "Liczby pierwsze z przedzialu od 2 do " << maxNumber << endl;
    for (int i = 2; i < maxNumber; i++)
    {
        if (numbers[i] != true) cout << i << ", ";
    }
    cout << endl;
}
void Sieve::delateNumber() {
    for (int i = 2; i*i <maxNumber ; i++)
    {
        for (int j = i*i; j < maxNumber; j+=i)
        {
            numbers[j] = true;
        }
    }
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
