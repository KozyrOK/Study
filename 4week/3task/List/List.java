public class List {
    private int[] array;
    private int capacity;
    private double multiplier;
    private int current;

    public List(int capacity, double multiplier) throws OutOfMemoryException {
        this.capacity = capacity;
        this.multiplier = multiplier;
        this.current = 0;

        array = new int[capacity];

        if ( array == null ) {
            throw new OutOfMemoryException();
        }
    }

    public int size() {
        return this.current;
    }

    public int max_size() {
        return this.capacity;
    }

    public void erase(int index) throws ZeroLenException {
        if ( index >= 0 ) {
            for ( int i = index; i < current; i++ ) {
            array[i] = array[i+1];
            }
            pop_back();
        }
    }

    public void insert(int value, int index) throws OutOfMemoryException {
        if ( index >= 0 && index <= current ) {
            push_back(0);
            for ( int i = current - 1; i > index; i-- ) {
                array[i] = array[i-1];
            }
            array[index] = value;
        }
    }

    public int pop_back() throws ZeroLenException {
        if ( current <= 0 ) {
            throw new ZeroLenException();
        }
        current -= 1;
        return array[current];
    }

    public int find(int value) {
        for ( int i = 0; i < current; i++ ) {
            if ( array[i] == value ) {
                return i;
            }
        }
        return -1;
    }

    public void push_back(int value) throws OutOfMemoryException {
        int newCurrent = current + 1;

        if ( newCurrent > capacity ) {
            int newCapacity = (int)(capacity * multiplier);
            int[] newArray = new int[newCapacity];

            if ( newArray == null) {
                throw new OutOfMemoryException();
            }

            for ( int i = 0; i < capacity; i++ ) {
                newArray[i] = array[i];
            }
            capacity = newCapacity;
            array = newArray;
            newArray = null;
        }
        array[current] = value;
        current = newCurrent;
    }

    public void sort() {
        int buffer;
        boolean isSorted = false;

        for ( int i = current - 1; i > 0 && isSorted == false; i-- ) {
            isSorted = true;
            for ( int j = 0; j < i; j++ ) {
                if ( array[j] > array[j+1] ) {
                    isSorted = false;
                    buffer = array[j];
                
                    array[j] = array[j+1];
                    array[j+1] = buffer;
                }
            }
        }
    }

    public int toIndex(int index) {
        return this.array[index];
    }

    public boolean equals(List other) {
        if ( current != other.size() ) {
            return false;
        }

        for ( int i = 0; i < current; i++ ) {
            if ( array[i] != other.array[i] ) {
                return false;
            }
        }

        return true;
    }
}
