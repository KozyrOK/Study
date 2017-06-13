public class ComplexMain {

    public static void main(String[] args) {
        Complex a = new Complex(5, 10);
        Complex b = new Complex (2, 5);
        b.print();
        
        b.increment(a);
        
        a.print();
        b.print();

    }

}