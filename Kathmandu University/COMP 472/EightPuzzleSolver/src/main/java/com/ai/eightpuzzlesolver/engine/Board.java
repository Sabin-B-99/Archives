package com.ai.eightpuzzlesolver.engine;

import java.util.Arrays;

public class Board {

    public static final int EMPTY_ROW_COL_VALUE = -1;
    private int[][] state;


    public Board(int[][] state) {
        this.state = state;
    }

    public void setState(int[][] state) {
        this.state = state;
    }

    public int[][] getState() {
        return state;
    }

    public int[] getEmptyRowColPos() {
        int[] emptyRowColPos = {-1,-1};
        for (int row = 0; row < state.length; row++){
            for (int col = 0; col < state[row].length; col++) {
                if(state[row][col] == -1){
                    emptyRowColPos[0] = row;
                    emptyRowColPos[1] = col;
                }
            }
        }
        return emptyRowColPos;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Board board = (Board) o;
        return Arrays.deepEquals(state, board.state);
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(state);
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (int[] rows : state) {
            for (int rowColVal : rows) {
                if(rowColVal == -1){
                    builder.append("| ").append("X");
                }else {
                    builder.append("| ").append(rowColVal);
                }
            }
            builder.append("|\n");
        }
        return builder.toString();
    }
}
