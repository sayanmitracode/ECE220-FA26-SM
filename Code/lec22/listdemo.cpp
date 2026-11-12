// The library's list<float>: unique, remove, and an iterator loop
#include <iostream>
#include <list>
using namespace std;

void print(const list<float> &l) {
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    list<float> l {2.1, 3.2, 4.5, 3.2, 5.6, 5.6};
    l.unique();       // adjacent duplicates
    print(l);
    l.remove(4.5);    // remove every 4.5
    print(l);
    l.unique();
    print(l);
    return 0;
}
