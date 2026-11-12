// getmin<Rectangle>: the template needs a < for Rectangle
#include <iostream>
using namespace std;

class Rectangle {
    int width_, height_;
  public:
    Rectangle(int w, int h) {
        width_ = w; height_ = h;
    }
    int area() const { return width_ * height_; }
    // smaller means smaller area
    bool operator<(const Rectangle &r) const {
        return area() < r.area();
    }
};

template <typename T>
T getmin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    Rectangle r1(3, 4), r2(2, 5);
    cout << getmin(r1, r2).area() << endl;
    return 0;
}

// Delete operator< from Rectangle: getmin<Rectangle> no
// longer compiles, because a < b has no meaning for it.
