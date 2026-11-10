// orthovector derives from Lecture 20's vector: protected members
#include <iostream>
#include <cmath>

class vector {
  protected:
    double angle_, length_;
  public:
    vector() { angle_ = 0; length_ = 0; }
    vector(double a, double l) { angle_ = a; length_ = l; }
    double getAngle() { return angle_; }
    double getLength() { return length_; }
};

// along an axis: 0 R, 1 U, 2 L, 3 D
class orthovector : public vector {
  protected:
    int d_;
  public:
    orthovector(int dir, double l) {
        const double halfPI = 1.570796327;
        d_ = dir;
        angle_ = dir * halfPI;   // protected
        length_ = l;
    }
    double hypotenuse(const orthovector &b) {
        if ((d_ + b.d_) % 2 == 0)
            return length_ + b.length_;
        return sqrt(length_ * length_
                    + b.length_ * b.length_);
    }
};

int main() {
    orthovector f(0, 3), h(1, 4);
    std::cout << f.getAngle() << " " << h.getAngle()
              << std::endl;
    std::cout << f.hypotenuse(h) << std::endl;
    return 0;
}
