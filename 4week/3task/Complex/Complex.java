public class Complex {
    private double real;
    private double imaginary;
    
public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
}

public Complex() {
        this(0,0);
}

public double getReal() {
        return this.real;
}

public double getImaginary() {
        return this.imaginary;
}

public boolean equal(Complex other) {
        return this.real == other.real && this.imaginary == other.imaginary;
}

public void increment(Complex other){
    this.real += other.real;
    this.imaginary += other.imaginary;
}

public Complex sum(Complex other) {
    Complex a = this;
    a.increment(other);
        return a;
}

public void decrement(Complex other) {
    this.real -= other.real;
    this.imaginary -= other.imaginary;
}

public Complex diff(Complex other) {
    Complex a = this;
    a.decrement(other);
        return a;
}

public Complex multiply(Complex other) {
        Complex multiply = this;

        multiply.real *= other.real;
        multiply.imaginary *= other.imaginary;

        return multiply;
}

public void print() {
    System.out.println("("+this.real+";"+this.imaginary+"i"+")");
}

}