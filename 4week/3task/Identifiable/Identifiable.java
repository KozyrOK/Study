class Identifiable  implements Cloneable {
    private int identNumber;
    private static int counter = 0;

    public Identifiable() {
        counter += 1;
        identNumber = counter;
    }

    public static int getLastId() {
        return counter;
    }

    public int getId() {
        return identNumber;
    }

    public Identifiable clone() throws CloneNotSupportedException {
        counter += 1;
        return (Identifiable) super.clone();
    }

    public String toString() {
        return "" + identNumber;
    }
}
