import java.util.ArrayList;

interface ValueListener {
    public void onValueUpdate(Boolean value);
}

class NORGate {
    ArrayList<ValueListener> cb = new ArrayList<>();
    boolean fInput;
    boolean sInput;
    boolean dft = false;

    void addOutputListener(ValueListener callback){
        cb.add(callback);   
    }
    
    void removeOutputListener(ValueListener callback){
        cb.remove(callback);
    }

    void setFirstInput(boolean value){
        fInput = value;
    }

    void setSecondInput(boolean value){
        sInput = value;
    }

    void updateOutput(){
        if ((this.fInput || this.sInput) != this.dft) {
            for (ValueListener v : this.cb) {
                v.onValueUpdate(!this.dft);
            }
        }
    }
    public static void main(String[] args) {
        var gate = new NORGate();
        var valueDisplayer = new ValueListener() {
        public void onValueUpdate(boolean v) {
            System.out.print("goes from " + !v + " to " + v);
            }
        };
            var booleanValues = new boolean[]{ false, true };
            for (var a1 : booleanValues) {
                for (var b1 : booleanValues) {
                    for (var a2 : booleanValues) {
                        for (var b2 : booleanValues) {
                            System.out.print("("+a1+","+b1+") -> ("+a2+","+b2+") ");
                            gate.setFirstInput(a1);
                            gate.setSecondInput(b1);
                            gate.updateOutput();
                            gate.addOutputListener(valueDisplayer);
                            gate.setFirstInput(a2);
                            gate.setSecondInput(b2);
                            gate.updateOutput();
                            gate.removeOutputListener(valueDisplayer);
                            System.out.println();
                    }
                }
            }
        }
    }
}

