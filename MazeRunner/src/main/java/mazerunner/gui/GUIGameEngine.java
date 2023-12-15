package mazerunner.gui;


import java.io.FileNotFoundException;
import java.io.IOException;

import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import mazerunner.engine.GameEngine;
import mazerunner.engine.Position;

/**
 * GUIGameEngine class which will initialize and oversee all the 
 * game functionalites that need to happen when an event is fired 
 * through the GUI
 */
public class GUIGameEngine extends GameEngine {

    private MapGUI gameMap;
    private PlayerGUI player;
    private TextArea gameLogArea;
    private TextArea playerStatArea;

    public GUIGameEngine(int mapSize) {
        super(mapSize);
        gameMap = new MapGUI(mapSize);
        player = new PlayerGUI();
    }

    /**
     * Method to set the difficulty of the game
     * @param difficulty - the value of difficulty (an int in range of 0 - 10) 
     */
    public void setDifficulty(int difficulty){
        GameEngine.difficulty = difficulty;
        gameMap.setDifficulty(difficulty);
    }

    /**
     * Method that initializes game map and game element (traps, coins etc.) position
     */
    public void startGame(){
        gameMap.generateMap();
    }

    /**
     * Method to initalize the mapgrid on which game element images will sit on
     * @param grid - a GridPane on which game element images will sit on
     */
    public void setMapGrids(GridPane grid){
        gameMap.setGuiGrids(grid);
    }

    /**
     * Method to move the player (player image on the gui) to the next gird in the desired direction
     * @param dirFlag - flag that represents the desired direction
     *                  these can be -w (fo up), -s(for down), -a(for left) and -d(for right)
     * @return - a boolean representing whether the player has moved successfylly or not
     */
    public boolean movePlayer(String dirFlag){
        if(this.getPlayer().isPlayerDead()){
            gameLogArea.setText("GAME OVER! No more stamina.\n" + this.player.getFinalScore());
        }
        if(!(this.player.isPlayerDead()) && (!this.gameOver) && (!this.gameComplete)){
            if(dirFlag.equals("-w")){
                gameLogArea.clear();
                if(!player.movePlayerUp()){
                    gameLogArea.setText("Hit a wall! Move to other direction");
                };
                ifGameElementHitDoAction(player.getPlayerPos());
                gameMap.changePlayerPos(player, player.getPlayerPos());
                return true;
            }

            if(dirFlag.equals("-s")){
                gameLogArea.clear();
                if(!player.movePlayerDown()){
                    gameLogArea.setText("Hit a wall! Move to other direction");
                };
                ifGameElementHitDoAction(player.getPlayerPos());
                gameMap.changePlayerPos(player, player.getPlayerPos());
                return true;
            }

            if(dirFlag.equals("-a")){
                gameLogArea.clear();
                if(!player.movePlayerLeft()){
                    gameLogArea.setText("Hit a wall! Move to other direction");
                };
                ifGameElementHitDoAction(player.getPlayerPos());
                gameMap.changePlayerPos(player, player.getPlayerPos());
                return true;
            }

            if(dirFlag.equals("-d")){
                gameLogArea.clear();
                if(!player.movePlayerRight()){
                    gameLogArea.setText("Hit a wall! Move to other direction");
                };
                ifGameElementHitDoAction(player.getPlayerPos());
                gameMap.changePlayerPos(player, player.getPlayerPos());
                return true;
            }
        }
        return false;
    }

    /**
     * Method that performs the required action (removing apple or coin form map), if the player 
     * hits another game element in the map
     * @param hitPos - position of contact of other game element and player
     */
    private void ifGameElementHitDoAction(Position hitPos){
        if(checkIfPlayerHitsGameObject(player.getPlayerPos(), this.gameMap.getMapGrid())){
            int typeOfObjectHit = typeOfObjectHit(player.getPlayerPos(), this.gameMap.getMapGrid());
            onPlayerHitObject(typeOfObjectHit, player.getPlayerPos());
        }
    }

    /**
     * Method that actually performs the logic when player hits aonther game element in the map
     * @param objectHitType - int code of the game elemnt that has been hit/touched by the player
     * @param hitPos - position of contanct of the game elemnet and player
     */
    private void onPlayerHitObject(int objectHitType, Position hitPos){
        StringBuilder gameLog = new StringBuilder();
        switch (objectHitType) {
            case CoinGUI.COIN_CODE:
                this.player.giveCoinToPlayer(hitPos);
                this.gameMap.removeCoin(hitPos);
                gameLog.append("Yay! Coin Found! Added a coin to your inventory.\n");
                gameLog.append("You can use one coin to pay to get out of a trap considring you are in one.\n");
                break;
            case TrapGUI.TRAP_CODE:
                if(this.player.playerHasCoins()) {
                    this.player.removeCoinFromPlayer();
                    gameLog.append("Trapped. Paid one cone to get out.");
                }else{
                    gameLog.append("No more coin left to pay to get out of the trap.\n");
                    gameLog.append("GAME OVER!\n");
                    gameLog.append(this.player.getFinalScore());
                    this.gameOver = true;
                }
                break;
            case AppleGUI.APPLE_CODE:
                gameLog.append("Yay! Found an apple. Increased your stamina by 3\n");
                gameLog.append("An apple a day, keeps a doctor away.\n");
                this.player.setStamina(this.player.getStamina() + 3);
                this.gameMap.removeApple(hitPos);
                break;
            case MapGUI.EXIT_POSITION_CODE:
                gameLog.append("Yay! found exit door of the maze. You got out of the maze!\n");
                gameLog.append("WON THE GAME\n");
                gameLog.append(this.player.getFinalScore());
                this.gameComplete = true;
                break;
            default:
                gameLog.append("Unexpected Error!");
                break;
        }
        this.gameLogArea.setText(gameLog.toString());
    }

    /**
     * Method that returns this instance of the PlayerGUI
     * @return - a PlayerGUI representing this instance of player
     */
    public PlayerGUI getPlayer(){
        return this.player;
    }

    /**
     * Method that will initalzie the TextArea on which game events wil be displayed during gameplay
     * @param gameLogArea - TextArea on which game events wil be displayed during gameplay
     */
    public void setGameLogArea(TextArea gameLogArea){
        this.gameLogArea = gameLogArea;
    }

    /**
     * Method that will initalzie the TextArea on which playerstats wil be displayed during gameplay
     * @param playerStatArea - TextArea on which playerstats wil be displayed during gameplay
     */

    public void setPlayerStatArea(TextArea playerStatArea){
        this.playerStatArea = playerStatArea;
    }

    /**
     * Method that saves the current state of the game once the 
     * save button is pressed in the UI
     */
    public void saveGame(){
        SaveGame sg = new SaveGame(this.gameMap,this.player);
        try{
            sg.createFile();
            gameLogArea.setText("Game Saved Successfully!");
        }catch(IOException e){
            gameLogArea.setText("Failed to save. Reporting error...");
        }
    }

    /**
     * Method that loads the latest save game state once the load button
     * is pressed in the UI
     */
    public void loadGame(){
        LoadGame lg = new LoadGame();
        try{
            lg.loadSavedGame();
            this.gameMap.setMapGrid(lg.getSaveMapGridsState());
            this.player = lg.getsavedPlayerState();

            this.gameMap.putAppleInMap();
            this.gameMap.putCoinsInMap();
            this.gameMap.putTrapsInMap();
            this.gameMap.putExitDoorOnMap();
            this.gameMap.changePlayerPos(this.player, this.player.getPlayerPos());

            gameLogArea.setText(lg.loadSuccessStatus());
            playerStatArea.setText(this.player.getPlayerStatus());
        }catch(FileNotFoundException e){
            gameLogArea.setText("No saved game file found on disk");
        }  
    }
}
