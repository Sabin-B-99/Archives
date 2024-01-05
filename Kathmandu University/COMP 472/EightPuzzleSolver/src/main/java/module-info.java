module com.ai.eightpuzzlesolver {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.ai.eightpuzzlesolver.gui to javafx.fxml;
    exports com.ai.eightpuzzlesolver.gui;
}
