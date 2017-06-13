public class Car {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point location;
    private String model;

    public Car(double capacity, double consumption, Point location, String model) {
        if ( capacity < 0 ) {
            capacity = 60;
        }
        if ( consumption < 0 ) {
            consumption = 0.6;
        }
        this.fuelAmount = capacity;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
    }

    public Car(double capacity, double consumption, double x, double y, String model) {
        Point location = new Point(x, y);
        if ( capacity < 0 ) {
            capacity = 60;
        }
        if ( consumption < 0 ) {
            consumption = 0.6;
        }
        this.fuelAmount = capacity;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
    }

    public Car(double capacity, double consumption, String model) {
        this(capacity, consumption, 0, 0, model);
    }

    public Car() {
        this(60, 0.6, 0, 0, "Mercedes");
    }

    public double getFuelAmount() {
        return this.fuelAmount;
    }

    public double getFuelCapacity() {
        return this.fuelCapacity;
    }

    public double getFuelConsumption() {
        return this.fuelConsumption;
    }
    
    public Point getLocation() {
        return this.location;
    }

    public String getModel() {
        return this.model;
    }

    public void drive(Point destination) throws OutOfFuelException {
        double fuelNeeded;
        double distance;

        distance = location.distance(destination);
        fuelNeeded = distance * fuelConsumption;
        if ( fuelNeeded > fuelAmount ) {
            throw new OutOfFuelException();
        }
        fuelAmount -= fuelNeeded;
        location = destination;
    }

    public void drive(double x, double y) throws OutOfFuelException {
        drive(new Point(x,y));
    }

    public void refill(double fuel) throws ToMuchFuelException {
        double NewFuelAmount = fuelAmount;
        NewFuelAmount += fuel;
        if (NewFuelAmount > fuelCapacity) {
            throw new ToMuchFuelException();
        }
        fuelAmount = NewFuelAmount;
    }
    
    public void print() {
        System.out.println("Model: "+ this.model + "\n"
                            +"Location: " + this.location + "\n"
                            +"Fuel consumption: " + this.fuelConsumption + "\n"
                            +"Fuel amount: " + this.fuelAmount + "\n"
                            +"Fuel capacity: " + this.fuelCapacity);
    }
}
