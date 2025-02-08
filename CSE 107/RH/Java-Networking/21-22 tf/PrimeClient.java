import java.io.*;
import java.net.*;

public class PrimeClient {
    public static void main(String[] args) {
        try {
            // Connect to the server running on localhost at port 8080
            Socket socket = new Socket("localhost", 8080);
            System.out.println("Connected to server.");

            // Create input and output streams for communication with the server
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

            // Define two integers to send to the server
            int num1 = 10; // Example integer
            int num2 = 50; // Example integer

            // Send the integers to the server
            oos.writeInt(num1);
            oos.writeInt(num2);
            oos.flush();
            System.out.println("Sent numbers to server: " + num1 + ", " + num2);

            // Receive the result (number of primes) from the server
            int primeCount = ois.readInt();
            System.out.println("Number of prime numbers between " + num1 + " and " + num2 + " is: " + primeCount);

            // Close resources
            oos.close();
            ois.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}