package com.missionariescannibalsstatespacesimulator.gui;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class GUIMain extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Missionaries and cannibal state space problem simulator");
        Pane mainContainer = MainPane.getMainContainer();
        Scene mainScene = new Scene(mainContainer, 800, 650);
        primaryStage.setScene(mainScene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}
