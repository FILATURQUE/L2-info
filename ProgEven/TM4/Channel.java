//package frontJava.padiflac;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.Serializable;
import java.io.StreamCorruptedException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Random;
import java.nio.charset.StandardCharsets;


import javax.net.ssl.HttpsURLConnection;


public class Channel<T> {
    private final String channel_name;
    private final Queue<T> events = new ArrayDeque<>();
    private int id = 0;
    private static final String addr = "https://prog-reseau-m1.lacl.fr/padiflac/";

    private static final String nonce =
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    private static final Random r = new Random();	
	
    private String genNonce() {
	char[] sb = new char[64];
	for(int i=0; i<64;i++) {
	    sb[i] = nonce.charAt(r.nextInt(62));
	}
	return new String(sb);
    }
	
    public Channel(String channel_name) {
	this.channel_name = channel_name;
    }
	
    private byte[] serializeToString(T o) throws IOException {
	if (o instanceof String)
	    return ((String)o).getBytes(StandardCharsets.UTF_8) ;
	ByteArrayOutputStream stream = new ByteArrayOutputStream();
	ObjectOutputStream oos = new ObjectOutputStream(stream);
	oos.writeObject(o);
	oos.close();
	return stream.toByteArray();
    }
	
    @SuppressWarnings("unchecked")
    private T unserializeFromString(byte[] s) throws IOException, ClassNotFoundException {
	try {		
	    ByteArrayInputStream stream = new ByteArrayInputStream(s);
	    ObjectInputStream ois = new ObjectInputStream(stream);
	    T readObj = (T) ois.readObject();
	    ois.close();
	    return readObj;
	}catch(StreamCorruptedException e) {
	    return (T) new String(s);
	}catch(EOFException e) {
	    return (T) new String(s);
	}
    }

    /*    private static String toString(byte[] array) {
	StringBuilder str = new StringBuilder().append("[");
	for (int i=0;i<Math.min(array.length,15);i++) {
	    byte b = array[i];
	    if (b>=32 && b<127)
		str.append((char)b);
	    else
		str.append(b&0xFF);
	    str.append(", ");
	}
	if (array.length <= 15) {
	    str.setLength(str.length()-2);
	    str.append("]");
	}
	else
	    str.append("...");
	return str.toString();
	} */
	
    private void parseEvent(byte[] bb, int i) throws ClassNotFoundException, IOException {
	StringBuilder sb = new StringBuilder();
	while(i<bb.length) {
	    byte b = bb[i];
	    if(b=='|')break;
	    sb.append((char)b);
	    i++;
	}
	i++;
	if(i<bb.length) {
	    int size = Integer.parseInt(sb.toString());
	    byte[] buff = java.util.Arrays.copyOfRange(bb, i, i+size);
	    // System.out.printf("Received: %s%n",toString(buff));
	    T t = unserializeFromString(buff);
	    events.add(t);
	    parseEvent(bb, i+size);
	}else {
	    id =Integer.parseInt(sb.toString());
	}
    }
	
    private void connect() throws IOException, ClassNotFoundException {
	String id2 = "";
	if (id>0) {
	    id2 = "?id="+id;
	}
	URL u;
	try {
	    u = new URL(addr+channel_name+id2);
	    URLConnection uc = u.openConnection();
	    InputStream is = uc.getInputStream();
	    parseEvent(is.readAllBytes(),0);
	} catch (MalformedURLException e) {
	    throw new AssertionError(e);
	}
    }
	
    public T getNext() throws IOException, ClassNotFoundException {
	while (events.isEmpty()) {
	    connect();
	}
	return events.poll();
    }
	
		
    public void send(T s) throws IOException, ClassNotFoundException {
	//Make sure connect have been called to enforce that the channel contain type T.
	if(id==0)
	    connect();
	URL u;
	try {
	    String non = genNonce();
	    u = new URL(addr+channel_name+"?nonce="+non);
	    HttpsURLConnection uc = (HttpsURLConnection)u.openConnection();
	    uc.setRequestMethod("POST");
	    uc.setDoOutput(true);
	    OutputStream os = uc.getOutputStream();
	    os.write(serializeToString(s));
	    os.close();
	    uc.connect();
	    byte[] result = uc.getInputStream().readAllBytes();
	    // result should be ['O','K'] = [79, 75]
	    if (!java.util.Arrays.equals(result,OK)) {
		throw new IOException("Unexpected answer from server");
	    }
	} catch (MalformedURLException e) {
	    throw new AssertionError(e);
	}
    }
    private static final byte[] OK = {'O','K'};
	
    static class Test implements Serializable {		
	private static final long serialVersionUID = -8039544355798053477L;
	String f1;
	int f2;
	public Test(String f1,int f2) {
	    this.f1 = f1;
	    this.f2 = f2;
	}
	@Override
	public String toString() {
	    return "Test [f1=" + f1 + ", f2=" + f2 + "]";
	}	
    }
	
    public static void testObject() throws ClassNotFoundException, IOException {
	Channel<Test> c = new Channel<>("JavaTestObject");
	c.send(new Test("toto2",15));
	for(;;) {
	    System.out.println(c.getNext());
	}
    }

    private static String escape(String s) {
	StringBuilder str = new StringBuilder();
	var c = s.codePoints();
	c.forEachOrdered(i -> {
		if (Character.isISOControl(i)) {
		    str.append("\\").append(String.format("%03o",i));
		} else {
		    str.append(Character.toString(i));
		}
	    });
	return str.toString();
    }							    
    
    public static void testString() throws IOException, ClassNotFoundException {
	Channel<String> c = new Channel<>("ChatTest");
	c.send("TestJavaObject");
	for(;;) {
	    System.out.println(escape(c.getNext()));
	}
    }
	
    public static void main(String[] args) throws ClassNotFoundException, IOException {
	//testObject();
	testString();
    }
	
}
