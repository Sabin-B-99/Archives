module com.badalsabin.ai.eightpuzzlebfsdfs {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.badalsabin.ai.eightpuzzlebfsdfs.gui to javafx.fxml;
    exports com.badalsabin.ai.eightpuzzlebfsdfs.gui;
}