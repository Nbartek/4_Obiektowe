// Matura2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include<string>
#include<fstream>
#include<sstream>
#include <vector>

void Zadanie1_2();
void Zadanie4();

int main()
{
    Zadanie4();

}
void Zadanie1_2() {
    int n = 6066;
    int cyfra;
    int d = 0;
    int potega = 1;
    while (n > 0)
    {
        cyfra = n % 10;
        n = n / 10;
        cyfra = 9 - cyfra;
        d = d + (potega * cyfra);
        potega = potega * 10;
    }
    std::cout << d;
}
void Zadanie4() {
    //std::ifstream Plik("przyklad.txt");
    std::ifstream Plik("instrukcje.txt");
    std::string tekst;
    std::string zdanie;
    std::vector<std::string> rodzaje{ "DOPISZ","ZMIEN","USUN","PRZESUN" };
    std::vector<std::string> litery{ "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
    std::vector<int> literyIle{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    std::vector<std::string> pojedynczaInstrukcja;
    std::vector<std::string> wynik;
    std::string podzial;
    int najdluszszyCiagDlg = 0;
    int ostatni = -1;
    int najdluszyCiag = -1;
    int ciagA, ciagB, ciagC, ciagD = 1;
    while (std::getline(Plik, tekst)) {
        std::stringstream instrukcja(tekst);
        while (instrukcja >> podzial) {
            pojedynczaInstrukcja.push_back(podzial);

       }
        if (pojedynczaInstrukcja[0].compare(rodzaje[0]) == 0) {
            wynik.push_back(pojedynczaInstrukcja[1]);
            for (size_t j = 0; j < litery.size(); j++)
            {
                std::string temp = (litery[j]);
                if (pojedynczaInstrukcja[1].compare(temp) == 0) {
                    literyIle[j] = literyIle[j] + 1;
                }
            }
            if (ostatni == 0) {
                ciagA++;
                if (ciagA > najdluszszyCiagDlg) {
                    najdluszyCiag = 0;
                    najdluszszyCiagDlg = ciagA;
                }
            }
            else {
                ciagA = 1;
            }
            ostatni = 0;
        }
        else if (pojedynczaInstrukcja[0].compare(rodzaje[1]) == 0) {
            int last = wynik.size()-1;
            wynik[last] = pojedynczaInstrukcja[1];
            if (ostatni == 1) {
                ciagB++;
                if (ciagB > najdluszszyCiagDlg) {
                    najdluszyCiag = 1;
                    najdluszszyCiagDlg = ciagB;
                }
            }
            else {
                ciagB = 1;
            }
            ostatni = 1;
        }
        else if (pojedynczaInstrukcja[0].compare(rodzaje[2]) == 0) {
            wynik.pop_back();
            if (ostatni == 2) {
                ciagC++;
                if (ciagC > najdluszszyCiagDlg) {
                    najdluszyCiag = 2;
                    najdluszszyCiagDlg = ciagC;
                }
            }
            else {
                ciagC = 1;
            }
            ostatni = 2;
        }
        else if (pojedynczaInstrukcja[0].compare(rodzaje[3]) == 0) {
            int gdzie = -1;
            for (size_t i = 0; i < wynik.size(); i++)
            {
                if (wynik[i].compare(pojedynczaInstrukcja[1]) == 0) {
                    gdzie = i;
                    break;
                 }
            }
            if (gdzie != -1) {
                for (size_t j = 0; j < litery.size(); j++)
                {
                    if (wynik[gdzie].compare((litery[j])) == 0) {
                        if (j == 25) {
                            wynik[gdzie] = "A";
                            break;
                        }
                        else {
                            wynik[gdzie] = (litery[j + 1]);
                            break;
                        }

                    }
                }
            }


            if (ostatni == 3) {
                ciagD++;
                if (ciagD > najdluszszyCiagDlg) {
                    najdluszyCiag = 3;
                    najdluszszyCiagDlg = ciagD;
                }
            }
            else {
                ciagD = 1;
            }
            ostatni = 3;
        }
        pojedynczaInstrukcja.clear();
    }
    Plik.close();
    int max = 0;
    std::string jaka;
    for (size_t i = 0; i < literyIle.size(); i++)
    {
        if (literyIle[i] > max) {
            max = literyIle[i];
            jaka = (litery[i]);
        }
    }
    for (size_t i = 0; i < wynik.size(); i++)
    {
        zdanie.append(wynik[i]);
    }
    std::cout << wynik.size() << std::endl;;
    std::cout << rodzaje[najdluszyCiag] << " " << najdluszszyCiagDlg << std::endl;
    std::cout << jaka << " " << max << std::endl;
    std::cout << zdanie << std::endl;
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
