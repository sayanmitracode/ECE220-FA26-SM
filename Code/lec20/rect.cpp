// Rectangle: a class with two constructors
#include <iostream>
using namespace std;

class Rectangle {
    int width_, height_;
  public:
    Rectangle();
    Rectangle(int, int);
    int area() const { return width_ * height_; }
};

Rectangle::Rectangle() {
    // set both width_ and height_ to 0
    width_ = 0;
    height_ = 0;
}

Rectangle::Rectangle(int w, int h) {
    // set width_ to w and height_ to h
    width_ = w;
    height_ = h;
}

int main() {
    Rectangle rect1(3, 4);
    Rectangle rect2;
    cout << "rect1: " << rect1.area() << endl;
    cout << "rect2: " << rect2.area() << endl;
    return 0;
}
