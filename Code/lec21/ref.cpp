// A reference is another name for an existing variable
#include <iostream>
using namespace std;

int main() {
    int var = 5;
    int &ref = var; // permanent alias of var
    int *ptr = &var; // re-pointable

    ref = 10;
    cout << "var = " << var << endl;
    var = 15;
    cout << "ref = " << ref << endl;
    *ptr = 20;
    cout << "ref = " << ref << endl;
    cout << (&ref == &var) << endl;
    return 0;
}
