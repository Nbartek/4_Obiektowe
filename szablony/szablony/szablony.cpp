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
void ex3();
template<typename K>
std::string kolo(K promien) {
    K pp = 3.14 * (promien ^ 2);
    K obw = 2 * 3.14 * promien;
    return std::cout << "Pole kola to: " << pp << " obwod kola to: " << obw << std::endl;
}
template<typename K>
std::string kwadrat(K a) {
    K pp = a ^ 2;
    K obw = 4*a;
    return std::cout << "Pole kwadratu to: " << pp << " obwod kwadratu to: " << obw << std::endl;
}
template<typename P>
std::string prostokont(P a,P b) {
    P pp = a*b;
    P obw = 2 *a+2*b ;
    return std::cout << "Pole prostokonta to: " << pp << " owod prostokonta to: " << obw << std::endl;
}
int main()
{
    //ex1();
    //ex2();
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
void ex3(){
    std::cout << "Podaj co chesz : ";
    std::string win;
    std::getline(std::cin, win);
}