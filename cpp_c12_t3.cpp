#include <iostream>

using namespace std;

int main() {
    int a = static_cast<int>(UINT16_MAX);
    unsigned int b = static_cast<unsigned int>(INT16_MAX);
    cout << a << endl;
    cout << b << endl;
    return 0;
}

//
// Created by zer-oRBT on 24.11.2022.
//
