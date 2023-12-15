package com.missionariescannibalsstatespacesimulator.gui;

import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileInputStream;
import java.net.URI;
import java.net.URL;
import java.util.LinkedList;
import java.util.NoSuchElementException;

public class MainPane extends Pane {

    private static  final double IMG_WIDTH_HEIGHT = 100;
    private static final BorderPane mainPane = new BorderPane();
    private static final Button nextButton = new Button("Next");

    private static final MenuBar menuBar = new MenuBar();
    private static final GUITreeGenerator treeGenerator = new GUITreeGenerator();

    private static final LinkedList<Pane> treeNodesLinkedList = new LinkedList<>();
    private static final LinkedList<Pane> treeNodesParentsList = new LinkedList<>();
    private static final LinkedList<String> nodeStateReachingCondition = new LinkedList<>();


    private static final Label latestNodeMarker = new Label("X");

    private static double drawnNodeYForAutoScroll;

    private MainPane(){
    }

    public static Pane getMainContainer(){
        setUpToolBar();
        buildMainPane();
        return mainPane;
    }

    private static void buildMainPane(){
        treeGenerator.generateStateSpace();

        HBox buttonBar = new HBox();
        buttonBar.setPadding(new Insets(5));
        buttonBar.getChildren().addAll(nextButton);

        Group generatedNodeGroup = new Group();
        ScrollPane nodeGroupScrollPane = new ScrollPane();
        nodeGroupScrollPane.setPadding(new Insets(10));
        mainPane.setTop(menuBar);
        mainPane.setCenter(nodeGroupScrollPane);
        mainPane.setBottom(buttonBar);

        nodeGroupScrollPane.setContent(generatedNodeGroup);
        latestNodeMarker.setTextFill(Color.DARKGREEN);

        Tree currentTreeNode =  treeGenerator.getTreeRoot();
        calculateNodePosInSceneAndAddToLinkedList(currentTreeNode);

        Pane initialNode = treeNodesLinkedList.removeFirst();
        changeLatestNodeMarkerPosition(initialNode.getLayoutX() + initialNode.getWidth() / 2,
                initialNode.getLayoutY() + initialNode.getHeight() / 2);
        generatedNodeGroup.getChildren().addAll(initialNode, latestNodeMarker);


        nextButton.setOnAction(event ->{
            addNextNodeInVisualizationArea(generatedNodeGroup);
            autoScrollScrollPane(nodeGroupScrollPane);
        });
    }


    private static void autoScrollScrollPane(ScrollPane scrollPane){
        double scrollPaneHeight = scrollPane.getContent().getBoundsInLocal().getHeight();
        double newScrollVValue = drawnNodeYForAutoScroll/scrollPaneHeight;
        if(newScrollVValue <= 0.25){
            scrollPane.setVvalue(0);
        }else{
            scrollPane.setVvalue(drawnNodeYForAutoScroll/scrollPaneHeight);
        }
    }

    private static void addNextNodeInVisualizationArea(Group nodeGroup){
        try {
            Pane nextNodeToDraw = treeNodesLinkedList.removeFirst();
            changeLatestNodeMarkerPosition(nextNodeToDraw.getLayoutX() + nextNodeToDraw.getWidth() / 2,
                    nextNodeToDraw.getLayoutY() + nextNodeToDraw.getHeight() / 2);
            nodeGroup.getChildren().add(nextNodeToDraw);

            drawnNodeYForAutoScroll = nextNodeToDraw.getLayoutY() + nextNodeToDraw.getHeight();

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

    private static void calculateNodePosInSceneAndAddToLinkedList(Tree rootNode){
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
                calculateNodePosInSceneAndAddToLinkedList(currentNode);
            }
        }
    }


    private static Line connect(Pane sourcePane, Pane destinationPane){
        Line connectionLine = new Line();
        connectionLine.setStrokeWidth(1);
        connectionLine.setStartX(sourcePane.getLayoutX() + sourcePane.getWidth() / 2);
        connectionLine.setStartY(sourcePane.getLayoutY());
        connectionLine.setEndX(destinationPane.getLayoutX() + destinationPane.getWidth() / 2);
        connectionLine.setEndY(destinationPane.getLayoutY() + destinationPane.getHeight());
        return connectionLine;
    }

    private static Label addTextBetweenPanes(Pane sourcePane, String text){
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


    private static void changeLatestNodeMarkerPosition(double posX, double posY){
        latestNodeMarker.setLayoutX(posX);
        latestNodeMarker.setLayoutY(posY);
    }

    private static void setUpToolBar(){

        Menu fileMenu = new Menu("File");
        final MenuItem quitBtn = new MenuItem("Exit");
        fileMenu.getItems().add(quitBtn);


        Menu helpMenu = new Menu("Help");
        final MenuItem legendBtn = new MenuItem("Legend");
        final MenuItem aboutButton = new MenuItem("About");
        helpMenu.getItems().addAll(legendBtn, aboutButton);

        menuBar.getMenus().addAll(fileMenu, helpMenu);


        quitBtn.setOnAction( event -> {
            Platform.exit();
        });

        aboutButton.setOnAction(event -> {
            Stage aboutStage = new Stage();
            aboutStage.setTitle("About");
            aboutStage.initModality(Modality.APPLICATION_MODAL);
            Scene aboutScene = new Scene(getAboutPane(), 600,200);
            aboutStage.setScene(aboutScene);
            aboutStage.show();
        });

        legendBtn.setOnAction(event -> {
            Stage legendStage = new Stage();
            legendStage.setTitle("Legend");
            legendStage.initModality(Modality.APPLICATION_MODAL);
            Scene legendScene = new Scene(getLegendPane(), 550, 550);
            legendStage.setScene(legendScene);
            legendStage.show();
        });
    }

    private static Pane getAboutPane(){
        Button closeAboutMenuBtn = new Button("Close");
        VBox about = new VBox();
        about.setSpacing(20);
        about.setAlignment(Pos.CENTER);
        about.getChildren().add(new Label("Developed by: Sabin Badal"));
        HBox codeSrc = new HBox();
        Label label = new Label("View source: ");
        codeSrc.setSpacing(20);
        codeSrc.setAlignment(Pos.CENTER);
        codeSrc.getChildren().addAll(label, new Hyperlink("https://github.com/Sabin-B-99/Archives/tree/main/Kathmandu%20University/COMP%20472/MissionariesCannibalsStateSpaceVisualizer"));
        about.getChildren().addAll(codeSrc, closeAboutMenuBtn);

        closeAboutMenuBtn.setOnAction(event -> {
            Stage stage = (Stage) about.getScene().getWindow();
            stage.close();
        });

        return about;
    }

    private static Pane getLegendPane(){
        BorderPane legend = new BorderPane();
        Button closeLegendBtn = new Button("Close");

        ImageView deadNodeImageView = new ImageView();
        deadNodeImageView.setFitHeight(IMG_WIDTH_HEIGHT);
        deadNodeImageView.setFitWidth(IMG_WIDTH_HEIGHT);
        Image deadNodeImage = new Image(MainPane.class.getResource("/img/dead-node.png").toString());
        deadNodeImageView.setImage(deadNodeImage);
        HBox deadNodeHBox = new HBox();
        Label deadNodeLabel = new Label("Dead node. Colored with red.");
        deadNodeHBox.getChildren().addAll(deadNodeImageView, deadNodeLabel);
        deadNodeHBox.setSpacing(20);
        deadNodeHBox.setAlignment(Pos.CENTER);

        ImageView latestNodeMarkerImgView = new ImageView();
        latestNodeMarkerImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        latestNodeMarkerImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        Image latestNodeMarkerImage = new Image(MainPane.class.getResource("/img/latest-added-node-marker.png").toString());
        latestNodeMarkerImgView.setImage(latestNodeMarkerImage);
        HBox markerNodeHBox = new HBox();
        Label markerLabel = new Label("Latest generated node marker.");
        markerNodeHBox.getChildren().addAll(latestNodeMarkerImgView, markerLabel);
        markerNodeHBox.setSpacing(20);
        markerNodeHBox.setAlignment(Pos.CENTER);

        ImageView latestNodeImgView = new ImageView();
        latestNodeImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        latestNodeImgView.setFitWidth(IMG_WIDTH_HEIGHT);
        Image latestNodeImage = new Image(MainPane.class.getResource("/img/latest-generated-node.png").toString());
        latestNodeImgView.setImage(latestNodeImage);
        HBox latestNodeHBox = new HBox();
        Label latestNodeLabel = new Label("""
                    Latest node generated in view. 
                    Marked with 'X' (Latest generated node marker) at top left.
                """);
        latestNodeHBox.getChildren().addAll(latestNodeImgView, latestNodeLabel);
        latestNodeHBox.setSpacing(20);
        latestNodeHBox.setAlignment(Pos.CENTER);

        ImageView extendableNodeImageView = new ImageView();
        extendableNodeImageView.setFitHeight(IMG_WIDTH_HEIGHT);
        extendableNodeImageView.setFitWidth(IMG_WIDTH_HEIGHT);
        Image extendableNodeImage = new Image(MainPane.class.getResource("/img/node-can-be-extended.png").toString());
        extendableNodeImageView.setImage(extendableNodeImage);
        HBox extendableNodeHBox = new HBox();
        Label extendableLabel = new Label("""
                    Nodes in gray can be extended.
                    Nodes that are gray and not extended are not
                    extendable or might have already been extended.
                    (Un-extendable nodes are such in which only either a missionary
                        or a cannibal is present on either side of the shore.)
                """);
        extendableNodeHBox.getChildren().addAll(extendableNodeImageView, extendableLabel);
        extendableNodeHBox.setSpacing(40);
        extendableNodeHBox.setAlignment(Pos.CENTER);


        VBox centerVBox = new VBox();
        centerVBox.getChildren().addAll(deadNodeHBox,extendableNodeHBox,markerNodeHBox, latestNodeHBox);
        centerVBox.getChildren().add(closeLegendBtn);
        centerVBox.setSpacing(20);
        centerVBox.setAlignment(Pos.CENTER);
        legend.setCenter(centerVBox);


        closeLegendBtn.setOnAction(event -> {
            Stage stage = (Stage) legend.getScene().getWindow();
            stage.close();
        });

        return legend;
    }
}
