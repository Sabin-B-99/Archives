package mazerunner.gui;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Slider;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import mazerunner.engine.GameEngine;

/**
 * JavaFXML Controller Class 
 */
public class Controller {

    @FXML
    private TextArea playerStat; //TextArea to display player status in the game GUI

    @FXML
    private Slider difficultySlide; //Slider to adjust game difficulty in the game GUI

    @FXML
    private Button moveUpBtn; //button to move the player image up by one gird in the game GUI

    @FXML
    private Button moveDownBtn; //button to move the player image down by one gird in the game GUI

    @FXML
    private Button moveLeftBtn; //button to move the player image left by one gird in the game GUI

    @FXML
    private Button moveRightBtn; //button to move the player image right by one gird in the game GUI

    @FXML
    private GridPane mapGrid; //GridPane that will hold the maze grids

    @FXML
    private TextArea gameLog; //TextArea to show different game events on the game GUI

    @FXML
    private Button saveBtn; //Button to save the  game state to a text file

    @FXML
    private Button loadBtn; //Button to load the game form the save file

    @FXML
    private Button helpBtn; //Button that shows game instruction to the game log area on pressed

    @FXML
    private Button newGame; //Button that will start a new game


    private GUIGameEngine ge = new GUIGameEngine(10);

    /**
     * Method that will be invoked when start button is pressed
     */
    public void onStartPress(){
        ge.setMapGrids(mapGrid);
        ge.startGame();
        ge.setGameLogArea(gameLog);
        newGame.setDisable(true);
        difficultySlide.setDisable(true);
        saveBtn.setDisable(false);
        loadBtn.setDisable(true);
        moveUpBtn.setDisable(false);
        moveDownBtn.setDisable(false);
        moveLeftBtn.setDisable(false);
        moveRightBtn.setDisable(false);
        playerStat.setText(ge.getPlayer().getPlayerStatus());
        gameLog.setText("Game Difficulty: " + GUIGameEngine.getDifficulty());
    }

    /**
     * Method that will be invoked when difficulty slide is dragged
     */
    public void onDifficultySliderChanged(){
        difficultySlide.valueProperty().addListener(
            new ChangeListener<Number>() {
                public void changed(ObservableValue <? extends Number > 
                observable, Number oldValue, Number newValue)
                {
                    double val = difficultySlide.getValue();
                    ge.setDifficulty((int) val);
                }
            }
        );
    }

    /**
     * Method that will be invoked when up button is pressed
     */
    public void onUpPressed(){
        ge.movePlayer("-w");
        playerStat.setText(ge.getPlayer().getPlayerStatus());
    }

    /**
     * Method that will be invoked when down button is pressed
     */
    public void onDownPressed(){
        ge.movePlayer("-s");
        playerStat.setText(ge.getPlayer().getPlayerStatus());
    }

    /**
     * Method that will be invoked when left button is pressed
     */
    public void onLeftPressed(){
        ge.movePlayer("-a");
        playerStat.setText(ge.getPlayer().getPlayerStatus());
    }

    /**
     * Method that will be invoked when right button is pressed
     */
    public void onRightPressed(){
        ge.movePlayer("-d");
        playerStat.setText(ge.getPlayer().getPlayerStatus());
    }

    /**
     * Method that will be invoked when help button is pressed
     */
    public void onHelpPressed(){
        gameLog.setText(GameEngine.showHelpText());
    }

    /**
     * Method that will be invoked when save button is pressed
     */
    public void onSavePressed(){
        ge.saveGame();
    }

    /**
     * Method that will be invoked when load button is pressed
     */
    public void onLoadPressed(){
        ge.setGameLogArea(gameLog);
        moveUpBtn.setDisable(false);
        moveDownBtn.setDisable(false);
        moveLeftBtn.setDisable(false);
        moveRightBtn.setDisable(false);
        loadBtn.setDisable(true);
        difficultySlide.setDisable(true);
        saveBtn.setDisable(false);
        newGame.setDisable(true);

        ge.setPlayerStatArea(playerStat);
        ge.setMapGrids(mapGrid);
        ge.loadGame();
    }
}
