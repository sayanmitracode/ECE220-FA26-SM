// Class template: a pair of two values of one type T
#include <iostream>
using namespace std;

template <typename T>
class mypair {
    T a, b;
  public:
    mypair(T first, T second) {
        a = first; b = second;
    }
    T getmin();
};

template <typename T>
T mypair<T>::getmin() {
    T retval = (a < b) ? a : b;
    return retval;
}

int main() {
    mypair<int> myobject(100, 75);
    mypair<double> d(2.5, 1.5);
    cout << myobject.getmin() << endl;
    cout << d.getmin() << endl;
    cout << sizeof(myobject) << " ";
    cout << sizeof(d) << endl;
    return 0;
}
