import java.awt.event.*;
import java.util.Arrays;

import javax.swing.*;


public class tm3 {
    interface ModelUpdate {
        public void update(int x, int y);
    }
    
    static class Model {
        private int player = 1;
        // 0 for empty, 1 for player 1 and 2 for player 2.
        private final int[][] cells = new int[7][6];
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

        public void getReplaced(int x, int y){
            int counter = 0;
            while (counter != 6) {
                
                if (cells[x][y+1] == 0) {
                    int temp = cells[x][y+1];
                    cells[x][y+1] = cells[x][y];
                    cells[x][y] = temp;
                }

                counter++;
            }
        }
        public int getCell(int x, int y) {
            return cells[x][y];
        }
        public boolean play(int x, int y) {
        
            if (cells[x][y] != 0)
                return false;

            cells[x][y] = player;
            for (int[] cell : cells) {
                System.out.println(Arrays.toString(cell));
            }
            System.out.println();
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
            return cells[0][2] != 0 && cells[0][2] == cells[1][1] && cells[0][2] == cells[2][0];
        }
    }

    @SuppressWarnings("Convert2Lambda")
    public static void main(String args[]) {  
        var cellSize = 70;
        var f = new JFrame("Morpion");
        f.setSize(cellSize*7,cellSize*7);
        var m = new Model();
        JButton[][] buttons = new JButton[7][6];
    
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 6; y++) {
                var b = new JButton("-");
                b.setBounds(x*cellSize,y*cellSize,cellSize,cellSize);
                final int X = x;
                final int Y = y;
                b.addActionListener(e -> {
                        m.play(X,Y);
                });
                f.add(b);
                buttons[x][y] = b;
            }
        }
    
        m.setUpdate(new ModelUpdate() {
            @SuppressWarnings("override")
            public void update(int x, int y) {
                buttons[x][y].setText(
                    switch (m.getCell(x,y)) {
                        case 0 -> "-";
                        case 1 -> "X";
                        case 2 -> "O";
                        default -> "?";
                    }
                );
                if (m.isFinished())
                    System.exit(1);
            }
        });
    
        f.setLayout(null);  
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        f.setVisible(true);
    }
}
