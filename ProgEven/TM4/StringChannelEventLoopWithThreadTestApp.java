import java.io.IOException;

public class StringChannelEventLoopWithThreadTestApp {
    public static void main(String[] args) throws ClassNotFoundException, IOException {
        var eventloop = new StringChannelEventLoopWithThread("test");
        eventloop.onMessageHandler(new MessageHandler() {
            public void handleMessage(String msg) {
                System.out.println("Message reçu 1: " + msg);
            }
        });
        eventloop.onMessageHandler(new MessageHandler() {
            public void handleMessage(String msg) {
                System.out.println("Message reçu 2: " + msg);
            }
        });
        eventloop.onMessageHandler(new MessageHandler() {
            public void handleMessage(String msg) {
                if(msg.equals("nouveau message"))
                    System.exit(1);;
            }
        });
    }
}
