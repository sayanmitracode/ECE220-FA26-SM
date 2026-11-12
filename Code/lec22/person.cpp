// Person with a deep-copy copy constructor
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char *name_;
    int id_;
  public:
    Person(const char *name, int id);
    Person(const Person &p);
    ~Person();
    void setName(const char *name) {
        strcpy(name_, name);
    }
    void show() const {
        cout << name_ << " " << id_ << endl;
    }
};

Person::Person(const char *name, int id) {
    name_ = new char[48];
    strcpy(name_, name);
    id_ = id;
}

Person::Person(const Person &p) {
    name_ = new char[48];    // its own block
    strcpy(name_, p.name_);  // copy the chars
    id_ = p.id_;
}

Person::~Person() {
    cout << "delete[] " << (void *)name_ << endl;
    delete[] name_;
}

int main() {
    Person p1("Jamie", 123456789);
    Person p2 = p1;          // copy constructor
    p2.setName("Alex");
    p1.show();
    p2.show();
    return 0;
}
