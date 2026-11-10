// The same program with a virtual area(): the object decides
#include <iostream>
using namespace std;

class Shape {
  protected:
    double width_, height_;
  public:
    Shape() { width_ = 0; height_ = 0; }
    Shape(double a, double b) {
        width_ = a; height_ = b;
    }
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
    Shape *ptr;
    Rectangle rec(3, 5);
    Triangle tri(4, 5);
    ptr = &rec;        // points to rec
    cout << "rec " << ptr->area() << endl;
    ptr = &tri;        // points to tri
    cout << "tri " << ptr->area() << endl;
    return 0;
}
