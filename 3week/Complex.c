#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} Complex;

void complexIncrement(Complex *this, Complex other) {
    this->re += other.re;
    this->im += other.im;
}

void complexDecrement(Complex *this, Complex other) {
    this->re -= other.re;
    this->im -= other.im;
}

Complex complexProduct(Complex a, Complex b) {
    Complex product;
    
    product.re = a.re * b.re - a.im * b.im;
    product.im = a.im * b.re + a.re * b.im;
    return product;
}

void complexMultiply(Complex *this, Complex other) {
    *this = complexProduct(*this, other);
}

Complex complexSum(Complex a, Complex b) {
    a.re += b.re;
    a.im += b.im;
    return a;
}

Complex complexDiff(Complex a, Complex b) {
    a.re -= b.re;
    a.im -= b.im;
    return a;
}

int complexEqual(Complex a, Complex b) {
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this) {
    return hypot(this.re, this.im);
}

void complexPrint(Complex this) {
    printf("%g%+gi", this.re, this.im);
}
