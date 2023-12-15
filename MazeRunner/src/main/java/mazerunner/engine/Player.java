package mazerunner.engine;


import java.util.ArrayList;

/**
 * Player Class that represents a player and its properties
 * in the game.
 */
public class Player {
    protected int stamina; //stamina of the player (initally, 12)
    private ArrayList<Coins> collectedCoins; //List of all the coins in the player collection
    protected Position playerPos; //current position of the player in the game
    public static final int PLAYER_CODE = 0; //code that represents the player in the game

    public Player(){
        this.stamina = 12;
        this.collectedCoins = new ArrayList<Coins>();
        this.playerPos = new Position(0,0);
    }

    /**
     * Method that returns the code that represents the player in the game
     * @return - an integer representing the player
     */
    public static int getPlayerCode() {
        return PLAYER_CODE;
    }

    /**
     * Method that sets the position of the player
     * @param playerPos - new position of the player 
     */
    public void setPlayerPos(Position playerPos) {
        this.playerPos = playerPos;
    }

    /**
     * method that returns the current position of the player
     * @return - Position object representing current position of the player
     */
    public Position getPlayerPos() {
        return playerPos;
    }

    /**
     * Method that returns the current stamina of the player
     * @return - an integer representing the current stamina of the player
     */
    public int getStamina() {
        return stamina;
    }

    /**
     * Method that sets a new stamina of the player
     * @param stamina - int representing new stamina
     */
    public void setStamina(int stamina) {
        this.stamina = stamina;
    }

    /**
     * Method that checks whether the player has stamina left or not.
     * Stamina should always be greater that 0 in the game for player to be able to move
     * @return - true if stamina is greater than zero (player has stamina), else false (player has no more stamina to move)
     */
    public boolean isPlayerDead(){
        if(this.stamina <= 0){
            return true;
        }
        return false;
    }

    /**
     * Methood that changes the position of the player (moves the player) to a new position once the user moves the player form 
     * one grid to another in the game. Also reduces playrs stamina by one after each movement
     * @param moveDirection - a string representing on which direction the player is to be moved. Valid inputs(movement direction) are: 
     *                        w(up), s(down), a(left), d(right)
     * @return - a boolean representing the success of movement. true if the player has moved to a new grid and changed position, false otherwise
     */
    public boolean changePlayerPosition(String moveDirection){
        Position newPos;
        int currentPlayerX = this.playerPos.getX();
        int currentPlayerY = this.playerPos.getY();
        int newPlayerPosX;
        int newPlayerPosY;

        if(moveDirection.equalsIgnoreCase("w")){
            newPlayerPosX = currentPlayerX + 1;
            newPlayerPosY= currentPlayerY;
            newPos = new Position(newPlayerPosX, newPlayerPosY);
            if(!playerHitsBoundary(newPos)){
                this.playerPos.setX(newPos.getX());
                this.playerPos.setY(newPos.getY());
                this.stamina--;
                return true;
            }else {
                System.out.println("Player Hit a wall");
            }
        }

        if(moveDirection.equalsIgnoreCase("s")){
            newPlayerPosX = currentPlayerX - 1;
            newPlayerPosY= currentPlayerY;
            newPos = new Position(newPlayerPosX, newPlayerPosY);
            if(!playerHitsBoundary(newPos)){
                this.playerPos.setX(newPos.getX());
                this.playerPos.setY(newPos.getY());
                this.stamina--;
                return true;
            }else {
                System.out.println("Player Hit a wall");
            }
        }

        if(moveDirection.equalsIgnoreCase("d")){
            newPlayerPosX = currentPlayerX;
            newPlayerPosY= currentPlayerY + 1;
            newPos = new Position(newPlayerPosX, newPlayerPosY);
            if(!playerHitsBoundary(newPos)){
                this.playerPos.setX(newPos.getX());
                this.playerPos.setY(newPos.getY());
                this.stamina--;
                return true;
            }else {
                System.out.println("Player Hit a wall");
            }
        }

        if(moveDirection.equalsIgnoreCase("a")){
            newPlayerPosX = currentPlayerX;
            newPlayerPosY= currentPlayerY - 1;
            newPos = new Position(newPlayerPosX, newPlayerPosY);
            if(!playerHitsBoundary(newPos)){
                this.playerPos.setX(newPos.getX());
                this.playerPos.setY(newPos.getY());
                this.stamina--;
                return true;
            }else {
                System.out.println("Player Hit a wall");
            }
        }
        return false;
    }

    /**
     * Method that checks whether the player hits a grid/map boundaries or not.
     * @param newPos - new position to which player has to move
     * @return - boolean represents whether the player hits the map boundary or not: true if player hits the boundaries, false otherwise
     */
    protected boolean playerHitsBoundary(Position newPos){
        int newPlayerPosX = newPos.getX();
        int newPlayerPosY = newPos.getY();

        if(newPlayerPosX < 0 || newPlayerPosX > 9){
            return true;
        }

        if(newPlayerPosY < 0 || newPlayerPosY > 9){
            return true;
        }
        return false;
    }

    /**
     * Method that adds a coin to the player's collection
     * @param - the position in the map at which the coin was collected
     */
    public void giveCoinToPlayer(Position coinPos){
        Coins coin = new Coins(coinPos);
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
}
