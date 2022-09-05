// szablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
T polePr(T pBok1, T pbok2) {
    return (pbok2 * pBok1);
}

template <typename T>
T obwPr(T pBok1, T pbok2) {
    return (2*pbok2 + 2 * pBok1);
}
int main()
{
    float pbok1 = 1.23, pbok2 = 3.2;
    std::cout << obwPr<int>(pbok1,pbok2) << std::endl;
}

