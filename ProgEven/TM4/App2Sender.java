import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class App2Sender {
     public static void main(String[] args) throws ClassNotFoundException, IOException {
        var cA = new Channel<String>("20250204A");
        var cB = new Channel<String>("20250204B");
        //
        for(int x=0; x<5; x++) {
            cA.send(""+x);
            var r = cB.getNext();
            System.out.println(r);
        }
        
    }
}
