// swap three ways: by value, by pointer, and by reference
#include <iostream>
using namespace std;

void swap_val(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_ptr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 2, y = 3;
    swap_val(x, y);
    cout << "val: " << x << " " << y << endl;
    swap_ptr(&x, &y);
    cout << "ptr: " << x << " " << y << endl;
    swap_ref(x, y);
    cout << "ref: " << x << " " << y << endl;
    return 0;
}
