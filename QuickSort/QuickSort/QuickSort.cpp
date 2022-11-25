// QuickSort.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <time.h>

void quickSort(int* tablica, int lewo, int prawo) {
    int pivot = tablica[(lewo + prawo) / 2];
    int i, j, temp;
    i = lewo;
    j = prawo;
    do {
        while (tablica[i] < pivot)i++;
        while (tablica[j] > pivot)j--;
        if (i <= j) {
            temp = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = temp;
            j--;
            i++;
        }
    } while (i <= j);
    if(j>lewo) quickSort(tablica, lewo, j);
    if(i<prawo)quickSort(tablica, i, prawo);
}
int main()
{
    int ile = 20;
    int* tablica;
    tablica = new int[20];
    srand(time(NULL));
    for (size_t i = 0; i < ile; i++)
    {
        tablica[i] = rand() % 100 + 1;
    }
    for (size_t i = 0; i < ile; i++)
    {
        std::cout << " " << tablica[i] << " ";
    }
    std::cout<<"--------------"<<std::endl;
    quickSort(tablica, 0, ile-1);
    for (size_t i = 0; i < ile; i++)
    {
        std::cout<<" "<<tablica[i]<<" ";
    }
}


