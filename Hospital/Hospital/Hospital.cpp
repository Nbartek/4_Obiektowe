
#include <iostream>
#include <string>
using namespace std;
class GroupUp {
public:
    virtual string display() = 0;
};
class Person: virtual public GroupUp {
protected:
    string firstName;
    string lastName;
public:
    Person(string imie, string nazwisko) {
        this->firstName = imie;
        this->lastName = nazwisko;
    }
     string display() {
        return "Imie: "+firstName+" Nazwisko: "+lastName;
    }
};
class Doctor: public Person {
protected:
    string speciality;
public:
    Doctor(  string imie,string nazwisko,string specjalizacja ):Person(imie,nazwisko) {
        this->speciality = specjalizacja;
        this->firstName = imie;
        this->lastName = nazwisko;
    }
    string display() {
      return  Person::display()+" Specjalizacja: "+speciality;
    }
};
class Ordynator : public Doctor {
private:
    string department;
public:
    Ordynator( string imie, string nazwisko, string specjalizacja, string oddzial) :Doctor(imie, nazwisko, specjalizacja) {
        this->speciality = specjalizacja;
        this->Person::lastName = nazwisko;
        this->Person::firstName = imie;
        this->department = oddzial;
    }
    string display() {
        return Doctor::display() + " Oddzial: "+department;
    }
};

class Hospital {
    string name;
    double bedCount;
public:
    Hospital(string name, double beds) {
        this->bedCount = beds;
        this->name = name;
    }
    void display() {
        cout << "Nazwa szpitala: " + name + " liczba miejsc: " + to_string(bedCount) << endl;;
    }
};
int main()
{
    Person p1 = { "Bartek","Xbox" };
    cout<<p1.display()<<endl;
    Doctor d1 = { "Gordon","Nintendo","Chirurgia"};
    cout << d1.display() << endl;
    Ordynator o1 = { "Daniel","PlayStation","Plastyk","Plastyczny"};
    cout << o1.display() << endl;
    Hospital h1 = { "Imienia Mickiewicza",231412 };
    h1.display();


}

