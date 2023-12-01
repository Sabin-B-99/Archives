package mazerunner.gui;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import mazerunner.engine.Position;

/**
 * Class that saves the state of the game in a .txt file when the player
 * saves the game.
 * 
 * The game states are saved in the .txt file
 * A seperator "-----" is used to seperate the map state and player state
 * Map state is saved above the seperator
 * Player state is saved below the seperator 
 * 
 * First line after the seperator represents the last saved state player's stamina
 * Second line after the seperator represents the Position of the last saved state player
 * Through third to second to last represents the Position of the last saved state player's coins
 * last line after the separator is an empty line
 */
public class SaveGame {
    private MapGUI mapState; //Current map state that is to be saved
    private PlayerGUI playerState; //Curret player state that is to be saved
    private FileWriter saveFile; 
    private BufferedWriter saver;

    public SaveGame(MapGUI mapState, PlayerGUI playerState){
        this.mapState = mapState;
        this.playerState = playerState;
    }
    
    /**
     * Method that creates a save file if no save file is found on disk
     * otherwise, the method will overwrite the existing file
     * And save the current player and map state when save button is pressed in the UI
     * @throws IOException
     */
    public void createFile() throws IOException{
        String saveDirectory = System.getProperty("user.dir") +File.separator + "savefile.txt";
        saveFile = new FileWriter(saveDirectory, false);
        saver = new BufferedWriter(saveFile);
        writeMapStateToFile();
        writePlayerStateToFile();
        saver.close();
    }

    /**
     * Method that writes the current map state to the save file
     */
    private void writeMapStateToFile(){
        int[][] mapGrid = mapState.getMapGrid();
        try {
            for(int row = 0; row < mapGrid.length; row++){
                for(int col = 0; col < mapGrid[row].length; col++){
                    saver.write(String.valueOf(mapGrid[row][col]));
                    saver.write('\n');
                }
            }
        } catch (IOException e) {
            System.out.println("Error: WirteMap State To File");
        }
    }

    /**
     * Method that writes the current player state to the file
     */
    private void writePlayerStateToFile(){
        ArrayList<CoinGUI> playerCoins = playerState.getCollecteCoinGUIs();
        Position coinPos;
        try{
            saver.write("-----\n");
            saver.write(String.valueOf(playerState.getStamina()) + "\n");
            Position playerPos = playerState.getPlayerPos();
            saver.write(playerPos.getX() +"," + playerPos.getY() + "\n");
            for (CoinGUI coinGUI : playerCoins) {
                coinPos = coinGUI.getCoinPosition();
                saver.write(String.valueOf(coinPos.getX() + "," + String.valueOf(coinPos.getY()) + "\n"));
            }
        }catch(IOException e){
            System.out.println("Error: WirtePlayer State To File");
        }
    }
}
