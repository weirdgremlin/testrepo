#include <iostream>
#include <iostream>
using namespace std;
int main() {
    int a[]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int* i = &a[0]; i != (&a[8] + 1);i ++){
        cout << *i;
    }
    return 0;
}
