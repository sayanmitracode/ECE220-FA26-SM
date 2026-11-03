// Operator overloading: a + b for the vector class
#include <iostream>
#include <cmath>

class vector {
  protected:
    double angle_, length_;
  public:
    vector operator+(const vector &b) {
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
    // constructors and the other member functions
    vector() { angle_ = 0; length_ = 0; }
    vector(double a, double l) { angle_ = a; length_ = l; }
    double getAngle() { return angle_; }
    double getLength() { return length_; }
};

int main() {
    vector a(1.5, 2), b(2.6, 3);
    vector c = a + b;         // before: a.add(b)
    std::cout << c.getLength() << " "
              << c.getAngle() << std::endl;
    return 0;
}
