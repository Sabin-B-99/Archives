package mazerunner.engine;
import java.util.Scanner;

/**
 * Class that initalizes and handles all the events and functionalites of 
 * the game
 */
public class GameEngine {
    
    protected static int difficulty = 5; //inital game difficulty
    private static Scanner input = new Scanner(System.in); //scanner to read user input for direction and setting game difficulty for console based play
    protected boolean gameOver = false; //a boolean representing whether the game is over on not
    protected boolean gameComplete = false; //a boolean representing whether the game is complete or not

    private Map gameMap; //Map object that represents the game map
    private Player player; //Player that represents the player placed at the bottom left gird of the game

    public GameEngine(int mapSize){
        gameMap = new Map(mapSize);
        player = new Player();
    }

    /**
     * Method that initalzies the inital game states such as map generation placing
     * different game elements at random grids before the main game loop actually starts.
     * This method also sets the inital difficulty of the game, show game instruction as
     * well as inital map state after the map has been initialized
     */
    public void startGame(){
        System.out.println(GameEngine.showHelpText());
        setDifficulty();
        gameMap.generateMap();

        Position exitPos = gameMap.getExiPosition();
        System.out.println("Exit Position (row,col): " + exitPos.getX() + ", " + exitPos.getY());
        gameMap.showMapInitializationStats();
    }
    /**
     * Method that contains the main game loop. Reads the playe's movement direction 
     * and updates game's state after every move. This game loop is used for the console
     * based play of this game.
     */
    public void updateGame(){
        String dir;
        while (true){
            System.out.println("**********************************************************************************");
            System.out.println("Player Current Position (row,col): " + this.player.getPlayerPos().getX() + ", " + this.player.getPlayerPos().getY());
            System.out.println(this.player.getPlayerStatus());
            dir = readInputDirection();
            if(player.changePlayerPosition(dir)){
                if(checkIfPlayerHitsGameObject(player.getPlayerPos(), gameMap.getMapGrid())){
                    int objectTypeHit = typeOfObjectHit(player.getPlayerPos(), gameMap.getMapGrid());
                    onPlayerHitObject(objectTypeHit);
                }
            }
            if(gameOver || gameComplete || player.isPlayerDead()){
                if(player.isPlayerDead()){
                    System.out.println("No more Stamina");
                    System.out.println("You Died. Game Over.");
                }
                System.out.println(this.player.getFinalScore());
                break;
            }
        }
        input.close();
    }

    /**
     * Method that checks whether the player in the map hits another game element/object (coins,traps etc)
     * or not. 
     * @param hPosition - Position in which the collosion between the player and other game elemnt
     * @param mapGrid - A 2d array representing the game map in which the collision is to be checked
     * @return - true if collision occurs, false otherwise
     */
    protected boolean checkIfPlayerHitsGameObject(Position hPosition, int[][] mapGrid){
        int x = hPosition.getX();
        int y = hPosition.getY();
        boolean playerHitObject = (mapGrid[x][y] == Coins.COIN_CODE) || (mapGrid[x][y] == Traps.TRAP_CODE)
                || (mapGrid[x][y] == Apples.APPLE_CODE) || (mapGrid[x][y] == Map.EXIT_POSITION_CODE);

        if(playerHitObject){
            return true;
        }
        return false;
    }

    /**
     * Method that returns the type of game element that a Player element collides with in the map
     * @param hPosition - Position in which the collision has occured
     * @param mapGrid - 2d array Map in which the collision has occured
     * @return - an integer representing the game elemnt code with which the player has collided
     */
    protected int typeOfObjectHit(Position hPosition, int[][] mapGrid){
        int x = hPosition.getX();
        int y = hPosition.getY();
        return mapGrid[x][y];
    }

    /**
     * Method that takes a specific action after the player element collides with other game elements
     * @param objectHitType - Code of game element with which the player has collided
     */
    private void onPlayerHitObject(int objectHitType){
        switch (objectHitType){
            case Coins.COIN_CODE:
                this.player.giveCoinToPlayer(this.player.getPlayerPos());
                this.gameMap.removeCoin(this.player.getPlayerPos());
                this.gameMap.setMapGridElement(this.player.getPlayerPos(), -1);
                System.out.println("Yay! Found a coin");
                System.out.println("At Position (row,col): " + this.player.getPlayerPos().getX() + ", " + this.player.getPlayerPos().getY());
                System.out.println("Coin Increased");
                break;
            case Traps.TRAP_CODE:
                System.out.println("Hit a trap!");
                System.out.println("At Position (row,col): " + this.player.getPlayerPos().getX() + ", " + this.player.getPlayerPos().getY());
                if(player.playerHasCoins()) {
                    this.player.removeCoinFromPlayer();
                    System.out.println("Paid a coin to get out of trap");
                    System.out.println("Coin Decreased");
                }else{
                    this.gameOver = true;
                    System.out.println("No coin to pay to get out of trap. Game Over");
                }
                break;
            case Apples.APPLE_CODE:
                System.out.println("Yay! Found an apple. An apple a day keeps the doctor away.");
                System.out.println("At Position (row,col): " + this.player.getPlayerPos().getX() + ", " + this.player.getPlayerPos().getY());
                System.out.println("Stamina Increased");
                this.player.setStamina(this.player.getStamina() + 3);
                this.gameMap.removeApples(this.player.getPlayerPos());
                this.gameMap.setMapGridElement(this.player.getPlayerPos(), -1);
                break;
            case Map.EXIT_POSITION_CODE:
                System.out.println("Found the exit door");
                System.out.println("At Position (row,col): " + this.player.getPlayerPos().getX() + ", " + this.player.getPlayerPos().getY());
                System.out.println("Game won!");
                this.gameComplete = true;
                break;
            default:
                System.out.println("Unexpected error: GameManager.java");
                break;
        }
    }
    /**
     * Method that returns current game difficulty
     * @return - an integer representing the game difficulty
     */
    public static int getDifficulty() {
        return difficulty;
    }

    /**
     * Method that sets current game difficuly after reading it from the 
     * user's keyboard.
     */
    private void setDifficulty(){
        difficulty = readDifficulty();
        this.gameMap.setDifficulty(difficulty);;
    }

    /**
     * Method that reads the direction to which the player needs to be moved
     * @return - a String representing the movement direction
     */
    private static String readInputDirection(){
        String moveKey;
        System.out.println("Enter key(Direction) to move: w(up),a(left),s(down),d(right)");
        while (true){
            moveKey = input.nextLine();
            boolean correctInput = moveKey.equalsIgnoreCase("w") || moveKey.equalsIgnoreCase("a")
                    || moveKey.equalsIgnoreCase("s") || moveKey.equalsIgnoreCase("d");
            if(correctInput){
                break;
            }else{
                System.out.println("Valid Keys(direction): w(up),a(left),s(down),d(right)");
            }
        }
        return moveKey;
    }
    /**
     * Method that reads the game difficulty form the keyboard of the user
     * @return - an integer representing difficulty provided by the user through his keyboard
     */
    private static int readDifficulty(){
        int d;
        System.out.println("Enter Difficulty: Difficulty should be in range of 1 - 10");
        while (true){
            d = input.nextInt();
            input.nextLine();
            if(d >= 0 && d <= 10){
                break;
            }else{
                System.out.println("Difficulty should be in range of 1 - 10");
            }
        }
        return d;
    }
    /**
     * Method that returns a string representing the game instructions
     * @return - A string representing the game instructions
     */
    public static String showHelpText(){
        StringBuilder helpText = new StringBuilder();
        helpText.append("*************** Welcome to MazeRunner ****************\n");
        helpText.append("The goal of this game is to get out of the maze evading traps,\n");
        helpText.append("while collecting coins, keeping your stamina high.\n");
        helpText.append("Rules of game: \n");
        helpText.append("Collect as much coin as you can. \n");
        helpText.append("If you fall in a trap, you have to pay a single coin to get out.\n");
        helpText.append("If you have no coins and you are in a trap then, it is GAME OVER!\n");
        helpText.append("Along with traps and coins, there are apples in this game\n");
        helpText.append("On collecting one apple, it will increase your stamina by 3\n");
        helpText.append("You will have 12 stamina initially.\n");
        helpText.append("Each move will cost you one stamina.\n");
        helpText.append("If you have zero stamina before finding the exit door.\n");
        helpText.append("then, it is GAME OVER!\n");
        helpText.append("Reach the exit door without delpeting your stamina, collecting as much\n"); 
        helpText.append("coin as possible to win the game\n");
        helpText.append("Your final score will be the number of coins you will have collected.\n");
        helpText.append("Traps, coins and apples will always be generated at random with every new game.\n");
        helpText.append("************************* ENJOY *********************************\n");
        return helpText.toString();
    }
    /**
     * Main method for the console based play of the game 
     * @param args - optional arguments
     */
    public static void main(String[] args) {
        GameEngine ge = new GameEngine(10);
        ge.startGame();
        ge.updateGame();
    }
}
