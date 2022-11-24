
#include <vector>
#include <iostream>

using namespace std;
class SortArray {
private:
    int tablica[10];
public:
    /// <summary>
    /// nazwa funkcji:          searchMax()
    /// parametry wejœciowe:    brak
    /// wartoœæ zwracana:       nadpisuje prywatn¹ zmienn¹ maximal - przeszukuje pêtl¹ for tablicê vectorow¹ i sprawdza dla ka¿dej rotacji czy 
    ///                         liczba jest wiêksza od nastêpnej i czy jest wiêksza od zmiennej max( na pocz¹tku przypisanej jako 0). Jesli warunki s¹ spe³nione
    ///                         max jest nadpisywany wartoœæia tablicy o indexie rotacji. Po petli maximum jest nadpisywane zmienna max 
    ///  autor:                 Bartek Nosek
    /// </summary>
    int searchMax(int j =0) {
        int max =0;
        for (int i = j; i < 9; i++)
        {
            if (tablica[i] > tablica[i + 1]) {
           
                if (tablica[i] > max) {
                    max = i;
                    
                }

            }
        }
        return max;
    }
    /// <summary>
    /// nazwa funkcji:           sort()
    /// parametry wejœciowe:    brak
    /// wartoœæ zwracana:       funkcja zwraca posortowan¹ tablicê. Sortowana jest poprzez 2 petle, pierwsza idzie po ka¿dej
    ///                         rotacji i w ka¿dej rotacji petla(mniejsza z ka¿d¹ rotacj¹) wyszukuje najmniejsz¹ wartoœæ w 
    ///                         tablicy i podk³ada ta liczbe w miejsce liczby z danej rotacji pêtli g³ównej 
    /// autor:                  Bartek Nosek
    /// </summary>
    void sort() {
        for (int i = 0; i < 10; i++)
        {
            int maximal = searchMax(i);
            int temp = tablica[i];
            tablica[i] = tablica[maximal];
            tablica[maximal] = temp;
           
                

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
            cout << "Wprowadz liczbe na index " << i << endl;
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
    cout<<v1.searchMax(2);
    v1.sort();
    cout << "-----------Wynik" << endl;
    v1.display();
    
}

