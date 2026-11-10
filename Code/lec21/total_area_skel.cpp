// Add up the areas of different shapes through one Shape * array (skeleton)
#include <iostream>
using namespace std;

class Shape {
  protected:
    double width_, height_;
  public:
    Shape(double a, double b) {
        width_ = a; height_ = b;
    }
    virtual double area() = 0;
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

class Square : public Rectangle {
  public:
    Square(double s) : Rectangle(s, s) {}
};

double total_area(Shape *s[], int n) {
    // add up the n areas




}

int main() {
    Rectangle rec(3, 5);
    Triangle tri(4, 5);
    Square sq(2);
    Shape *list[3] = {&rec, &tri, &sq};
    cout << total_area(list, 3) << endl;
    return 0;
}
