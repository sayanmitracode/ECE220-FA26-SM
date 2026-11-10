// Shape and two derived classes, Rectangle and Triangle (skeleton)
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
    double area() { return 0; }   // unknown shape
};

class Rectangle : public Shape {
  public:
    Rectangle(double a, double b) : Shape(a, b) {}
    double area() {
        // width_ by height_


    }
};

class Triangle : public Shape {
  public:
    Triangle(double a, double b) : Shape(a, b) {}
    double area() {
        // base width_, height height_


    }
};

int main() {
    Rectangle rec(3, 5);
    Triangle tri(4, 5);
    cout << "rec " << rec.area() << endl;
    cout << "tri " << tri.area() << endl;
    return 0;
}
