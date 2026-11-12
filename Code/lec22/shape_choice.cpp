// The object ptr points to is chosen by the input, not by the compiler
#include <iostream>
using namespace std;

class Shape {
  protected:
    double width_, height_;
  public:
    Shape(double a, double b) { width_ = a; height_ = b; }
    virtual double area() { return 0; }
};

class Rectangle : public Shape {
  public:
    Rectangle(double a, double b) : Shape(a, b) {}
    double area() { return width_ * height_; }
};

class Triangle : public Shape {
  public:
    Triangle(double a, double b) : Shape(a, b) {}
    double area() { return width_ * height_ / 2; }
};

int main() {
    Rectangle rec(3, 5);
    Triangle tri(4, 5);
    Shape *ptr;
    int which;
    cin >> which;
    if (which == 1) ptr = &rec;
    else            ptr = &tri;
    // 15 or 10?
    cout << ptr->area() << endl;
    return 0;
}
