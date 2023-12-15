package com.badalsabin.ai.eightpuzzlebfsdfs.gui;

import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;

public final class TreeDisplayPane extends Pane {

    private static TreeDisplayPane INSTANCE;
    private final BorderPane treeDisplayPane = new BorderPane();
    private final Button nextButton = new Button("Next");


    private static final LinkedList<Pane> treeNodesLinkedList = new LinkedList<>();
    private static final LinkedList<Pane> treeNodesParentsList = new LinkedList<>();
    private static final LinkedList<String> nodeStateReachingCondition = new LinkedList<>();

    private static final Label latestNodeMarker = new Label("X");

    private static double drawnNodeYForAutoScroll;
    private static double drawnNodeXForAutoScroll;


    private WindowManager windowManager;
    private TreeDisplayPane(){
    }

    public static TreeDisplayPane getInstance(){
        if(INSTANCE == null){
            INSTANCE = new TreeDisplayPane();
        }
        return INSTANCE;
    }

    public Pane getTreeDisplayPane(){
        buildTreeDisplayPane();
        return treeDisplayPane;
    }
    private void buildTreeDisplayPane(){
        windowManager.getGuiTreeGenerator().generateStateSpace();
        windowManager.setStateReachingCondition(windowManager.getGuiTreeGenerator().getStateReachingPath());

        HBox buttonBar = new HBox();
        buttonBar.setPadding(new Insets(5));
        buttonBar.getChildren().addAll(nextButton);

        Group generatedNodeGroup = new Group();
        ScrollPane nodeGroupScrollPane = new ScrollPane();
        nodeGroupScrollPane.setPadding(new Insets(10));


        treeDisplayPane.setCenter(nodeGroupScrollPane);
        treeDisplayPane.setBottom(buttonBar);

        nodeGroupScrollPane.setContent(generatedNodeGroup);
        latestNodeMarker.setTextFill(Color.DARKGREEN);

        Tree currentTreeNode = windowManager.getGuiTreeGenerator().getTreeRoot();


        if(windowManager.getGuiTreeGenerator().getMethod().equalsIgnoreCase("bfs")){
            calculateNodePosInSceneAndAddToLinkedListBFS(currentTreeNode);
        }else if (windowManager.getGuiTreeGenerator().getMethod().equalsIgnoreCase("dfs")){
            calculateNodePosInSceneAndAddToLinkedListDFS(currentTreeNode);
        }else{
            calculateNodePosInSceneAndAddToLinkedListBFS(currentTreeNode);
        }

        Pane initialNode = treeNodesLinkedList.removeFirst();
        changeLatestNodeMarkerPosition(initialNode.getLayoutX() + initialNode.getWidth() / 2,
                initialNode.getLayoutY() + initialNode.getHeight() / 2);
        generatedNodeGroup.getChildren().addAll(initialNode, latestNodeMarker);


        nextButton.setOnAction(event ->{
            addNextNodeInVisualizationArea(generatedNodeGroup);
            autoScrollScrollPane(nodeGroupScrollPane);
        });
    }


    private void autoScrollScrollPane(ScrollPane scrollPane){
        double scrollPaneHeight = scrollPane.getContent().getBoundsInLocal().getHeight();
        double scrollPaneWidth = scrollPane.getContent().getBoundsInLocal().getWidth();

        double newScrollVValue = drawnNodeYForAutoScroll/scrollPaneHeight;
        double newScrollHValue = drawnNodeXForAutoScroll/scrollPaneWidth;

        if(newScrollVValue <= 0.25){
            scrollPane.setVvalue(0);
        }else{
            scrollPane.setVvalue(newScrollVValue);
        }

        if(newScrollHValue <= 1.35){
            scrollPane.setHvalue(0);
        }else{
            scrollPane.setHvalue(newScrollHValue);
        }
    }

    private void addNextNodeInVisualizationArea(Group nodeGroup){
        try {
            Pane nextNodeToDraw = treeNodesLinkedList.removeFirst();
            changeLatestNodeMarkerPosition(nextNodeToDraw.getLayoutX() + nextNodeToDraw.getWidth() / 2,
                    nextNodeToDraw.getLayoutY() + nextNodeToDraw.getHeight() / 2);
            nodeGroup.getChildren().add(nextNodeToDraw);

            drawnNodeYForAutoScroll = nextNodeToDraw.getLayoutY() + nextNodeToDraw.getHeight();
            drawnNodeXForAutoScroll = nextNodeToDraw.getLayoutX() + nextNodeToDraw.getWidth();

            Pane parentNode = treeNodesParentsList.removeFirst();
            Line connectionLine =  connect(nextNodeToDraw, parentNode);
            Label text = addTextBetweenPanes(nextNodeToDraw, nodeStateReachingCondition.removeFirst());
            nodeGroup.getChildren().addAll(connectionLine, text);
        }catch (NoSuchElementException ignored){
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("State generation complete");
            alert.setHeaderText("All possible states generated");
            alert.setContentText("Cannot generate more nodes.");
            alert.showAndWait();
        }
    }

    private void calculateNodePosInSceneAndAddToLinkedListDFS(Tree rootNode){
        if(rootNode != null){
            Tree currentNode = null;
            GUITreeGenerator.calculateAndSetupPositionOfNodeInScene(rootNode);
            treeNodesLinkedList.add(rootNode.getRoot().getNode());
            if(rootNode.getParent()!=null){
                treeNodesParentsList.add(rootNode.getParent().getRoot().getNodeContainer());
                nodeStateReachingCondition.add(rootNode.getStateObtainedOnCondition());
            }
            for (int i = 0; i < rootNode.getChildren().size(); i++) {
                currentNode = rootNode.getChildren().get(i);
                calculateNodePosInSceneAndAddToLinkedListDFS(currentNode);
            }
        }
    }

    private void calculateNodePosInSceneAndAddToLinkedListBFS(Tree rootNode){
        Queue<Tree> bfsQueue = new LinkedList<>();
        bfsQueue.add(rootNode);
        while (!bfsQueue.isEmpty()){
            Tree temp = bfsQueue.poll();
            if(temp != null){
                GUITreeGenerator.calculateAndSetupPositionOfNodeInScene(temp);
                treeNodesLinkedList.add(temp.getRoot().getNode());
                if(temp.getParent()!=null){
                    treeNodesParentsList.add(temp.getParent().getRoot().getNodeContainer());
                    nodeStateReachingCondition.add(temp.getStateObtainedOnCondition());
                }
                for (Tree child: temp.getChildren()) {
                    if(child != null){
                        bfsQueue.add(child);
                    }
                }
            }
        }
    }


    private Line connect(Pane sourcePane, Pane destinationPane){
        Line connectionLine = new Line();
        connectionLine.setStrokeWidth(1);
        connectionLine.setStartX(sourcePane.getLayoutX() + sourcePane.getWidth() / 2);
        connectionLine.setStartY(sourcePane.getLayoutY());
        connectionLine.setEndX(destinationPane.getLayoutX() + destinationPane.getWidth() / 2);
        connectionLine.setEndY(destinationPane.getLayoutY() + destinationPane.getHeight());
        return connectionLine;
    }

    private Label addTextBetweenPanes(Pane sourcePane, String text){
        Label textCreated = new Label();
        textCreated.setText(text);
        textCreated.setTextFill(Color.BLUE);
        textCreated.setStyle("""
            -fx-background-color: #f4f4f4;
        """);
        double xPos = (sourcePane.getLayoutX() + sourcePane.getWidth() / 2) - 13;
        double yPos = sourcePane.getLayoutY() - 17;
        textCreated.setLayoutX(xPos);
        textCreated.setLayoutY(yPos);
        return textCreated;
    }


    private void changeLatestNodeMarkerPosition(double posX, double posY){
        latestNodeMarker.setLayoutX(posX);
        latestNodeMarker.setLayoutY(posY);
    }

    public WindowManager getWindowManager() {
        return windowManager;
    }

    public void setWindowManager(WindowManager windowManager) {
        this.windowManager = windowManager;
    }

}
