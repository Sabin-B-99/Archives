package com.missionariescannibalsstatespacesimulator.gui;

import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Text;
import javafx.scene.text.TextBoundsType;



public class CircleWithText{

    private Text nodeText;
    private Color nodeColor;
    private Circle nodeOutlineCircle;

    private Pane nodeContainer;



    public CircleWithText(String text, Color nodeColor){
        this.nodeColor = nodeColor;
        this.nodeText = createText(text);
        this.nodeOutlineCircle = encircle(this.nodeText);
        this.nodeContainer = new StackPane();
    }

    public Pane getNode(){
        nodeContainer.getChildren().addAll(nodeOutlineCircle, nodeText);
        return nodeContainer;
    }

    private Circle encircle(Text nodeText) {
        Circle circle = new Circle();
        circle.setFill(nodeColor);
        final double PADDING = 10;
        circle.setRadius(getWidth(nodeText) / 2 + PADDING);
        return circle;
    }

    private double getWidth(Text nodeText) {
        return nodeText.getLayoutBounds().getWidth();
    }

    private Text createText(String text) {
        Text textCreated = new Text(text);
        textCreated.setBoundsType(TextBoundsType.VISUAL);
        textCreated.setStyle(
                "-fx-font-family: \"Times New Roman\";" +
                        "-fx-font-style: italic;" +
                        "-fx-font-size: 12px;"
        );
        return textCreated;
    }

    public void setNodeXYPos(double X, double Y){
        this.nodeContainer.setLayoutX(this.nodeOutlineCircle.getRadius() * 2.5 * X);
        this.nodeContainer.setLayoutY(this.nodeOutlineCircle.getRadius() * 3 * Y);
    }

    public Pane getNodeContainer() {
        return nodeContainer;
    }

    public Circle getNodeOutlineCircle() {
        return nodeOutlineCircle;
    }
}
