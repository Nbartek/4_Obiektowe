// szablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include<cmath>
void ex1();
template <typename T>
T polePr(T pBok1, T pbok2) {
    return (pbok2 * pBok1);
}

template <typename T>
T obwPr(T pBok1, T pbok2) {
    return (2*pbok2 + 2 * pBok1);
}
template <typename J>
J obwKol(J promien) {
    return(2 * promien * 3.14);
}
template<typename J>
J polKol(J promien) {
    return(3.14 * (promien*promien));
}

template <typename D>
void  exchange1(D& a, D& b) {
    D temp = a;
    a = b;
    b = temp;
}
void ex2();
template <typename Z>
Z srednia(Z wyklad, Z cwiczenia, Z labolatorium, Z seminarium) {
    return((wyklad + cwiczenia + labolatorium + seminarium) / 4);
}
template<>
double srednia(double wyklad, double cwiczenia, double labolatorium, double seminarium) {
    return((wyklad + cwiczenia + labolatorium + seminarium) / 4);
}
int main()
{
    //ex1();
    ex2();
}

void ex1()
{
    float pbok1 = 1.23, pbok2 = 3.2;
    std::string jeden = "jeden", dwa = "dwa";
    char ds = 'b',qw='e';
    std::cout << obwPr<int>(pbok1,pbok2) << std::endl;
    std::cout << polePr<float>(pbok1, pbok2) << std::endl;
    std::cout << obwKol( pbok2) << std::endl;
    std::cout << polKol(pbok1) << std::endl;
    exchange1<std::string>(jeden, dwa);
    exchange1(ds, qw);
    std::cout << jeden << std::endl;
    std::cout << ds << std::endl;
}
void ex2() {
    std::cout << "srednia z ocen: " << srednia(3, 4, 3, 4) << std::endl;
}