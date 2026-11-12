// How a vector grows: size, capacity, and where element 0 lives
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        cout << v.size() << " " << v.capacity()
             << " " << &v[0] << endl;
    }
    return 0;
}
