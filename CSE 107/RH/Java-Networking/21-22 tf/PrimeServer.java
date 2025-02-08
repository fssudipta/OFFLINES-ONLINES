import java.io.*;
import java.net.*;

public class PrimeServer {
    public static void main(String[] args) {
        try {
            // Create a server socket listening on port 8080
            ServerSocket serverSocket = new ServerSocket(8080);
            System.out.println("Server started and waiting for clients...");

            // Continuously accept client connections
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket);

                // Handle each client in a separate thread
                new ClientHandler(clientSocket).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ClientHandler extends Thread {
    private Socket clientSocket;

    public ClientHandler(Socket socket) {
        this.clientSocket = socket;
    }

    public void run() {
        try {
            // Create input and output streams for communication with the client
            ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());
            ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());

            // Read two integers from the client
            int num1 = ois.readInt();
            int num2 = ois.readInt();
            System.out.println("Received numbers from client: " + num1 + ", " + num2);

            // Calculate the number of prime numbers between the two integers
            int primeCount = countPrimes(num1, num2);

            // Send the result back to the client
            oos.writeInt(primeCount);
            oos.flush();
            System.out.println("Sent prime count to client: " + primeCount);

            // Close resources
            ois.close();
            oos.close();
            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to count prime numbers between two integers
    private int countPrimes(int start, int end) {
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                count++;
            }
        }
        return count;
    }

    // Method to check if a number is prime
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}