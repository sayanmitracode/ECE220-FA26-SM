// The library's vector<int>: an array that grows
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // a vector of four ints
    vector<int> intVector {1, 3, 5, 7};
    // two more at the end
    intVector.push_back(9);
    intVector.push_back(11);
    // print them, as with an array
    for (size_t i = 0; i < intVector.size(); i++)
        cout << intVector[i] << " ";
    cout << endl;
    return 0;
}
