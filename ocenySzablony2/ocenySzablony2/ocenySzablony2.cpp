#include<iostream>
using namespace std;


void cw1();
void cw2();
//Definicja szablonu klasy Oceny
template<class T, int n>
//UWAGA:
//Szablon klasy oceny ma dwa parametry szablonowe: ugólniony typ danych T oraz liczbê ca³kowit¹ n.
class Oceny {
public:
    T oceny[n]; //zmienna cz³onkowska
    T max() { //funkcja cz³onkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] > temp) temp = oceny[i];
        }
        return temp;
    }

    T min() { //funkcja cz³onkowska
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
    //Definicja kontruktora domyœlnego
    Oceny1() {
        cout << "Wywo³anie konstruktora klasy ogólnej..." << endl;
    }
    //Definicje szablonów zmiennych cz³onkowskich
    T wyklad;
    T cwiczenia;
    T laboratorium;
    T seminarium;
    //Definicja szablonu funkcji cz³onkowskiej srednia()
    T srednia() {
        return (wyklad + cwiczenia + laboratorium + seminarium) / 4;
        /*UWAGA:
        Je¿eli zmienne cz³onkowskie wyklad, cwiczenia, laboratorium, seminarium nale¿¹ do typu ca³kowitego
        mamy do czynienia z dzieleniem ca³kowitym.*/
    }

};

//Definicja specjalizacji szablonu klasy Oceny dla typu double
template<>
class Oceny1<double> {
public:
    //Definicja kontruktora domyœlnego
    Oceny1() {
        cout << "Wywo³anie konstruktora klasy specjalizowanej..." << endl;
    }
    //Definicje szablonów zmiennych cz³onkowskich
    double wyklad;
    double cwiczenia;
    double laboratorium;
    double seminarium;
    //Definicja szablonu funkcji cz³onkowskiej srednia()
    double srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody œrednia w klasie specjalizowanej ró¿ni siê od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uogólnionej.*/
    }

};
template<>
class Oceny1<float> {
public:
    Oceny1() {
        cout << "Wywo³anie konstruktora klasy specjalizowanej double..." << endl;
    }
    //Definicje szablonów zmiennych cz³onkowskich
    float wyklad;
    float cwiczenia;
    float laboratorium;
    float seminarium;
    //Definicja szablonu funkcji cz³onkowskiej srednia()
    float srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody œrednia w klasie specjalizowanej ró¿ni siê od kodu szablonu metody o tej samej nazwie
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
    Szablon klasy Oceny zosta³ skonkretyzowany za pomoc¹ argumentów szablonowych: typu danych int oraz liczby 3.
    Tym samym zosta³a wygenerowana instancja szablonu klasy Oceny - nowa klasa, w której uogólniony typ danych T zosta³
    zast¹piony typem ca³kowitym int, a parametr n - liczb¹ 3.
    Obiekt oceny jest instancj¹ w³aœnie tej klasy.*/
    cout << "Najwy¿sza z oceny: " << oceny.max() << endl;
    cout << "Najni¿sza z oceny: " << oceny.min() << endl;
    cout << "Œrednia ocen: " << oceny.avg() << endl;
}
void cw2() {
    //Utworzenie obiektu oceny1
    Oceny1<int> oceny1 = Oceny1<int>(); //jawne wywo³anie konstruktora domyœlnego
    /*UWAGA:
    Obiekt oceny1 zosta³ utworzony na podstawie klasy ogólnej Oceny po jej konkretyzacji dla typu int.
    Wczeœniej kompilator sprawdzi³, ¿e nie jest dostêpna specjalizacja szablonu Oceny dla typu int.*/
    oceny1.wyklad = 3;
    oceny1.cwiczenia = 4;
    oceny1.laboratorium = 3;
    oceny1.seminarium = 4;
    cout << "Œrednia ocen semestralnych: " << oceny1.srednia() << endl;

    //Utworzenie obiektu oceny2
    Oceny1<double> oceny2; //niejawne wywo³anie konstruktora domyœlnego
    /*UWAGA:
    Obiekt oceny2 zostaje utworzony na podstawie specjalizacji szablonu klasy Oceny dla typu danych double.*/
    oceny2.wyklad = 3.0;
    oceny2.cwiczenia = 4.0;
    oceny2.laboratorium = 3.0;
    oceny2.seminarium = 4.0;
    cout << "Œrednia ocen semestralnych: " << oceny2.srednia() << endl;

}