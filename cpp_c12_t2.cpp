#include <iostream>

using namespace std;

int main() {
    int a = 1;
    char b = 'a';
    float c = 1.1;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << "with -&a:" << endl;
    cout << &a - reinterpret_cast<int*>(&a) << endl;
    cout << &b - reinterpret_cast<char*>(&a) << endl;
    cout << &c - reinterpret_cast<float*>(&a) << endl;
    return 0;
}
