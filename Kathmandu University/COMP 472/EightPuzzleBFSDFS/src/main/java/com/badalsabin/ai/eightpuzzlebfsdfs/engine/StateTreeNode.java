package com.badalsabin.ai.eightpuzzlebfsdfs.engine;

import java.util.ArrayList;
import java.util.List;

public class StateTreeNode {

    private StateTreeNode previousNode;
    private Board currentBoardState;
    private List<StateTreeNode> children;

    private boolean goalState;
    private String operatorUsed;

    public StateTreeNode() {
        this.children = new ArrayList<>();
    }

    public StateTreeNode(Board currentBoardState) {
        this.currentBoardState = currentBoardState;
        this.children = new ArrayList<>();
        this.goalState = false;
    }


    public void addChild(StateTreeNode child){
        child.previousNode = this;
        this.children.add(child);
    }

    public StateTreeNode getPreviousNode() {
        return previousNode;
    }

    public void setPreviousNode(StateTreeNode previousNode) {
        this.previousNode = previousNode;
    }

    public Board getCurrentBoardState() {
        return currentBoardState;
    }

    public void setCurrentBoardState(Board currentBoardState) {
        this.currentBoardState = currentBoardState;
    }

    public List<StateTreeNode> getChildren() {
        return children;
    }

    public void setChildren(List<StateTreeNode> children) {
        this.children = children;
    }

    public boolean isGoalState() {
        return goalState;
    }

    public void setGoalState(boolean goalState) {
        this.goalState = goalState;
    }

    @Override
    public int hashCode() {
        return currentBoardState.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return currentBoardState.equals(((StateTreeNode) obj).getCurrentBoardState());
    }

    @Override
    public String toString() {
        return currentBoardState.toString();
    }

    public int getLevel() {
        int nodeLevel = 0;
        StateTreeNode parentNode = this.previousNode;
        while (parentNode != null){
            nodeLevel += 1;
            parentNode = parentNode.previousNode;
        }
        return nodeLevel;
    }

    public String findStateReachingPathFromRoot(){
        String path = "";
        StateTreeNode parentNode = this.previousNode;
        StateTreeNode currentNode = this;
        while (parentNode != null){
            path = path.concat(currentNode.operatorUsed);
            currentNode = parentNode;
            parentNode = parentNode.previousNode;
        }
        return path;
    }

    public String getOperatorUsed() {
        return operatorUsed;
    }

    public void setOperatorUsed(String operatorUsed) {
        this.operatorUsed = operatorUsed;
    }
}
