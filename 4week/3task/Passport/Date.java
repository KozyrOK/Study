public class Date implements Cloneable {
    private int day;
    private int month;
    private int year;

    public void validate (int day, int month, int year) throws InvalidDateException {
        if ( day < 1 || day > 31 ) {
            throw new InvalidDateException("InvalidDate!");
        }
        if ( month < 1 || month > 12 ) {
            throw new InvalidDateException("InvalidDate!");
        }
        if ( year == 0 ) {
            throw new InvalidDateException("InvalidDate!");
        }
        if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
            if ( day > 30 ) {
                throw new InvalidDateException("InvalidDate!");
            }
        }
        if ( month == 2 ) {
            if ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) {
                if ( day > 29 ) {
                    throw new InvalidDateException("InvalidDate!");
                }
            } else if ( day > 28 ) {
                throw new InvalidDateException("InvalidDate!");
            }
        }
    }

    public Date(int day, int month, int year) throws InvalidDateException {
        validate(day, month, year);

        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Date() {
        this.day = 1;
        this.month = 1;
        this.year = 1970;
    }

    public int getDay() {
        return this.day;
    }

    public int getMonth() {
        return this.month;
    }

    public int getYear() {
        return this.year;
    }

    public Date clone() throws CloneNotSupportedException {
        return (Date) super.clone();
    }

    public String toString() {
        return this.day + "." + this.month + "." + this.year;
    }
}
