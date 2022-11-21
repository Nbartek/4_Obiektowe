
#include <vector>
#include <iostream>

using namespace std;
class SortArray {
private:
    int tablica[10];
    int maximal;
public:
    /// <summary>
    /// nazwa funkcji:          searchMax()
    /// parametry wej�ciowe:    brak
    /// warto�� zwracana:       nadpisuje prywatn� zmienn� maximal - przeszukuje p�tl� for tablic� vectorow� i sprawdza dla ka�dej rotacji czy 
    ///                         liczba jest wi�ksza od nast�pnej i czy jest wi�ksza od zmiennej max( na pocz�tku przypisanej jako 0). Jesli warunki s� spe�nione
    ///                         max jest nadpisywany warto��ia tablicy o indexie rotacji. Po petli maximum jest nadpisywane zmienna max 
    ///  autor:                 Bartek Nosek
    /// </summary>
    void searchMax() {
        int max =0;
        for (int i = 0; i < 10; i++)
        {
            if (tablica[i] > tablica[i + 1]) {
                if (tablica[i] > max) {
                    max = tablica[i];
                }

            }
        }
        maximal = max;
    }
    /// <summary>
    /// nazwa funkcji:           sort()
    /// parametry wej�ciowe:    brak
    /// warto�� zwracana:       funkcja zwraca posortowan� tablic�. Sortowana jest poprzez 2 petle, pierwsza idzie po ka�dej
    ///                         rotacji i w ka�dej rotacji petla(mniejsza z ka�d� rotacj�) wyszukuje najmniejsz� warto�� w 
    ///                         tablicy i podk�ada ta liczbe w miejsce liczby z danej rotacji p�tli g��wnej 
    /// autor:                  Bartek Nosek
    /// </summary>
    void sort() {
        for (int i = 0; i < 10; i++)
        {
            for (int j = i; j < 10; j++)
            {
                int temp;
                if (tablica[i] < tablica[i + 1]) {
                    temp = tablica[i];
                    tablica[i] = tablica[i + 1];
                    tablica[i + 1] = temp;

                }
                //tablica[i] = maximal;
            }
                

        }

    }
    void display() {
        for (int i = 0; i < 10; i++)
        {
            cout << tablica[i]<<" ";
        }
    }
    void getNubersToArray() {
        for (int i = 0; i < 10; i++)
        {
            int num;
            cout << "Wprowadz liczbe na index" << i << endl;
            cin >> num;
            tablica[i]=num;
        }
    }
    void getRandomNumbers() {
        for (int i = 0; i < 10; i++)
        {
            int num = rand()%100;
            tablica[i] = num;
        }
    }
};
int main()
{
    SortArray v1;
    //v1.getNubersToArray();
    v1.getRandomNumbers();
    v1.searchMax();
    v1.sort();
    cout << "-----------Wynik" << endl;
    v1.display();
    
}

