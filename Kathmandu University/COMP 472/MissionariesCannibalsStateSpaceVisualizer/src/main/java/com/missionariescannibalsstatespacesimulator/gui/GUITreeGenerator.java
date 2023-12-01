package com.missionariescannibalsstatespacesimulator.gui;

import com.missionariescannibalsstatespacesimulator.engine.EngineTreeGenerator;
import com.missionariescannibalsstatespacesimulator.engine.Shore;
import com.missionariescannibalsstatespacesimulator.engine.ShoreState;
import com.missionariescannibalsstatespacesimulator.engine.StateNode;
import javafx.scene.paint.Color;

import java.util.HashMap;
import java.util.Map;

public class GUITreeGenerator {
    private Tree treeRoot;
    private ShoreState leftShoreState = new ShoreState(3,3, true, Shore.LEFT);
    private ShoreState rightShoreState = new ShoreState(0,0,false, Shore.RIGHT);
    private StateNode rootNode = new StateNode(leftShoreState, rightShoreState);

    private static Map<Integer, Integer> numOfNodesInEachLevel = new HashMap<>();
    private static Map<Integer, Integer> numOfSlotAvailableInEachLevel = new HashMap<>();

    private static final int GAP_BETWEEN_SIBLINGS = 10;

    public GUITreeGenerator() {
        String rootStateText = stateText(rootNode);
        Color rootNodeColor = getColorForNode(rootNode);
        this.treeRoot = new Tree(new CircleWithText(rootStateText, rootNodeColor));
    }

    public synchronized void generateStateSpace(){
        EngineTreeGenerator.generateStateSpaceTree(rootNode);
        generateStateSpaceTree(treeRoot, rootNode);
        findNumOfNodesInEachLevel(treeRoot);
        numOfSlotAvailableInEachLevel.putAll(numOfNodesInEachLevel);
    }

    private void generateStateSpaceTree(Tree treeNode, StateNode stateNode){
        if(stateNode != null && treeNode != null){
            StateNode childState = null;
            Tree childTreeNode = null;
            numOfNodesInEachLevel.put(treeNode.getLevel(), 0);
            for (int i = 0; i < stateNode.getChildren().size(); i++) {
                childState = stateNode.getChildren().get(i);
                String nodeText = stateText(childState);
                Color color = getColorForNode(childState);
                CircleWithText circleWithText = new CircleWithText(nodeText, color);
                childTreeNode = new Tree(circleWithText);
                childTreeNode.setStateObtainedOnCondition(childState.getOperatorUsed());
                treeNode.addChild(childTreeNode);
                generateStateSpaceTree(childTreeNode, childState);
            }
        }
    }

    private void findNumOfNodesInEachLevel(Tree treeNode){
        if(treeNode != null){
            Tree childTreeNode = null;
            numOfNodesInEachLevel.put(treeNode.getLevel(),
                    numOfNodesInEachLevel.get(treeNode.getLevel()) + 1);
            for (int i = 0; i < treeNode.getChildren().size(); i++) {
                childTreeNode = treeNode.getChildren().get(i);
                findNumOfNodesInEachLevel(childTreeNode);
            }
        }
    }

    public static void calculateAndSetupPositionOfNodeInScene(Tree node){
        int levelOfCurrentNode = node.getLevel();
        int slotNumInRow = -1;
        double yPosRaw = levelOfCurrentNode;
        int numOfSlotAvailableInCurrentLevel = numOfSlotAvailableInEachLevel.get(levelOfCurrentNode);
        slotNumInRow = numOfNodesInEachLevel.get(levelOfCurrentNode) - numOfSlotAvailableInCurrentLevel;
        numOfSlotAvailableInEachLevel.put(levelOfCurrentNode, numOfSlotAvailableInCurrentLevel - 1);
        double xPosRaw = slotNumInRow + GAP_BETWEEN_SIBLINGS;
        node.getRoot().setNodeXYPos(xPosRaw, yPosRaw);
    }


    private String stateText(StateNode node){
        StringBuilder builder = new StringBuilder();
        ShoreState leftState = node.getLeftShoreState();
        ShoreState rightState = node.getRightShoreState();
        builder.append("L: ").append(leftState.getNumOfMissionaries()).append('M')
                .append(" | ").append(leftState.getNumOfCannibals()).append('C')
                .append(" | ").append(leftState.isBoat()?'B':'X');
        builder.append("\n");
        builder.append("R: ").append(rightState.getNumOfMissionaries()).append('M')
                .append(" | ").append(rightState.getNumOfCannibals()).append('C')
                .append(" | ").append(rightState.isBoat()?'B':'X');
        builder.append("\n");
        return builder.toString();
    }

    private Color getColorForNode(StateNode node){
        if(node.isGoalState()){
            return Color.GREEN;
        }else if(node.isDead()){
            return Color.RED;
        }else {
            return Color.GRAY;
        }
    }

    public Tree getTreeRoot() {
        return treeRoot;
    }
}
