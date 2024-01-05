package com.ai.eightpuzzlesolver.gui;

import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;


public final class MainWindowPane extends Pane {

    private static final double IMG_WIDTH_HEIGHT = 100;
    private static MainWindowPane INSTANCE;

    private final BorderPane mainWindow = new BorderPane();

    private final TreeDisplayPane treeDisplayPane;
    private final InputPane inputPane;
    private final MenuBar menuBar = new MenuBar();

    private final TextArea console;

    private WindowManager windowManager;

    private MainWindowPane() {
        this.inputPane = InputPane.getInstance();
        this.treeDisplayPane = TreeDisplayPane.getInstance();
        this.console = new TextArea();
        setUpToolBar();
    }

    public static MainWindowPane getInstance(){
        if(INSTANCE == null){
            INSTANCE = new MainWindowPane();
        }
        return INSTANCE;
    }

   public Pane getMainWindow(){
        mainWindow.setTop(menuBar);
        mainWindow.setCenter(inputPane.getInputPane());
        setupConsole();
        appendToConsole("Console:\n");
        setupConsoleOutputEvent();
        mainWindow.setBottom(console);
        return mainWindow;
   }

    public WindowManager getWindowManager() {
        return windowManager;
    }

    public void setWindowManager(WindowManager windowManager) {
        this.windowManager = windowManager;
        this.treeDisplayPane.setWindowManager(windowManager);
        this.inputPane.setWindowManager(windowManager);
        onUserInputComplete();
    }

    private void onUserInputComplete(){
        this.windowManager.guiTreeGeneratorSetProperty()
                .addListener((observable, oldValue, newValue) -> {
                    this.mainWindow.setCenter(treeDisplayPane.getTreeDisplayPane());
                });
    }

    private void setupConsole(){
        console.setPrefRowCount(9);
        console.setEditable(false);
    }

    private void appendToConsole(String text){
        console.appendText(text);
    }

    private void setupConsoleOutputEvent(){
        this.windowManager.stateReachingConditionProperty()
                .addListener( (observable, oldValue, newValue) -> {
                    StringBuilder consoleOutput = new StringBuilder();
                    consoleOutput.append("  (Initial State) -> ");
                    consoleOutput.append(newValue);
                    consoleOutput.append(" -> (Final State) \n");
                    appendToConsole(consoleOutput.toString());
                    appendToConsole("Where, ");
                    appendToConsole("Initial state is:\n");
                    appendToConsole(windowManager.getGuiTreeGenerator().getInitialState().toString());
                    appendToConsole("And final state is: \n");
                    appendToConsole(windowManager.getGuiTreeGenerator().getFinalState().toString());
                });
    }


    //*****************************************************************************************************//
    /**
     * Below you'll find wacky code for setting up toolbars and event listeners for
     * menubar buttons. Was too bored to refactor them into small pieces.
     * */
    private void setUpToolBar(){

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
        codeSrc.getChildren().addAll(label, new Hyperlink("https://github.com/Sabin-B-99/Archives/tree/main/Kathmandu%20University/COMP%20472/EightPuzzleBFSDFS"));
        about.getChildren().addAll(codeSrc, closeAboutMenuBtn);

        closeAboutMenuBtn.setOnAction(event -> {
            Stage stage = (Stage) about.getScene().getWindow();
            stage.close();
        });

        return about;
    }

    private Pane getLegendPane(){
        BorderPane legend = new BorderPane();
        Button closeLegendBtn = new Button("Close");

        ImageView finalStateNodeImageView = new ImageView();
        finalStateNodeImageView.setFitHeight(IMG_WIDTH_HEIGHT);
        finalStateNodeImageView.setFitWidth(IMG_WIDTH_HEIGHT);
        Image deadNodeImage = new Image(TreeDisplayPane.class.getResource("/img/finalState-node.png").toString());
        finalStateNodeImageView.setImage(deadNodeImage);
        HBox finalStateNodeHBox = new HBox();
        Label finalStateNodeLabel = new Label("Goal State Node. Colored in green.");
        finalStateNodeHBox.getChildren().addAll(finalStateNodeImageView, finalStateNodeLabel);
        finalStateNodeHBox.setSpacing(20);
        finalStateNodeHBox.setAlignment(Pos.CENTER);

        ImageView latestNodeMarkerImgView = new ImageView();
        latestNodeMarkerImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        latestNodeMarkerImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        Image latestNodeMarkerImage = new Image(TreeDisplayPane.class.getResource("/img/latest-added-node-marker.png").toString());
        latestNodeMarkerImgView.setImage(latestNodeMarkerImage);
        HBox markerNodeHBox = new HBox();
        Label markerLabel = new Label("Latest generated node marker.");
        markerNodeHBox.getChildren().addAll(latestNodeMarkerImgView, markerLabel);
        markerNodeHBox.setSpacing(20);
        markerNodeHBox.setAlignment(Pos.CENTER);

        ImageView latestNodeImgView = new ImageView();
        latestNodeImgView.setFitHeight(IMG_WIDTH_HEIGHT);
        latestNodeImgView.setFitWidth(IMG_WIDTH_HEIGHT);
        Image latestNodeImage = new Image(TreeDisplayPane.class.getResource("/img/latest-generated-node.png").toString());
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
        Image extendableNodeImage = new Image(TreeDisplayPane.class.getResource("/img/node-can-be-extended.png").toString());
        extendableNodeImageView.setImage(extendableNodeImage);
        HBox extendableNodeHBox = new HBox();
        Label extendableLabel = new Label("""
                    Nodes in gray can be extended.
                    Nodes that are gray may not be extended
                    if the goal state is already found. 
                """);
        extendableNodeHBox.getChildren().addAll(extendableNodeImageView, extendableLabel);
        extendableNodeHBox.setSpacing(40);
        extendableNodeHBox.setAlignment(Pos.CENTER);


        VBox centerVBox = new VBox();
        centerVBox.getChildren().addAll(finalStateNodeHBox,extendableNodeHBox,markerNodeHBox, latestNodeHBox);
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
