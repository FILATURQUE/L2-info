import java.io.IOException;

public class StringChannelEventLoopTestApp {
    public static void main(String[] args) throws ClassNotFoundException, IOException {
        var eventloop = new StringChannelEventLoop("test");
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
        eventloop.start();
    }
}
