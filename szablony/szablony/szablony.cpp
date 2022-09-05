// szablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>

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
int main()
{
    float pbok1 = 1.23, pbok2 = 3.2;
    std::cout << obwPr<int>(pbok1,pbok2) << std::endl;
    std::cout << polePr<float>(pbok1, pbok2) << std::endl;
    std::cout << obwKol( pbok2) << std::endl;
    std::cout << polKol(pbok1) << std::endl;
}

