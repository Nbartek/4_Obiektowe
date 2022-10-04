// SentinelSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int sentinelSearch(int arr[], int n, int searchValue) {
    int i = 0;
    while (arr[i] != searchValue) {
        i++;
    }
    if (i < n)return i;
    return 0;
}
void fillArr(int arr[], int n, int searchValue) {
    srand(time(NULL));

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100) + 1;
    }
    arr[n] = searchValue;
    
}
void arrOutcome(int arr[],int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int cars[50];
    const int n = 50;
    fillArr(cars, 50, 12);
    arrOutcome(cars,50);
    sentinelSearch(cars, 50, 12);
    
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
