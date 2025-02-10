import java.io.IOException;

public class App1Receiver {
    public static void main(String[] args) throws ClassNotFoundException, IOException {
        var c = new Channel<String>("test");
        //c.send("hello");
        for(;;) {
            var r = c.getNext();
            System.out.println("Message reçu: " + r);
        }
        
    }
}