package com.badalsabin.ai.eightpuzzlebfsdfs.engine;

public class EngineMain {
    public static void main(String[] args) {
        int[][] initialState = {
                {2,8,3},
                {1,6,4},
                {7,-1,5}
        };
        int[][] finalState = {
                {1,2,3},
                {8,-1,4},
                {7,6,5}
        };

        StateTreeNode initialStateNode = new StateTreeNode(new Board(initialState));
        StateTreeNode finalStateNode = new StateTreeNode(new Board(finalState));

        StateTreeManager stateTreeManager = new StateTreeManager(finalStateNode);
        stateTreeManager.generateStateSpaceTreeBFS(initialStateNode);
        stateTreeManager.printChildState(initialStateNode);
    }
}
