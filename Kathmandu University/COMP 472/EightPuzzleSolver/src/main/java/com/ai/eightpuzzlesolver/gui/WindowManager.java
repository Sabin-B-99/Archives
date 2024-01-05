package com.ai.eightpuzzlesolver.gui;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class WindowManager {
    private GUITreeGenerator guiTreeGenerator;
    private final BooleanProperty guiTreeGeneratorSet = new SimpleBooleanProperty();
    private StringProperty stateReachingCondition = new SimpleStringProperty();

    public WindowManager() {
    }

    public GUITreeGenerator getGuiTreeGenerator() {
        return guiTreeGenerator;
    }

    public void setGuiTreeGenerator(GUITreeGenerator guiTreeGenerator) {
        this.guiTreeGenerator = guiTreeGenerator;
        this.setGuiTreeGeneratorSet(true);
    }

    public boolean isGuiTreeGeneratorSet() {
        return guiTreeGeneratorSet.get();
    }

    public BooleanProperty guiTreeGeneratorSetProperty() {
        return guiTreeGeneratorSet;
    }

    public void setGuiTreeGeneratorSet(boolean guiTreeGeneratorSet) {
        this.guiTreeGeneratorSet.set(guiTreeGeneratorSet);
    }

    public String getStateReachingCondition() {
        return stateReachingCondition.get();
    }

    public StringProperty stateReachingConditionProperty() {
        return stateReachingCondition;
    }

    public void setStateReachingCondition(String stateReachingCondition) {
        this.stateReachingCondition.set(stateReachingCondition);
    }


}
