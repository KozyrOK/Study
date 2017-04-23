#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Vector;

Vector vectorSum(Vector a, Vector b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector vectorDiff(Vector a, Vector b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

void vectorIncrement(Vector *this, Vector other) {
    *this = vectorSum(*this, other);
}

void vectorDecrement(Vector *this, Vector other) {
    *this = vectorDiff(*this, other);
}

int vectorEqual(Vector a, Vector b) {
    return a.x == b.x && a.y == b.y;
}

double vectorLen(Vector this) {
    return hypot(this.x, this.y);
}

void vectorPrint(Vector this) {
    printf("(%g, %g)", this.x, this.y);
}
