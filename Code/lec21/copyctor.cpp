// Copy constructor: what is copied when a vector is passed by value
#include <iostream>

class vector {
  protected:
    double angle_, length_;
  public:
    vector(double a, double l) {
        angle_ = a; length_ = l;
    }
    // copy constructor
    vector(const vector &obj) {
        angle_ = obj.angle_;
        length_ = obj.length_;
        std::cout << "copy" << std::endl;
    }
    double getLength() const { return length_; }
};

double len_val(vector v) { return v.getLength(); }
double len_ref(const vector &v) {
    return v.getLength();
}

int main() {
    vector a(1.5, 2);
    vector b = a;
    std::cout << b.getLength() << std::endl;
    std::cout << len_val(a) << std::endl;
    std::cout << len_ref(a) << std::endl;
    return 0;
}
