package interfaces;

interface Alpha {
    default void reset() {
        System.out.println("Alpha's reset");
    }
}

interface Beta {
    default void reset() {
        System.out.println("Beta's reset");
    }
}

public class InterfaceMultipleInheritanceTest implements Alpha, Beta {
    @Override
    public void reset() {
        //System.out.println("Beta's reset");
        Alpha.super.reset();
        Beta.super.reset();
    }
    public static void main(String[] args) {
        InterfaceMultipleInheritanceTest check=new InterfaceMultipleInheritanceTest();
        check.reset();
    }
}


