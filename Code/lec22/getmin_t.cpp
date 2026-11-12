// Function template: getmin written once, for any type with <
#include <iostream>
using namespace std;

template <typename T>
T getmin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << getmin(3, 5) << endl;
    cout << getmin(2.5, 1.5) << endl;
    cout << getmin('x', 'b') << endl;
    cout << getmin<double>(3, 2.5) << endl;
    return 0;
}

// Try getmin(3, 2.5) without <double>: T cannot be both
// int and double, so the compiler rejects the call.
