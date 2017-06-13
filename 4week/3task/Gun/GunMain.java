public class GunMain {

    public static void main(String[] args) throws NotReadyException, OutOfRoundsException {
        Gun beretta = new Gun("beretta", 5);
        beretta.prepare();
        beretta.reload();
        beretta.shoot();
        beretta.prepare();
        beretta.print();
    }
}
