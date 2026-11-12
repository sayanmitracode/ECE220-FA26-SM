// One loop shape: array, linked list, vector, and list
#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct node { int data; node *next; };

int main() {
    int a[3] = {1, 2, 3};
    for (int *p = a; p != a + 3; p++)
        cout << *p << " ";
    cout << endl;

    node n3 = {3, NULL}, n2 = {2, &n3}, n1 = {1, &n2};
    for (node *q = &n1; q != NULL; q = q->next)
        cout << q->data << " ";
    cout << endl;

    vector<int> v {1, 2, 3};
    for (vector<int>::iterator it = v.begin();
         it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    list<int> l {1, 2, 3};
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
