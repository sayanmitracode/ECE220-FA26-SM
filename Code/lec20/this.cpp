// A member function receives the object's address in `this`
#include <iostream>

class vector {
    double angle_, length_;
  public:
    vector(double a, double l) { angle_ = a; length_ = l; }
    void scale(double k) {
        std::cout << "this = " << this << std::endl;
        this->length_ *= k;
    }
};

int main() {
    vector c(2.17, 4.29);
    std::cout << "size = " << sizeof(c) << std::endl;
    std::cout << "&c   = " << &c << std::endl;
    c.scale(2);
    return 0;
}
