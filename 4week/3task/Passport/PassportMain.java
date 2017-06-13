public class PassportMain {
public static void main(String[] args) throws InvalidSerialException, InvalidDateException {
    Date a = new Date(28, 02, 1992);
    Date b = new Date(19, 07, 1983);
    Date c = new Date(18, 04, 1993);

    Passport.setSeries("YZ", 999999);

    Passport x = new Passport("Artem", "Kozyr", a);

    Passport y = new Passport("Viktoriya", "Pjadyk", b);

    Passport z = new Passport("Roman", "Voronin", c);

    System.out.println(x);
    System.out.println(y);
    System.out.println(z);
}
}
