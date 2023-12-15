package mazerunner.gui;

import java.io.FileReader;
import java.util.Scanner;
import java.util.regex.Pattern;

import mazerunner.engine.Position;

import java.io.File;
import java.io.FileNotFoundException;

/**
 * Class that loads the latest save state of game
 */
public class LoadGame {
    private PlayerGUI savedPlayerState; //last saved player game and its properties
    private int[][] mapGrid; //last saved game map grid to be loaded
    private static Scanner loader; //save game .txt file reader
    private String[] positionXY; //x-val and y-val  of player coins position read from saved file 
    private boolean mapStateAndPlayerStateSeparatorFound = false; //saved player and saved map state seperator in the file

    public LoadGame(){
        mapGrid = new int[10][10];
        this.savedPlayerState = new PlayerGUI();
    }

    /**
     * Method that loads the save file from the disk and initializes the map state and 
     * player state to the last saved state
     * @throws FileNotFoundException - throws when no saved game file is found on disk
     */
    public void loadSavedGame() throws FileNotFoundException{
        String saveDirectory = System.getProperty("user.dir") + File.separator + "savefile.txt";
        loader = new Scanner(new FileReader(saveDirectory));
        initializeMapSAndPlayertate();
        loader.close();
    }

    /**
     * Method that actually initializs the current Map and player state to the 
     * last saved state
     */
    private void initializeMapSAndPlayertate(){
        savedPlayerState = new PlayerGUI();
        Position playerPos = new Position(); //position of last saved player
        Position coinPos; //position of all the coins that the last saved player had in his/her collection
        
        Pattern separator = Pattern.compile("-+");
        
        String rawLine;

        int mapGridRow = 0;
        int mapGridCol = 0;
        while(loader.hasNextLine()){
            rawLine = loader.nextLine();

            if(!rawLine.equalsIgnoreCase(" ")){
                if(loader.hasNext(separator)){
                    mapGrid[mapGridRow][mapGridCol] = Integer.parseInt(rawLine); //initializing the int [9][9] index of current map state form the last saved state
                    mapStateAndPlayerStateSeparatorFound = true;
                    loader.nextLine(); //reading the '------'  seperator
                    rawLine = loader.nextLine(); //reading the first line after the separator has been found
                    savedPlayerState.setStamina(Integer.parseInt(rawLine)); //setting the current player stamina from last saved player
                    rawLine = loader.nextLine(); //reading the second line after seperaor
                    playerPos = findSavedPlayerPosition(rawLine);
                }
                
                if(mapStateAndPlayerStateSeparatorFound){
                    if(loader.hasNextLine()){
                        rawLine = loader.nextLine(); //reading the second line after the seperator
                    }
                    positionXY = rawLine.split(","); //splitiing the last save players coins position in an array
                    coinPos = new Position(Integer.parseInt(positionXY[0]),Integer.parseInt(positionXY[1]));
                    savedPlayerState.giveCoinToPlayer(coinPos);
                }else{
                    /*
                    * Reading the last saved map state
                    */
                    mapGrid[mapGridRow][mapGridCol] = Integer.parseInt(rawLine);
                    mapGridCol++;
                    if(mapGridCol == 10){
                        mapGridRow++;
                        mapGridCol = 0;
                    }
                }
            }
        }
        this.savedPlayerState.setPlayerPos(playerPos);
    }

    /**
     * Method that searches for the last player position in the map
     * @return - a position object representing the latest player position in the map
     */
    private Position findSavedPlayerPosition(String playerPos){
        int xPos = 0;
        int yPos = 0;
        String[] playerPosXY = playerPos.split(",");
        xPos = Integer.parseInt(playerPosXY[0]);
        yPos = Integer.parseInt(playerPosXY[1]);
        return new Position(xPos, yPos);
    }

    /**
     * Method that returns the last map saved state
     * @return - a 2d array representing the the last map saved state
     */
    public int[][] getSaveMapGridsState(){
        return this.mapGrid;
    }

    /**
     * Method that returns the last saved player state
     * @return - A PlayerGUI object representing the last saved player state
     */
    public PlayerGUI getsavedPlayerState(){
        return this.savedPlayerState;
    }

    /**
     * Method that returns a string indicating game loading success
     * @return - a String indicating game loading success
     */
    public String loadSuccessStatus(){
        StringBuilder status = new StringBuilder();
        status.append("Game Loaded Successfully!\n");
        return status.toString();
    }
}
