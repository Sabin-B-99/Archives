package com.missionariescannibalsstatespacesimulator.gui;

import java.util.ArrayList;

public class Tree {
    private CircleWithText root;
    private ArrayList<Tree> children;
    private Tree parent;
    private int level;

    private String stateObtainedOnCondition;

    public Tree(CircleWithText root) {
        this.parent = null;
        this.root = root;
        this.children = new ArrayList<>();
        this.level = 0;
    }

    public void addChild(Tree child){
        child.parent = this;
        this.children.add(child);
        child.calculateLevel();
    }

    private void calculateLevel(){
        Tree parent = this.parent;
        while (parent != null){
            this.level += 1;
            parent = parent.parent;
        }
    }

    public int getLevel() {
        return level;
    }

    public CircleWithText getRoot() {
        return root;
    }

    public ArrayList<Tree> getChildren() {
        return children;
    }

    public Tree getParent() {
        return parent;
    }

    public String getStateObtainedOnCondition() {
        return stateObtainedOnCondition;
    }

    public void setStateObtainedOnCondition(String stateObtainedOnCondition) {
        this.stateObtainedOnCondition = stateObtainedOnCondition;
    }
}
