package com.badalsabin.ai.eightpuzzlebfsdfs.gui;

import com.badalsabin.ai.eightpuzzlebfsdfs.engine.Board;
import com.badalsabin.ai.eightpuzzlebfsdfs.engine.StateTreeNode;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;

public final class InputPane extends Pane {
    private final Button run;
    private final ToggleGroup toggleGroup;
    private final GridPane initialStateInputGrids;
    private final GridPane finalStateInputGrids;


    private WindowManager windowManager;

    private static InputPane INSTANCE;

    private InputPane() {
        this.run = new Button("Run");
        this.toggleGroup = new ToggleGroup();
        this.initialStateInputGrids = new GridPane();
        this.finalStateInputGrids = new GridPane();
    }

    public static InputPane getInstance(){
        if(INSTANCE == null){
            INSTANCE = new InputPane();
        }
        return INSTANCE;
    }

    public Pane getInputPane(){
        addRunButtonEventHandler();
        return stateInputGrid();
    }
    private Pane stateInputGrid(){
        VBox initialStateInputGrids = getInitialStateInputGrid();
        VBox finalStateInputGrids = getFinalStateInputGrid();
        VBox instructionPane = getInputInstructionsPane();
        HBox inputGridHBox = new HBox();
        inputGridHBox.setPadding(new Insets(5,5,5,5));
        inputGridHBox.setSpacing(35);
        inputGridHBox.getChildren().addAll(initialStateInputGrids, finalStateInputGrids, instructionPane);
        VBox inputGridPane = new VBox();
        inputGridPane.setSpacing(10);
        inputGridPane.getChildren().addAll(inputGridHBox, getOptionsPane());
        return inputGridPane;
    }

    private VBox getInitialStateInputGrid(){
        Label initialStateLabel = new Label("Initial State");
        VBox initialStateInputGridAndLabelVBox = new VBox();
        initialStateInputGridAndLabelVBox.getChildren().add(initialStateLabel);
        initialStateInputGridAndLabelVBox.getChildren().add(initialStateInputGrid());
        initialStateInputGridAndLabelVBox.setSpacing(10);
        initialStateInputGridAndLabelVBox.setPadding(new Insets(15,15,15,15));
        return initialStateInputGridAndLabelVBox;
    }

    private VBox getFinalStateInputGrid(){
        Label finalStateLabel = new Label("Goal State");
        VBox finalStateInputGridAndLabelVBox = new VBox();
        finalStateInputGridAndLabelVBox.getChildren().add(finalStateLabel);
        finalStateInputGridAndLabelVBox.getChildren().add(finalStateInputGrid());
        finalStateInputGridAndLabelVBox.setSpacing(10);
        finalStateInputGridAndLabelVBox.setPadding(new Insets(15,15,15,15));
        return finalStateInputGridAndLabelVBox;
    }

    private VBox getInputInstructionsPane(){
        Label instructionsTitle = new Label("Instructions");
        VBox instructionsGrid = new VBox();
        Text instructionText = new Text();
        instructionText.setText("""
                    1. Please input -1 to represent an empty cell.
                        Example:
                        Initial State:            Final State:
                        |2|8 |3|                  |1|2 |3| 
                        |1|6 |4|                  |8|-1|4|
                        |7|-1|5|                  |7|6 |5|
                    
                    2. Please do not enter string on the input grid. 
                       Do not leave them empty. Haven't implemented 
                       input validation functions. Program will break.
                       huhuhhu :(( 
                    
                    3. The dfs method is almost useless and finding
                       solutions using this method is rare. Better
                       use the Iterative deepening search (ids) method
                       or the breadth first search method.   
                       
                    Have fun :)))
                """);
        instructionsGrid.getChildren().addAll(instructionsTitle, instructionText);
        instructionsGrid.setSpacing(10);
        instructionsGrid.setPadding(new Insets(15));
        return instructionsGrid;
    }
    private GridPane initialStateInputGrid(){
        addInputCellsInGridPane(initialStateInputGrids,3,3);
        return initialStateInputGrids;
    }

    private GridPane finalStateInputGrid(){
        addInputCellsInGridPane(finalStateInputGrids, 3,3);
        return finalStateInputGrids;
    }
     private void addInputCellsInGridPane(GridPane pane, int noOfRow, int noOfCol){
        for (int row = 0; row < noOfRow; row++) {
            TextField[] textFieldRow = new TextField[noOfCol];
            for (int col = 0; col < noOfCol; col++) {
                TextField valInputTextField = new TextField();
                valInputTextField.setMaxWidth(50);
                textFieldRow[col] = valInputTextField;
            }
            pane.addRow(row, textFieldRow);
        }
     }

     private HBox getOptionsPane(){
        HBox options = new HBox();

        RadioButton bfsRadioButton = new RadioButton("bfs");
        bfsRadioButton.setToggleGroup(toggleGroup);
        bfsRadioButton.setSelected(true);

        RadioButton idsRadioButton = new RadioButton("ids");
        idsRadioButton.setToggleGroup(toggleGroup);

        RadioButton dfsRadioButton = new RadioButton("dfs");
        dfsRadioButton.setToggleGroup(toggleGroup);

        options.getChildren().addAll(run, bfsRadioButton, idsRadioButton, dfsRadioButton);

        options.setPadding(new Insets(15));
        options.setSpacing(5);
        return options;
     }

     private void addRunButtonEventHandler(){
         run.setOnAction(e->{
             RadioButton selectedButton = (RadioButton) toggleGroup.getSelectedToggle();
             StateTreeNode initialState = new StateTreeNode(new Board(extractInputValues(initialStateInputGrids)));
             StateTreeNode finalState = new StateTreeNode(new Board(extractInputValues(finalStateInputGrids)));
             GUITreeGenerator guiTreeGenerator = new GUITreeGenerator(initialState, finalState, selectedButton.getText());
             windowManager.setGuiTreeGenerator(guiTreeGenerator);
         });
     }

    private int[][] extractInputValues(GridPane inputGridPane) {
        int[] valuesLinear  = new int[9];
        int counter = 0;
        for (Node textField: inputGridPane.getChildren()) {
            if(textField instanceof TextField field){
                valuesLinear[counter] = Integer.parseInt(field.getText());
                counter++;
            }
        }

        counter = 0;
        int[][] inputValues = new int[3][3];
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++){
                inputValues[row][col] = valuesLinear[counter];
                counter++;
            }
        }
        return inputValues;
    }

    public WindowManager getWindowManager() {
        return windowManager;
    }

    public void setWindowManager(WindowManager windowManager) {
        this.windowManager = windowManager;
    }
}

