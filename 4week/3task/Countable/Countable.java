class Countable implements Cloneable {
    private static int count = 0;

    Countable() {
        count += 1;
    }

    public static int getCountable() {
        return count;
    }
    
    public Countable clone() throws CloneNotSupportedException {
        count += 1;
        return (Countable) super.clone();
    }
}