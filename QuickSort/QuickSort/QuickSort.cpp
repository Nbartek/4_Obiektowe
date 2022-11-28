// QuickSort.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <time.h>
#include <windows.h>

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
void sortowanieBabelkowe(int t[], int n) {
    int i, j;
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (t[j] < t[i]) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}
int main()
{
    clock_t start, stop;
    double czas;
    int ile = 1000000;
    int* tablica;
    int* tablica2;
    tablica = new int[ile];
    tablica2 = new int[ile];
    srand(time(NULL));
    for (size_t i = 0; i < ile; i++)
    {
        tablica[i] = rand() % 100 + 1;
        tablica2[i] = rand() % 100 + 1;

    }
    //for (size_t i = 0; i < ile; i++)
    //{
    //    std::cout << " " << tablica[i] << " ";
    //}
    //std::cout<<"--------------"<<std::endl;
    std::cout << "Sortowanie szybkie" << std::endl;
    start = clock();
    quickSort(tablica, 0, ile-1);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << czas << std:: endl;
    //for (size_t i = 0; i < ile; i++)
    //{
    //    std::cout<<" "<<tablica[i]<<" ";

    //}
    std::cout << "Tablica bombelkowa" << std::endl;
    //for (size_t i = 0; i < ile; i++)
    //{
    //    std::cout << " " << tablica2[i] << " ";
    //}
    //std::cout << "--------------" << std::endl;
    start = clock();
    sortowanieBabelkowe(tablica, ile);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << czas << std::endl;
    //for (size_t i = 0; i < ile; i++)
    //{
    //    std::cout << " " << tablica2[i] << " ";

    //}
}


