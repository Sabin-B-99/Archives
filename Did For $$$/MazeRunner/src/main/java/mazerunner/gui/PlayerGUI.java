package mazerunner.gui;

import mazerunner.engine.Player;
import mazerunner.engine.Position;
import javafx.scene.image.ImageView;
import java.io.File;
import java.util.ArrayList;

/**
 * PlayerGUI class that extends form the player class and represents the player and 
 * its image in the game GUI
 */
public class PlayerGUI extends Player{

    /**
     * Fields that imports the player image and put it in the ImageView
     */
    private static final String PLAYER_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "img" + File.separator + "player.png";
    private static final ImageView PLAYER_IMG = new ImageView(PLAYER_IMG_DIR);

    private ArrayList<CoinGUI> collectedCoins; //ArrayList of coins collected by the player during the game
    public PlayerGUI(){
        super();
        this.collectedCoins = new ArrayList<CoinGUI>();
    }

    /**
     * Method that will return the ImageView containing the image of the player
     * @return - ImageView containing the image of the player
     */
    public ImageView get_PLAYER_IMG(){
        return PLAYER_IMG;
    }

    /**
     * Method that will move the player and its image to the left by one gird
     * as well as reduce the player's stamina by one upon success in moving
     * @return - boolean value representing the success(true) of moving the player 
     */
    public boolean movePlayerLeft(){
        Position newPos;
        int currentPlayerX = this.getPlayerPos().getX();
        int currentPlayerY = this.getPlayerPos().getY();
        int newPlayerPosX;
        int newPlayerPosY;
        newPlayerPosX = currentPlayerX;
        newPlayerPosY= currentPlayerY - 1;
        newPos = new Position(newPlayerPosX, newPlayerPosY);
        
        if(!playerHitsBoundary(newPos)){
            this.setPlayerPos(newPos);
            this.setStamina(this.getStamina() - 1);
            return true;
        }
        return false;
    }

    /**
     * Method that will move the player and its image to the right by one gird
     * as well as reduce the player's stamina by one upon success in moving
     * @return - boolean value representing the success(true) of moving the player 
     */
    public boolean movePlayerRight(){
        Position newPos;
        int currentPlayerX = this.getPlayerPos().getX();
        int currentPlayerY = this.getPlayerPos().getY();
        int newPlayerPosX;
        int newPlayerPosY;
        newPlayerPosX = currentPlayerX;
        newPlayerPosY= currentPlayerY + 1;
        newPos = new Position(newPlayerPosX, newPlayerPosY);
        
        if(!playerHitsBoundary(newPos)){
            this.setPlayerPos(newPos);
            this.setStamina(this.getStamina() - 1);
            return true;
        }
        return false;
    }

    /**
     * Method that will move the player and its image up by one gird
     * as well as reduce the player's stamina by one upon success in moving
     * @return - boolean value representing the success(true) of moving the player 
     */
    public boolean movePlayerUp(){
        Position newPos;
        int currentPlayerX = this.getPlayerPos().getX();
        int currentPlayerY = this.getPlayerPos().getY();
        int newPlayerPosX;
        int newPlayerPosY;
        newPlayerPosX = currentPlayerX + 1;
        newPlayerPosY= currentPlayerY;
        newPos = new Position(newPlayerPosX, newPlayerPosY);
        
        if(!playerHitsBoundary(newPos)){
            this.setPlayerPos(newPos);
            this.setStamina(this.getStamina() - 1);
            return true;
        }
        return false;
    }

    /**
     * Method that will move the player and its image down by one gird
     * as well as reduce the player's stamina by one upon success in moving
     * @return - boolean value representing the success(true) of moving the player 
     */
    public boolean movePlayerDown(){
        Position newPos;
        int currentPlayerX = this.getPlayerPos().getX();
        int currentPlayerY = this.getPlayerPos().getY();
        int newPlayerPosX;
        int newPlayerPosY;
        newPlayerPosX = currentPlayerX - 1;
        newPlayerPosY= currentPlayerY;
        newPos = new Position(newPlayerPosX, newPlayerPosY);
        
        if(!playerHitsBoundary(newPos)){
            this.setPlayerPos(newPos);
            this.setStamina(this.getStamina() - 1);
            return true;
        }
        return false;
    }

    /**
     * Method that adds a coin to the player's collection
     * @param - the position in the map at which the coin was collected
     */
    public void giveCoinToPlayer(Position coinPos){
        CoinGUI coin = new CoinGUI(coinPos);
        collectedCoins.add(coin);
    }

    /**
     * Method that reduces the coin in the player collection by one
     */
    public void removeCoinFromPlayer(){
        int totalCoins = collectedCoins.size();
        collectedCoins.remove(totalCoins - 1);
    }

    /**
     * Method that checks whether the player has a coin in his collection or not
     * @return - a boolean representing whether the player has a coin (true) in his collection or not (false)  
     */
    public boolean playerHasCoins(){
        return (!collectedCoins.isEmpty());
    }

    /**
     * Method that returns a String representing the player's current stamina and total no of
     * coins in player's collection
     * @return - a String representing the player's current stamina and total no of coins in player's collection
     */
    public String getPlayerStatus(){
        StringBuilder status = new StringBuilder();
        status.append("Player Coins: ").append(this.collectedCoins.size()).append('\n');
        status.append("Player Stamina: ").append(this.stamina).append('\n');
        return status.toString();
    }

    /**
     * Method that returns a String representing the player's final score when game ends
     * The final score is the total number of coin the player has collected.
     * @return - a String representing the player's final score when game ends
     */
    public String getFinalScore(){
        StringBuilder finScore = new StringBuilder();
        finScore.append("*********************************\n");
        finScore.append("Final Score: ").append(this.collectedCoins.size()).append('\n');
        finScore.append("*********************************\n");
        return finScore.toString();
    }

    public ArrayList<CoinGUI> getCollecteCoinGUIs(){
        return this.collectedCoins;
    }
}
