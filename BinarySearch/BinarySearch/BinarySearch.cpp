// BinarySearch.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <vector>
#include <iostream>

using namespace std;
class BinarySearch {
	vector<int> array;
	int length;
	int searchItem;
public:
	BinarySearch(vector<int> tablica, int wyszukanie) {
		this->array = tablica;
		this->searchItem = wyszukanie;
		this->length = array.size();
	}
	int find_Number() {
		int start = 0;
		int end = length - 1;
		while (start <= end)
		{
			int middle = (start + end) / 2;
			if (array[middle] == searchItem) return middle;
			else {
				if (array[middle] > searchItem) { end = middle - 1; }
				else {
					start = middle + 1;
				}
			}
		}
		return -1;
	}
	void fillNumbers() {
		for (int i = 0; i < length; i++) {
			array.push_back(rand() / 100);
		}
	}
	void bubbleSort() {
		int i, j;
		float temp;
		for ( i = 0; i < length; i++)
		{
			for (j = i + 1; j < length; j++) {
				if (array[j] < array[i]) {
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	void merge(vector<int> tablica, int poczatek, int srodek, int koniec) {
		int indexTab1 = srodek - poczatek + 1;
		int indexTab2 = koniec - srodek;

		
	}
	void mergeSort(vector<int> tablica, int początek, int koniec) {
		if (początek > koniec) return;
		int srodek = (początek + koniec) / 2;
		mergeSort(tablica, początek, srodek);
		mergeSort(tablica, srodek + 1, koniec);
		merge(tablica, początek, srodek, koniec);
	}
	void display() {
		if (find_Number() == -1) {
		cout << "Nie znaleznion liczby" << endl;
		}
		else {
			cout << " Znaleziono na miejscu: " << find_Number() << endl;
		}
	}
	
};
//int find_Number(vector<int> vec,int length,int searchItem) {
//	int start = 0;
//	int end = length - 1;
//	while (start<=end)
//	{
//		int middle = (start + end) / 2;
//		if (vec[middle] == searchItem) return middle;
//		else {
//			if (vec[middle] > searchItem) { end = middle - 1; }
//			else{
//				start = middle + 1;
//			}
//		}
//	}
//	return -1;
//}
int main()
{
	vector<int> a = { 11,23,35,44,51,59,62,71,88,91 };
	//int length = a.size();
	int lookin = 12;
	//int result = find_Number(a, length, lookin);
	//if (result == -1) {
	//	cout << "Nie znaleznion liczby" << endl;
	//}
	//else {
	//	cout << " Znaleziono na miejscu: " << result << endl;
	//}
	BinarySearch bs1 = { a,lookin };
	bs1.find_Number();
	bs1.display();

	
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
