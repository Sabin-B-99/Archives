package com.missionariescannibalsstatespacesimulator.engine;

public class EngineMain {
    public static void main(String[] args) {
        ShoreState leftShoreState = new ShoreState(3,3, true, Shore.LEFT);
        ShoreState rightShoreState = new ShoreState(0,0,false, Shore.RIGHT);
        StateNode rootNode = new StateNode(leftShoreState, rightShoreState);
        EngineTreeGenerator.generateStateSpaceTree(rootNode);
        EngineTreeGenerator.printChildState(rootNode);
    }
}
