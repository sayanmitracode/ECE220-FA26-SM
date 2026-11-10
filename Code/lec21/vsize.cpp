// sizeof an object before and after a virtual function is added
#include <iostream>
using namespace std;

class Plain {                  // Shape, no virtual function
  protected:
    double width_, height_;
  public:
    double area() { return 0; }
};

class Virt {                   // Shape with virtual area()
  protected:
    double width_, height_;
  public:
    virtual double area() { return 0; }
};

int main() {
    cout << sizeof(double) << " " << sizeof(void *) << endl;
    cout << sizeof(Plain) << " " << sizeof(Virt) << endl;
    return 0;
}
