package com.missionariescannibalsstatespacesimulator.engine;

import java.util.Objects;

public class ShoreState{

    Shore shore;
    private int numOfMissionaries;
    private int numOfCannibals;
    private boolean boat;

    private boolean dead;


    public ShoreState(int numOfMissionaries, int numOfCannibals, boolean boat, Shore shore) {
        this.numOfMissionaries = numOfMissionaries;
        this.numOfCannibals = numOfCannibals;
        this.boat = boat;
        this.dead = false;
        this.shore = shore;
    }

    public int getNumOfMissionaries() {
        return numOfMissionaries;
    }

    public void setNumOfMissionaries(int numOfMissionaries) {
        this.numOfMissionaries = numOfMissionaries;
    }

    public int getNumOfCannibals() {
        return numOfCannibals;
    }

    public void setNumOfCannibals(int numOfCannibals) {
        this.numOfCannibals = numOfCannibals;
    }

    public boolean isBoat() {
        return boat;
    }

    public void setBoat(boolean boat) {
        this.boat = boat;
    }

    public boolean isDead() {
        return dead;
    }

    public void setDead(boolean dead) {
        this.dead = dead;
    }

    public Shore getShore() {
        return shore;
    }

    public void setShore(Shore shore) {
        this.shore = shore;
    }

    @Override
    public String toString() {
        return "{" +
                "numOfMissionaries=" + numOfMissionaries +
                ", numOfCannibals=" + numOfCannibals +
                ", boat=" + boat +
                '}';
    }


    public void checkAndMarkDead(){
        if ( (this.numOfMissionaries > 0 &&  this.numOfCannibals > this.numOfMissionaries)){
            this.dead = true;
        }
    }


    @Override
    public int hashCode() {
        return Objects.hash(numOfCannibals, numOfMissionaries, boat);
    }

    @Override
    public boolean equals(Object obj) {
        ShoreState otherState = (ShoreState) obj;
        return this.numOfCannibals == otherState.numOfCannibals && this.numOfMissionaries == otherState.numOfMissionaries
                && this.boat == otherState.boat;
    }
}

