// Person with all three: copy constructor, assignment, destructor
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char *name_;
    int id_;
  public:
    Person(const char *name, int id);
    Person(const Person &p);                // 1
    Person &operator=(const Person &p);     // 2
    ~Person();                              // 3
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
    name_ = new char[48];
    strcpy(name_, p.name_);
    id_ = p.id_;
}

Person &Person::operator=(const Person &p) {
    if (this != &p) {     // skip p1 = p1
        strcpy(name_, p.name_);  // own block
        id_ = p.id_;
    }
    return *this;
}

Person::~Person() {
    delete[] name_;
}

int main() {
    Person p1("Jamie", 123456789);
    Person p2 = p1;     // copy constructor
    Person p3("Robin", 246813579);
    p3 = p1;            // copy assignment
    p2.setName("Alex");
    p3.setName("Sam");
    p1.show();
    p2.show();
    p3.show();
    return 0;
}
