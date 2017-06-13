public class Mohican {
    private String name;
    private static Mohican lastMohican;
    private static Mohican prevMohican;

    public static Mohican getLast() {
        return lastMohican;
    }

    public Mohican(String name) {
        this.name = name;
        prevMohican = lastMohican;
        lastMohican = this;
    }

     public Mohican(Mohican other) {
        this.name = other.name;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return "" + name;
    }
}
