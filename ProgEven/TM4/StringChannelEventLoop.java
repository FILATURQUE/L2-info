import java.io.IOException;
import java.util.ArrayList;

interface MessageHandler {
    void handleMessage(String msg); 
}

public class StringChannelEventLoop {
    private Channel<String> channel;
    private ArrayList<MessageHandler> messageHandlerList;

    public StringChannelEventLoop(String channelName) {
        channel = new Channel<String>(channelName);
        messageHandlerList = new ArrayList<>();
    }

    public void onMessageHandler(MessageHandler newMessageHandler) {
        messageHandlerList.add(newMessageHandler);
    }

    public void removeMessageHandler(MessageHandler messageHandler) {
        messageHandlerList.remove(messageHandler);
    }

    public void start() throws ClassNotFoundException, IOException {
        for(;;) {
            var msg = channel.getNext();
            for(var messageHandler : messageHandlerList)
                messageHandler.handleMessage(msg);
        }
    }
}
