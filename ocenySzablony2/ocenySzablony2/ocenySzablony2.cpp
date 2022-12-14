#include<iostream>
using namespace std;


void cw1();
void cw2();
//Definicja szablonu klasy Oceny
template<class T, int n>
//UWAGA:
//Szablon klasy oceny ma dwa parametry szablonowe: ugólniony typ danych T oraz liczbę całkowitą n.
class Oceny {
public:
    T oceny[n]; //zmienna członkowska
    T max() { //funkcja członkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] > temp) temp = oceny[i];
        }
        return temp;
    }

    T min() { //funkcja członkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] < temp) temp = oceny[i];
        }
        return temp;
    }
    T avg() {;
        T added = 0;
        T temp = oceny[0];
            for (int i = 0; i < n; i++) {
                added = added + oceny[i];
            }
        return added / n;
    }
};

template<class T> //szablon ma jeden parametr szablonowy T
class Oceny1 {
public:
    //Definicja kontruktora domyślnego
    Oceny1() {
        cout << "Wywołanie konstruktora klasy ogólnej..." << endl;
    }
    //Definicje szablonów zmiennych członkowskich
    T wyklad;
    T cwiczenia;
    T laboratorium;
    T seminarium;
    //Definicja szablonu funkcji członkowskiej srednia()
    T srednia() {
        return (wyklad + cwiczenia + laboratorium + seminarium) / 4;
        /*UWAGA:
        Jeżeli zmienne członkowskie wyklad, cwiczenia, laboratorium, seminarium należą do typu całkowitego
        mamy do czynienia z dzieleniem całkowitym.*/
    }

};

//Definicja specjalizacji szablonu klasy Oceny dla typu double
template<>
class Oceny1<double> {
public:
    //Definicja kontruktora domyślnego
    Oceny1() {
        cout << "Wywołanie konstruktora klasy specjalizowanej..." << endl;
    }
    //Definicje szablonów zmiennych członkowskich
    double wyklad;
    double cwiczenia;
    double laboratorium;
    double seminarium;
    //Definicja szablonu funkcji członkowskiej srednia()
    double srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody średnia w klasie specjalizowanej różni się od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uogólnionej.*/
    }

};
template<>
class Oceny1<float> {
public:
    Oceny1() {
        cout << "Wywołanie konstruktora klasy specjalizowanej double..." << endl;
    }
    //Definicje szablonów zmiennych członkowskich
    float wyklad;
    float cwiczenia;
    float laboratorium;
    float seminarium;
    //Definicja szablonu funkcji członkowskiej srednia()
    float srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody średnia w klasie specjalizowanej różni się od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uogólnionej.*/
    }
};
int main()
{
    //cw1()
    cw2();
    return 0;
}
void cw1() {
    //Utworzenie i inicjalizacja obiektu oceny
    Oceny<float, 3> oceny{ 3,5,4 };
    /*UWAGA:
    Szablon klasy Oceny został skonkretyzowany za pomocą argumentów szablonowych: typu danych int oraz liczby 3.
    Tym samym została wygenerowana instancja szablonu klasy Oceny - nowa klasa, w której uogólniony typ danych T został
    zastąpiony typem całkowitym int, a parametr n - liczbą 3.
    Obiekt oceny jest instancją właśnie tej klasy.*/
    cout << "Najwyższa z oceny: " << oceny.max() << endl;
    cout << "Najniższa z oceny: " << oceny.min() << endl;
    cout << "Średnia ocen: " << oceny.avg() << endl;
}
void cw2() {
    //Utworzenie obiektu oceny1
    Oceny1<int> oceny1 = Oceny1<int>(); //jawne wywołanie konstruktora domyślnego
    /*UWAGA:
    Obiekt oceny1 został utworzony na podstawie klasy ogólnej Oceny po jej konkretyzacji dla typu int.
    Wcześniej kompilator sprawdził, że nie jest dostępna specjalizacja szablonu Oceny dla typu int.*/
    oceny1.wyklad = 3;
    oceny1.cwiczenia = 4;
    oceny1.laboratorium = 3;
    oceny1.seminarium = 4;
    cout << "Średnia ocen semestralnych: " << oceny1.srednia() << endl;

    //Utworzenie obiektu oceny2
    Oceny1<double> oceny2; //niejawne wywołanie konstruktora domyślnego
    /*UWAGA:
    Obiekt oceny2 zostaje utworzony na podstawie specjalizacji szablonu klasy Oceny dla typu danych double.*/
    oceny2.wyklad = 3.0;
    oceny2.cwiczenia = 4.0;
    oceny2.laboratorium = 3.0;
    oceny2.seminarium = 4.0;
    cout << "Średnia ocen semestralnych: " << oceny2.srednia() << endl;

}