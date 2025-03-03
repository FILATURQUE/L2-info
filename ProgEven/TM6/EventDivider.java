
import java.util.ArrayList;

interface Callback{
    public void run();
}

class Clock{
    int time;
    ArrayList<Callback> cbList;

    public Clock(int ms){
        this.time = ms;
        cbList = new ArrayList<>();
    }

    public void addListener(Callback cb){
        cbList.add(cb);
    }

    public void rmListener(){
        for (Callback cb : cbList) {
            cbList.remove(cb);
        }
    }

    public void start() throws InterruptedException{
        for(;;){
            int i = 0;
            this.cbList.get(i).run();
            Thread.sleep(this.time);
            i++;
        }
    }
}

class Data {

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    public int i = 0; 
}

class Test1 {
    public static void main(String[] args) throws InterruptedException {
        var clock = new Clock(500);
        var data = new Data();
        clock.addListener(() -> {
            data.i++;
            System.out.println(data.i);
        });
        clock.start();
    }
}

class EventDivider{
    int i;
    ArrayList<Callback> cbList;
    int count = 0;

    public EventDivider(int i){
        if (i > 0);
        this.i = i;
        cbList = new ArrayList<>();
    }

    public void tick(){
        if (this.count < this.i-1) {
            this.count++;
        } else {
            this.count = 0;
            for (Callback cb : cbList) {
                cb.run();
        }
        }
    }

    public void addClockListener(Callback cb){
        cbList.add(cb);
    }

    public void rmListener(){
        for (Callback cb : cbList) {
            cbList.remove(cb);
        }
    }
    public static void main(String[] args) {
        var evdiv = new EventDivider(3);
        evdiv.addClockListener(() -> {
            System.out.println("Hey !");
        });
        for(int i = 0; i < 10; i++) {
            System.out.print("" + i + " ");
            evdiv.tick();
        }
        System.out.println();
    }

}     
