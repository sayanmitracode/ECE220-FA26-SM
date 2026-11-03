// When do constructors and destructors run? Each one prints.
#include <iostream>
using namespace std;

class Rectangle {
    int width_, height_;
  public:
    Rectangle();
    Rectangle(int, int);
    ~Rectangle();
    int area() const { return width_ * height_; }
};

Rectangle::Rectangle() {
    width_ = 0;
    height_ = 0;
    cout << "construct 0x0" << endl;
}

Rectangle::Rectangle(int w, int h) {
    width_ = w;
    height_ = h;
    cout << "construct " << w << "x" << h << endl;
}

Rectangle::~Rectangle() {
    cout << "destruct " << width_ << "x"
         << height_ << endl;
}

int main() {
    Rectangle rect1(3, 4);
    cout << "rect1 area " << rect1.area() << endl;
    {
        Rectangle rect2;
        cout << "rect2 area " << rect2.area() << endl;
    }
    cout << "end of main" << endl;
    return 0;
}
