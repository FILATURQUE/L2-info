import java.io.IOException;

public class App2Receiver {
    public static void main(String[] args) throws ClassNotFoundException, IOException {
        var cA = new Channel<String>("20250204A");
        var cB = new Channel<String>("20250204B");
        for(;;) {
            var r = cA.getNext();
            cB.send("Message reçu: " + r);
        }
    }
}