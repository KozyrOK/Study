public class InvalidDateException extends Exception{
    public String string;
    
    public InvalidDateException (String string) {
        this.string = string;
    }
}
