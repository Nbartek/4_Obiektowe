// Polygons.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>

using namespace std;
class Polygon {
private:
    vector<int> sides;
public:
    Polygon(vector<int> args) {
        sides = args;
    }
    int perimeter() {
        int result = 0;
        for (int side : sides) {
            result += side;
        }
        return result;
    }
    virtual double area() = 0;
};
class Rectangle : public Polygon {
    int a, b;
public:
    Rectangle(int a, int b) :Polygon({a,a,b,b}) {
        this->a = a;
        this->b = b;
    }

    double area() {
        return a * b;
    }
};
class Square : public Rectangle {
    int a;
public:
    Square(int a):Rectangle(a,a) {
        this->a = a;
    }
};
class Triangle : public Polygon {
    int a, b, c;
public:
    Triangle(int a, int b, int c) :Polygon({ a,b,c }) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double area() {
        float p = (a + b + c) / 2.0;
        float pt = sqrt(p * (p - a) * (p - b) * (p - c));
        return pt;
    }
};
int main()
{
    cout << "Prostokat" << endl;
    Rectangle rectangle(6, 9);
    cout << rectangle.perimeter() << endl;
    cout << rectangle.area() << endl;
    cout << "Kwadrat" << endl;
    Square square(12);
    cout << square.perimeter() << endl;
    cout << square.area() << endl;
    cout << "trojkat" << endl;
    Triangle trinagle(10, 10, 10);
    cout << trinagle.area() << endl;
    cout << trinagle.perimeter() << endl;
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
