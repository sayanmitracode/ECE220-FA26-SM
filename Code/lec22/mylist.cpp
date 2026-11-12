// A linked list as a class template; List is Node's friend
#include <iostream>
using namespace std;

template <typename T> class List;

template <typename T>
class Node {
    T data;
    Node<T> *next;
    Node(T d) { data = d; next = NULL; }
    friend class List<T>;   // List may use next
};

template <typename T>
class List {
    Node<T> *head;
  public:
    List() { head = NULL; }
    ~List() {
        while (head != NULL) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(T data) {      // insert at head
        Node<T> *ptr = new Node<T>(data);
        ptr->next = head;
        head = ptr;
    }
    void print() {
        Node<T> *cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    List<int> list1;
    list1.add(5);
    list1.add(2);
    list1.add(4);
    list1.print();
    List<char> list2;
    list2.add('B');
    list2.add('E');
    list2.print();
    return 0;
}
