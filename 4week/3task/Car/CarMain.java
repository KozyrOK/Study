public class CarMain {

    public static void main(String[] args) throws ToMuchFuelException, OutOfFuelException {

    Point dist = new Point(2, 1);

    Car car = new Car();
    car.print();
    car.drive(dist);
    car.print();
    car.drive(1.0, 1.0);
    car.print();
    car.refill(10.0);
    car.print();
    }
}
