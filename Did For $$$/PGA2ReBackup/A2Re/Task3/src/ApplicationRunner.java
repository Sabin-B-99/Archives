
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

/**
 * Class that contains the main method that is used to run the application
 */
public class ApplicationRunner extends Application{

    @Override
    public void start(Stage primaryStage) throws Exception {
       Pane mainDisplay = MainDisplayPane.mainDisplayPane();

        Scene mainScene = new Scene(mainDisplay, 955, 545);
        primaryStage.setScene(mainScene);
        primaryStage.setTitle("EPOS Menu System");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}