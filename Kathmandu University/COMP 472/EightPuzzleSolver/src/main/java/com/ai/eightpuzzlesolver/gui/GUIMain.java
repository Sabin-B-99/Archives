package com.ai.eightpuzzlesolver.gui;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GUIMain extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("8-Puzzle Problem state space generator");

        WindowManager windowManager = new WindowManager();
        MainWindowPane mainWindowPane = MainWindowPane.getInstance();
        mainWindowPane.setWindowManager(windowManager);

        Scene mainScene = new Scene(mainWindowPane.getMainWindow(), 800, 650);
        primaryStage.setScene(mainScene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch();
    }
}
