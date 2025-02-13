import java.io.IOException;

interface ModelUpdate {
    public void update(int x, int y);
}

class Model {
    private int player = 1;
    // 0 for empty, 1 for player 1 and 2 for player 2.
    private int[][] cells = new int[3][3];
    private void changePlayer() {
        player = (this.player == 1) ? 2 : 1;
    }
    private ModelUpdate update_cb = null;

    public void setUpdate(ModelUpdate up) {
        update_cb = up;
    }
    public int getPlayer() {
        return player;
    }
    public int getCell(int x, int y) {
        return cells[x][y];
    }
    public boolean play(int x, int y) {
        if (cells[x][y] != 0)
            return false;
        cells[x][y] = player;
        if (update_cb != null)
            update_cb.update(x, y);
        changePlayer();
        return true;
    }
    public boolean isFinished() {
        for (int i = 0; i < 3; i++) {
            if (cells[i][0] != 0 && cells[i][0] == cells[i][1] && cells[i][0] == cells[i][2])
                return true;
            if (cells[0][i] != 0 && cells[0][i] == cells[1][i] && cells[0][i] == cells[2][i])
                return true;
        }
        if (cells[0][0] != 0 && cells[0][0] == cells[1][1] && cells[0][0] == cells[2][2])
            return true;
        if (cells[0][2] != 0 && cells[0][2] == cells[1][1] && cells[0][2] == cells[2][0])
            return true;
        return false;
    }
}

public class Morpion4 {

    
    public static void main(String[] args) throws ClassNotFoundException, IOException {  

        
    } 
}

