// Function overloading (Lecture 20): the same body written twice
#include <iostream>
using namespace std;

int getmin(int a, int b) {
    return (a < b) ? a : b;
}

double getmin(double a, double b) {
    return (a < b) ? a : b;
}

int main() {
    cout << getmin(3, 5) << endl;
    cout << getmin(2.5, 1.5) << endl;
    return 0;
}

// Try adding getmin(3, 2.5) to main: neither version matches
// better than the other, so the compiler rejects the call.
