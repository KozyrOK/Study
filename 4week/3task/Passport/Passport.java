public class Passport {
    private static char newSeries[]={'A', 'A'};
    private static int newSerialNumber=1;

    private char[] series = new char[2];
    private int serialNumber;
    private String name;
    private String surname;
    private Date date;

    public static void validate(String series) throws InvalidSerialException {
        char[] buffer = series.toCharArray();

        if ( series.length() > 2 ) {
            throw new InvalidSerialException();
        }
        for ( int i = 0; i < 2; i++ ) {
            if ( buffer[i] < 'A' || buffer[i] > 'Z' ) {
                throw new InvalidSerialException();
            }
        }
    }

    public static void validate(int serialNumber) throws InvalidSerialException {
        if ( serialNumber < 1 || serialNumber > 999999 ) {
            throw new InvalidSerialException();
        }
    }

    public void seriesGenerator() throws InvalidSerialException {
        for ( int i = 0; i < 2; i++ ) {
            series[i] = newSeries[i];
        }
        serialNumber = newSerialNumber;
    
        if ( newSerialNumber < 999999 ) {
            newSerialNumber += 1;
        } else {
            newSerialNumber = 1;
            if ( newSeries[1] < 'Z' ) {
                newSeries[1] += 1;
            } else if ( newSeries[0] < 'Z') {
                newSeries[1] = 'A';
                newSeries[0] += 1;
            } else {
                throw new InvalidSerialException();
            }
        }
    }

    public Passport(String name, String surname, Date date) throws InvalidSerialException, InvalidDateException {
        this.name = name;
        this.surname = surname;
        this.date = date;

        this.seriesGenerator();
    }

    public String getSeries() {
        String buffer = String.valueOf(this.series);

        return buffer;
    }

    public int getSerialNumber() {
        return this.serialNumber;
    }

    public String getName() {
        return this.name;
    }

    public String getSurname() {
        return this.surname;
    }

    public Date getDate() {
        return this.date;
    }

    public static void setSeries(String series) throws InvalidSerialException {
        validate(series);

        char[] buffer = series.toCharArray();

        for ( int i = 0; i < 2; i++ ) {
            newSeries[i] = buffer[i];
        }
    }

    public static void setSeries(int serialNumber) throws InvalidSerialException {
        validate(serialNumber);

        newSerialNumber = serialNumber;
    }

    public static void setSeries(String series, int serialNumber) throws InvalidSerialException {
        setSeries(series);
        setSeries(serialNumber);
    }

    public String toString() {
        return "Passport: " + this.getSeries()
        + this.getSerialNumber() + '\n'
        + "Name: " + this.getName() + '\n'
        + "Surname: " + this.getSurname() + '\n'
        + "Date of Birth: " + this.getDate();
    }
}
