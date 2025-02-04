package exceptions;

public class ExceptionMultipleCatch {
    public static void main(String args[]) {
        int a = 10, b = 0, c;
        try {
            c = a / b;
        } catch (ArithmeticException | NullPointerException e) {
            System.out.println(e);
            return;
        // } catch (NullPointerException e2) {
        //     System.out.println(e2);
        //     return;
        } catch(Exception e) {
            System.out.println(e);
            return;
        }
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}
