import java.io.IOException;

public class test {

    public static String getNext(Channel c) throws ClassNotFoundException, IOException{
        String r = (String) c.getNext();
        return r;
    }

    public static void main(String[] args) throws ClassNotFoundException, IOException {
        var c = new Channel<>("eiogjiodfjigofjgodfgdfjigdfilgdjfgldkf");
        c.send("Game STARTO");
        System.out.println(test.getNext(c));
    }
}
