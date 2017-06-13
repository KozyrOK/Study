public class Date {
    private int day;
    private int month;
    private int year;
    
    public Date(int day, int month, int year) throws InvalidDateException {
        this.day = day;
        this.month = month;
        this.year = year;
        validate(day, month, year);
    }

    public void validate(int day, int month, int year) throws InvalidDateException {
        if (this.day < 1 || this.day > 31) { 
            throw new InvalidDateException("Invalid date");
        }
    
        boolean month31 = true;
        if (this.month == 2 || this.month == 4 || this.month == 6 || 
            this.month == 9 || this.month== 11) {
            month31 = false;
        }
    
        if (month31 == false && this.day == 31) {
            throw new InvalidDateException("Invalid date");
        }
    
        boolean leapYear = false;
    
        if (this.year % 400 == 0) {
            leapYear = true;
        } else if (this.year % 100 == 0) {
            leapYear = false;
        } else if (this.year % 4 == 0) {
            leapYear = true;
        }
    
        if (leapYear == false && this.month == 2 && this.day > 28) {
            throw new InvalidDateException("Invalid date");
        } else if (leapYear == true && this.month == 2 && this.day > 29) {
            throw new InvalidDateException("Invalid date");
        }
    
        if (this.month < 1 || this.month > 12) { 
            throw new InvalidDateException("Invalid date");
        }
    
        if (this.year < 1 || this.year > 9999) { 
            throw new InvalidDateException("Invalid date");
        }
}
    
    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }
    
    public int getYear() {
        return year;
    }

    public void print() {
        if (this.month < 10) {
            System.out.println(this.day+".0"+this.month+"."+this.year);
        } else {
            System.out.println(this.day+"."+this.month+"."+this.year);
        }
    }
}
