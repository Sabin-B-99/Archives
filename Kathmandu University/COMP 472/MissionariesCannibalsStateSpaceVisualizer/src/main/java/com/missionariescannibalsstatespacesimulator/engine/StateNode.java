package com.missionariescannibalsstatespacesimulator.engine;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;

public class StateNode {

    public static final HashSet<StateNode> exploredNodes = new HashSet<>();

    private ShoreState leftShoreState;
    private ShoreState rightShoreState;

    private boolean dead;

    private ArrayList<StateNode> children;
    private StateNode parent;

    private boolean goalState;

    private String operatorUsed;

    public StateNode(ShoreState leftShoreState, ShoreState rightShoreState) {
        this.leftShoreState = leftShoreState;
        this.rightShoreState = rightShoreState;
        this.parent = null;
        this.children = new ArrayList<>();
        this.dead = false;
    }


    private void addChild(StateNode childNode){
        childNode.parent = this;
        this.children.add(childNode);
    }



    public void generateChildNodes(){
        StateNode childState = null;
        Shore shoreWithBoat = getShoreWithBoat();
        if(!this.dead && !this.goalState){
            for (Operators op: Operators.values()) {
                if(operatorCanBeApplied(op, shoreWithBoat)){
                    childState = (shoreWithBoat == Shore.LEFT) ? applyOperatorToLeftShore(op): applyOperatorToRightShore(op);
                    childState.checkAndMarkDead();
                    childState.checkAndMarkGoal();
                    if(!exploredNodes.contains(childState)){
                        this.addChild(childState);
                    }
                }
            }
            exploredNodes.add(this);
        }
    }

    private void checkAndMarkDead(){
        this.leftShoreState.checkAndMarkDead();
        this.rightShoreState.checkAndMarkDead();
        if(this.leftShoreState.isDead() || this.rightShoreState.isDead()){
            this.dead = true;
        }
    }

    public ArrayList<StateNode> getChildren() {
        return children;
    }


    @Override
    public String toString() {
        return "{" +
                "leftShoreState=" + leftShoreState.toString() +
                ", rightShoreState=" + rightShoreState.toString() +
                '}';
    }

    public int getLevel(){
        int nodeLevel = 0;
        StateNode parentNode = this.parent;
        while (parentNode != null){
            nodeLevel += 1;
            parentNode = parentNode.parent;
        }
        return nodeLevel;
    }

    private StateNode applyOperatorToLeftShore(Operators op){
        StateNode childState = null;

        ShoreState childStateRightShore = null;
        ShoreState childStateLeftShore = null;

        switch (op){
            case C -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries(),
                        this.leftShoreState.getNumOfCannibals() - 1, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries(),
                        this.rightShoreState.getNumOfCannibals() + 1, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case M -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() - 1,
                        this.leftShoreState.getNumOfCannibals(), !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() + 1,
                        this.rightShoreState.getNumOfCannibals(), !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case MC -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() - 1,
                        this.leftShoreState.getNumOfCannibals() - 1, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() + 1,
                        this.rightShoreState.getNumOfCannibals() + 1, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case CC -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries(),
                        this.leftShoreState.getNumOfCannibals() - 2, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries(),
                        this.rightShoreState.getNumOfCannibals() + 2, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case MM -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() - 2,
                        this.leftShoreState.getNumOfCannibals(), !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() + 2,
                        this.rightShoreState.getNumOfCannibals(), !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
        }
        childState = new StateNode(childStateLeftShore, childStateRightShore);
        childState.operatorUsed = op.toString() + " -> RS";
        return childState;
    }

    private StateNode applyOperatorToRightShore(Operators op){
        StateNode childState = null;
        ShoreState childStateRightShore = null;
        ShoreState childStateLeftShore = null;
        switch (op){
            case C -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries(),
                        this.leftShoreState.getNumOfCannibals() + 1, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries(),
                        this.rightShoreState.getNumOfCannibals() - 1, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case M -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() + 1,
                        this.leftShoreState.getNumOfCannibals(), !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() - 1,
                        this.rightShoreState.getNumOfCannibals(), !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case MC -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() + 1,
                        this.leftShoreState.getNumOfCannibals() + 1, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() - 1,
                        this.rightShoreState.getNumOfCannibals() - 1, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case CC -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries(),
                        this.leftShoreState.getNumOfCannibals() + 2, !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries(),
                        this.rightShoreState.getNumOfCannibals() - 2, !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
            case MM -> {
                childStateLeftShore = new ShoreState(this.leftShoreState.getNumOfMissionaries() + 2,
                        this.leftShoreState.getNumOfCannibals(), !this.leftShoreState.isBoat(), Shore.LEFT);
                childStateRightShore = new ShoreState(this.rightShoreState.getNumOfMissionaries() - 2,
                        this.rightShoreState.getNumOfCannibals(), !this.rightShoreState.isBoat(), Shore.RIGHT);
            }
        }
        childState = new StateNode(childStateLeftShore, childStateRightShore);
        childState.operatorUsed = op.toString() + " -> LS";
        return childState;
    }

    private Shore getShoreWithBoat(){
        if(this.leftShoreState.isBoat()){
            return this.leftShoreState.getShore();
        }
        return this.rightShoreState.getShore();
    }

    private boolean operatorCanBeApplied(Operators op, Shore shoreWithBoat){
        ShoreState shoreState = shoreWithBoat == Shore.LEFT ? this.leftShoreState : this.rightShoreState;
        if(op == Operators.MM && shoreState.getNumOfMissionaries() >= 2){
            return true;
        } else if(op == Operators.CC && shoreState.getNumOfCannibals() >= 2){
            return true;
        } else if(op == Operators.MC && shoreState.getNumOfMissionaries() >= 1
                && shoreState.getNumOfCannibals() >= 1){
            return true;
        } else if(op == Operators.M && shoreState.getNumOfMissionaries() >= 1){
            return true;
        } else {
            return op == Operators.C && shoreState.getNumOfCannibals() >= 1;
        }
    }


    private void checkAndMarkGoal(){
        if(this.rightShoreState.getNumOfCannibals() == 3
                && this.rightShoreState.getNumOfMissionaries() == 3 && this.rightShoreState.isBoat()){
            this.goalState = true;
            this.dead = true;
        }
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        StateNode stateNode = (StateNode) o;
        return leftShoreState.equals(stateNode.leftShoreState) && rightShoreState.equals(stateNode.rightShoreState);
    }

    @Override
    public int hashCode() {
        return Objects.hash(leftShoreState, rightShoreState);
    }


    public ShoreState getLeftShoreState() {
        return leftShoreState;
    }

    public ShoreState getRightShoreState() {
        return rightShoreState;
    }

    public boolean isDead() {
        return dead;
    }

    public boolean isGoalState() {
        return goalState;
    }

    public String getOperatorUsed() {
        return operatorUsed;
    }
}
