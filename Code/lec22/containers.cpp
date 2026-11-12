// Function templates that work on any container with iterators
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// print every element of c
template <typename C>
void print_all(const C &c) {
    for (auto it = c.begin(); it != c.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// count the elements of c equal to x
template <typename C, typename T>
int count_eq(const C &c, T x) {
    int n = 0;
    for (auto it = c.begin(); it != c.end(); ++it)
        if (*it == x)
            n++;
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
