// Pure virtual function: Shape becomes an abstract class
#include <iostream>
using namespace std;

class Shape {
  protected:
    double width_, height_;
  public:
    Shape(double a, double b) {
        width_ = a; height_ = b;
    }
    virtual double area() = 0;   // pure virtual
};

class Rectangle : public Shape {
  public:
    Rectangle(double a, double b) : Shape(a, b) {}
    double area() { return width_ * height_; }
};

int main() {
    // Shape shape1(2, 4);   // error, see below
    Shape *ptr;              // allowed
    Rectangle rec(3, 5);
    ptr = &rec;
    cout << ptr->area() << endl;
    return 0;
}

// With the comment removed from the first line of main, g++ reports:
//   abstract.cpp:22:11: error: variable type 'Shape' is an abstract class
//      22 |     Shape shape1(2, 4);   // error, see below
//         |           ^
//   abstract.cpp:12:20: note: unimplemented pure virtual method 'area' in 'Shape'
//      12 |     virtual double area() = 0;   // pure virtual
//         |                    ^
//   1 error generated.
