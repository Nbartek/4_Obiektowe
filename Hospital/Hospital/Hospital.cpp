
#include <iostream>
using namespace std;
class Person {
    string firstName;
    string lastName;
public:
    Person(string imie, string nazwisko) {
        this->firstName = imie;
        this->lastName = nazwisko;
    }
    virtual string display() {
        return "Imie: "+firstName+" Nazwisko: "+lastName;
    }
};
class Doctor: public Person {
    string speciality;
public:
    Doctor( string imie, string nazwisko, string specjalizacja):Person(imie,nazwisko) {
        this->speciality = specjalizacja;
    }
    string display() {
        Person::display();
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

