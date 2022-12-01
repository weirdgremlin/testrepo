#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a = -INT32_MIN;
    int *b = static_cast<int*> (&a);
    cout << a << endl;
    for (int i = 0; i < sizeof(*b) * 8; i++)
        cout << ((*b >> i) & 1u) << ((i % 8 == 7)?"\n":"");
    return 0;
}