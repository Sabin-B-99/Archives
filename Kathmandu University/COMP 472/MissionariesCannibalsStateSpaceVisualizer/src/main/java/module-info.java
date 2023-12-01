module com.missionariescannibalsstatespacesimulator {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.missionariescannibalsstatespacesimulator.gui to javafx.fxml;
    exports com.missionariescannibalsstatespacesimulator.gui;
}