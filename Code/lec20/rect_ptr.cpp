// Objects through pointers: ->, new, delete, delete[]
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
    width_ = 0;
    height_ = 0;
}

Rectangle::Rectangle(int w, int h) {
    width_ = w;
    height_ = h;
}

int main() {
    Rectangle rect1(3, 4);
    Rectangle *r_ptr1 = &rect1;
    // print rect1's area through r_ptr1
    cout << r_ptr1->area() << endl;

    Rectangle *r_ptr2 = new Rectangle(5, 6);
    // print the area of *r_ptr2
    cout << r_ptr2->area() << endl;

    Rectangle *r_ptr3 = new Rectangle[2]{
        Rectangle(), Rectangle(2, 4)};
    // print the areas of both rectangles
    cout << r_ptr3[0].area() << endl;
    cout << r_ptr3[1].area() << endl;

    // deallocate the heap memory
    delete r_ptr2;
    delete[] r_ptr3;
    return 0;
}
