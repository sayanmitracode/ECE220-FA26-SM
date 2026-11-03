/* Adding two vectors in C: a struct, and functions that take it */
#include <stdio.h>
#include <math.h>

typedef struct VectorStruct {
    double angle, length;
} vector;

void scaleVector(vector *v, double k);
vector addVectors(vector a, vector b);

int main() {
    vector a = {1.5, 2}, b = {2.6, 3}, c;
    c = addVectors(a, b);
    scaleVector(&c, 2);
    printf("%f %f\n", c.length, c.angle);
    return 0;
}

void scaleVector(vector *v, double k) {
    v->length *= k;
}

vector addVectors(vector a, vector b) {
    vector c;
    double ax = a.length * cos(a.angle);
    double bx = b.length * cos(b.angle);
    double ay = a.length * sin(a.angle);
    double by = b.length * sin(b.angle);
    double cx = ax + bx;
    double cy = ay + by;
    c.length = sqrt(cx * cx + cy * cy);
    c.angle = acos(cx / c.length);
    return c;
}
