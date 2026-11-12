// In-class: function templates that work on any container
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// print every element of c
template <typename C>
void print_all(const C &c) {
    // loop from c.begin() to c.end(), print *it




    cout << endl;
}

// count the elements of c equal to x
template <typename C, typename T>
int count_eq(const C &c, T x) {
    int n = 0;
    // loop over c; add 1 to n when *it equals x




    return n;
}

int main() {
    vector<int> v {3, 1, 3, 2};
    list<char> l {'E', 'C', 'E', 'B'};
    print_all(v);
    print_all(l);
    cout << count_eq(v, 3) << " ";
    cout << count_eq(l, 'E') << endl;
    return 0;
}
