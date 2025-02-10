import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class App1Sender {
     public static void main(String[] args) throws ClassNotFoundException, IOException {
        var c = new Channel<String>("test");
        //
        for(;;) {
            var input = System.console().readLine("> ");
            c.send(input);
        }
        
    }
}
