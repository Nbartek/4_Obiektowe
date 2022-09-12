#include<iostream>
using namespace std;


void cw1();
void cw2();
//Definicja szablonu klasy Oceny
template<class T, int n>
//UWAGA:
//Szablon klasy oceny ma dwa parametry szablonowe: ug�lniony typ danych T oraz liczb� ca�kowit� n.
class Oceny {
public:
    T oceny[n]; //zmienna cz�onkowska
    T max() { //funkcja cz�onkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] > temp) temp = oceny[i];
        }
        return temp;
    }

    T min() { //funkcja cz�onkowska
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
    //Definicja kontruktora domy�lnego
    Oceny1() {
        cout << "Wywo�anie konstruktora klasy og�lnej..." << endl;
    }
    //Definicje szablon�w zmiennych cz�onkowskich
    T wyklad;
    T cwiczenia;
    T laboratorium;
    T seminarium;
    //Definicja szablonu funkcji cz�onkowskiej srednia()
    T srednia() {
        return (wyklad + cwiczenia + laboratorium + seminarium) / 4;
        /*UWAGA:
        Je�eli zmienne cz�onkowskie wyklad, cwiczenia, laboratorium, seminarium nale�� do typu ca�kowitego
        mamy do czynienia z dzieleniem ca�kowitym.*/
    }

};

//Definicja specjalizacji szablonu klasy Oceny dla typu double
template<>
class Oceny1<double> {
public:
    //Definicja kontruktora domy�lnego
    Oceny1() {
        cout << "Wywo�anie konstruktora klasy specjalizowanej..." << endl;
    }
    //Definicje szablon�w zmiennych cz�onkowskich
    double wyklad;
    double cwiczenia;
    double laboratorium;
    double seminarium;
    //Definicja szablonu funkcji cz�onkowskiej srednia()
    double srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody �rednia w klasie specjalizowanej r�ni si� od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uog�lnionej.*/
    }

};
template<>
class Oceny1<float> {
public:
    Oceny1() {
        cout << "Wywo�anie konstruktora klasy specjalizowanej double..." << endl;
    }
    //Definicje szablon�w zmiennych cz�onkowskich
    float wyklad;
    float cwiczenia;
    float laboratorium;
    float seminarium;
    //Definicja szablonu funkcji cz�onkowskiej srednia()
    float srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody �rednia w klasie specjalizowanej r�ni si� od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uog�lnionej.*/
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
    Szablon klasy Oceny zosta� skonkretyzowany za pomoc� argument�w szablonowych: typu danych int oraz liczby 3.
    Tym samym zosta�a wygenerowana instancja szablonu klasy Oceny - nowa klasa, w kt�rej uog�lniony typ danych T zosta�
    zast�piony typem ca�kowitym int, a parametr n - liczb� 3.
    Obiekt oceny jest instancj� w�a�nie tej klasy.*/
    cout << "Najwy�sza z oceny: " << oceny.max() << endl;
    cout << "Najni�sza z oceny: " << oceny.min() << endl;
    cout << "�rednia ocen: " << oceny.avg() << endl;
}
void cw2() {
    //Utworzenie obiektu oceny1
    Oceny1<int> oceny1 = Oceny1<int>(); //jawne wywo�anie konstruktora domy�lnego
    /*UWAGA:
    Obiekt oceny1 zosta� utworzony na podstawie klasy og�lnej Oceny po jej konkretyzacji dla typu int.
    Wcze�niej kompilator sprawdzi�, �e nie jest dost�pna specjalizacja szablonu Oceny dla typu int.*/
    oceny1.wyklad = 3;
    oceny1.cwiczenia = 4;
    oceny1.laboratorium = 3;
    oceny1.seminarium = 4;
    cout << "�rednia ocen semestralnych: " << oceny1.srednia() << endl;

    //Utworzenie obiektu oceny2
    Oceny1<double> oceny2; //niejawne wywo�anie konstruktora domy�lnego
    /*UWAGA:
    Obiekt oceny2 zostaje utworzony na podstawie specjalizacji szablonu klasy Oceny dla typu danych double.*/
    oceny2.wyklad = 3.0;
    oceny2.cwiczenia = 4.0;
    oceny2.laboratorium = 3.0;
    oceny2.seminarium = 4.0;
    cout << "�rednia ocen semestralnych: " << oceny2.srednia() << endl;

}