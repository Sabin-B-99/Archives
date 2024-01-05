package com.ai.eightpuzzlesolver.gui;

import com.ai.eightpuzzlesolver.engine.StateTreeManager;
import com.ai.eightpuzzlesolver.engine.StateTreeNode;
import javafx.scene.paint.Color;

import java.util.HashMap;
import java.util.Map;

public class GUITreeGenerator {
    private Tree treeRoot;

    private StateTreeNode initialState;
    private StateTreeNode finalState;
    private StateTreeManager stateTreeManager;

    private static Map<Integer, Integer> numOfNodesInEachLevel = new HashMap<>();
    private static Map<Integer, Integer> numOfSlotAvailableInEachLevel = new HashMap<>();

    private static final int GAP_BETWEEN_SIBLINGS = 10;

    private final String method;

    private final String heuristic;

    private String stateReachingPath;

    public GUITreeGenerator(StateTreeNode initialState, StateTreeNode finalState, String method, String heuristic) {
        this.initialState = initialState;
        this.finalState = finalState;
        String rootStateText = stateText(initialState);
        Color rootNodeColor = getColorForNode(initialState);
        this.treeRoot = new Tree(new CircleWithText(rootStateText, rootNodeColor));
        this.stateTreeManager = new StateTreeManager(finalState);
        this.method = method;
        this.heuristic = heuristic;
    }

    public synchronized void generateStateSpace(){
        if(method.equalsIgnoreCase("A*")){
            char heuristicFlag = (heuristic.equals("manhtnDist")) ? 'm' : 'n';
            stateTreeManager.generateStateSpaceTreeAStar(initialState, heuristicFlag);
        } else if(method.equalsIgnoreCase("dfs")){
            stateTreeManager.generateStateSpaceTreeDFS(initialState);
        }else if(method.equalsIgnoreCase("bfs")) {
            stateTreeManager.generateStateSpaceTreeBFS(initialState);
        }else{
            stateTreeManager.generateStateSpaceTreeIDS(initialState);
        }
        if(stateTreeManager.puzzleSolved){
            this.stateReachingPath = stateTreeManager.getStateReachingPath();
            generateStateSpaceTree(treeRoot, initialState);
            findNumOfNodesInEachLevel(treeRoot);
            numOfSlotAvailableInEachLevel.putAll(numOfNodesInEachLevel);
        }
    }

    private void generateStateSpaceTree(Tree treeNode, StateTreeNode node){
        if(node != null && treeNode != null){
            StateTreeNode childState = null;
            Tree childTreeNode = null;
            numOfNodesInEachLevel.put(treeNode.getLevel(), 0);
            for (int i = 0; i < node.getChildren().size(); i++) {
                childState = node.getChildren().get(i);
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


    private String stateText(StateTreeNode node){
        return node.toString();
    }

    private Color getColorForNode(StateTreeNode node){
        if(node.isGoalState()){
            return Color.GREEN;
        } else {
            return Color.GRAY;
        }
    }

    public Tree getTreeRoot() {
        return treeRoot;
    }

    public String getMethod() {
        return method;
    }

    public String getStateReachingPath() {
        return stateReachingPath;
    }

    public StateTreeNode getInitialState() {
        return initialState;
    }

    public StateTreeNode getFinalState() {
        return finalState;
    }
}
