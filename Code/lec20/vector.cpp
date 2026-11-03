// Adding two vectors in C++: a class with member functions
#include <iostream>
#include <cmath>

class vector {
    double angle_, length_;
  public:
    vector();
    vector(double a, double l);
    double getAngle() { return angle_; }
    double getLength() { return length_; }
    void scale(double k) { length_ *= k; }
    vector add(vector b);
};

int main() {
    vector a(1.5, 2), b(2.6, 3), c;
    c = a.add(b);
    c.scale(2);
    std::cout << c.getLength() << " "
              << c.getAngle() << std::endl;
    return 0;
}

vector::vector() {
    angle_ = 0;
    length_ = 0;
}

vector::vector(double a, double l) {
    angle_ = a;
    length_ = l;
}

vector vector::add(vector b) {
    vector c;
    double ax = length_ * cos(angle_);
    double bx = b.length_ * cos(b.angle_);
    double ay = length_ * sin(angle_);
    double by = b.length_ * sin(b.angle_);
    double cx = ax + bx;
    double cy = ay + by;
    c.length_ = sqrt(cx * cx + cy * cy);
    c.angle_ = acos(cx / c.length_);
    return c;
}
