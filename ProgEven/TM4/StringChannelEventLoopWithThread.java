import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

interface MessageHandler {
    void handleMessage(String msg); 
}

public class StringChannelEventLoopWithThread {
    private Channel<String> channel;
    private ArrayList<MessageHandler> messageHandlerList;

    public StringChannelEventLoopWithThread(String channelName) {
        channel = new Channel<String>(channelName);
        messageHandlerList = new ArrayList<>();
        ExecutorService executor = Executors.newFixedThreadPool(1);
        executor.submit(() -> {
            try {
                start();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public void onMessageHandler(MessageHandler newMessageHandler) {
        messageHandlerList.add(newMessageHandler);
    }

    public void removeMessageHandler(MessageHandler messageHandler) {
        messageHandlerList.remove(messageHandler);
    }

    private void start() throws ClassNotFoundException, IOException {
        for(;;) {
            var msg = channel.getNext();
            for(var messageHandler : messageHandlerList)
                messageHandler.handleMessage(msg);
        }
    }
}
