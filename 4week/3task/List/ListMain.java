public class ListMain {
    public static void main(String[] args) throws OutOfMemoryException, ZeroLenException {
        List a = new List(5, 1.2);

        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_back(6);
        a.push_back(7);

        for ( int i = 0; i < a.max_size(); i++ ) {
            System.out.println(a.toIndex(i));
        }
        System.out.println(a.size());
    }
}