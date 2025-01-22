public class GraduationSimulator {
    public static final int graduationLMAO(int batch, int jhamela, String uni) {
        int newJhamela = 0;
        int gradYear = batch + 4; 

        if (uni.equals("BUET")) { 
            newJhamela += jhamela; 
        }
        while (newJhamela > 0) {
            newJhamela++; 
            gradYear++;   
            System.out.println("Graduation delayed to: " + gradYear);
            try {
                Thread.sleep(500); 
            } catch (InterruptedException e) {
                System.err.println("Simulation interrupted."); //chat, is this real?
                break; 
            }
        }
        return gradYear; 
    }

    public static void main(String[] args) {
        int batch = 2022;     
        int jhamela = 1;     
        String uni = "BUET";
        System.out.println("Starting Graduation Simulation...");
        graduationLMAO(batch, jhamela, uni); 
    }
}
