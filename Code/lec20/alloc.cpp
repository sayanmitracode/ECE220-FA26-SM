// Dynamic allocation in C++: new, delete, delete[]
#include <iostream>
using namespace std;

int main() {
    int *p, *q, i;
    p = new int;            // one int
    q = new int[10];        // array of 10
    *p = 220;
    for (i = 0; i < 10; i++)
        q[i] = i * i;
    cout << *p << " " << q[9] << endl;
    delete p;
    delete[] q;
    return 0;
}
