// DynamicPoliform.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Pracownik {
public: 
    string imie, nazwisko;
    virtual void zwrocDane();
};
class Nauczyciel : public Pracownik {
public:
    string przedmiot;
    void zwrocDane();
};
class Wychowawca : public Nauczyciel {
    string klasa;
    void zwrocDane();
};
int main()
{
    Pracownik* w_pracownik;
    Pracownik pracownik1;
    w_pracownik = &pracownik1;
    w_pracownik->nazwisko = "Janda";
    pracownik1.imie = "deniss";// tutaj sie tak da ale przy dynamicznym tworzeniu tak sie nie bedzie da³o zrobiæ
    w_pracownik->zwrocDane();

    Nauczyciel pracownik2;
    w_pracownik = &pracownik2;
    w_pracownik->nazwisko = "Janda";
    pracownik2.przedmiot = " dupa";
    w_pracownik->zwrocDane();
    Wychowawca pracownik3;
    w_pracownik = &pracownik3;
    w_pracownik->nazwisko = "Janda";
    pracownik3.przedmiot = " dupa";
    //pracownik3.klasa = "jezynki2a";
    w_pracownik->zwrocDane();
    std::cout << "Hello World!\n";
}

void Pracownik::zwrocDane() {
    cout << "Metoda zwrocDane() z klasy pracownik" << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
}
void Nauczyciel::zwrocDane() {
    cout << "Metoda zwrocDane() z klasy pracownik" << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Przedmiot" << przedmiot << endl;
}
void Wychowawca::zwrocDane() {
    cout << "Metoda zwrocDane() z klasy pracownik" << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Klasa: " << klasa << endl;
    cout << "Przedmiot: " << przedmiot << endl;
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
