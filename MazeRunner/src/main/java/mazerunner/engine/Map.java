package mazerunner.engine;


import java.util.ArrayList;
import java.util.Random;

/**
 * Map Class represents the 2d map of the game which will 
 * hold all the game elemnts like coin, player and traps 
 * in the game.
 */

public class Map {
    private int mapSize; //size of the map
    private int[][] mapGrid; //2d array that represents the map and its grids 
    private ArrayList<Coins> coins; //ArrayList of coins that will be placed int the map randomly
    private ArrayList<Apples> apples; //ArrayList of apples that will be placed int the map randomly
    private ArrayList<Traps> traps; //ArrayList of traps that will be placed int the map randomly
    private Position exitPosition; //Position of the exit door at the map
    private boolean exitPosSet; //boolean value that represents whether the exit door and its position has been generated and set at the map randomly 
    private int difficulty; //game difficulty (ranges for 0-10, 10 is the hardest)
    public static final int EXIT_POSITION_CODE = 4; //code of the exit door. This code can be used by methods to find the exit position in the map

    public Map(int mapSize){
        this.mapSize = mapSize;
        this.mapGrid = new int[mapSize][mapSize];
        difficulty = GameEngine.getDifficulty();
        this.coins = new ArrayList<Coins>();
        this.traps = new ArrayList<Traps>();
        this.apples = new ArrayList<Apples>();
        exitPosSet = false;
    }

    /**
     * Method that initazlizes map grids and puts game elements on the map grid at random positions and player at bottom left position
     */
    public void generateMap(){
        initializeGrids();
        generateCoinsAtRandom();
        generateTrapsAtRandom();
        generateApplesAtRandom();
        generateExitAtRandom();
    }

    /**
     * Method that checks whether the a single grid(box) of the map cointains a game elemnet/object (coins, traps, player etc.) or not
     * @param p - Position in which a game elemnet's existence on the map is to be checked
     * @return - true if the game element exits at the provided position, false if not found
     */
    private boolean gridContainsGameObject(Position p){
        int row = p.getX();
        int col = p.getY();
        if (mapGrid[row][col] != -1){
            return true;
        }
        return false;
    }

    /**
     * Method that generates a Position object with random x and y values, but both the x and y wont be zero simaltenously
     * @return - Position object with a random x and y values, but both the x and y wont be zero simaltenously 
     */
    private mazerunner.engine.Position generateRandomPosition(){
        Random random = new Random();
        int x  = 0;
        int y = 0;

        while (x == 0 && y == 0) {
            x = random.nextInt(mapSize);
            y = random.nextInt(mapSize);
        }
        mazerunner.engine.Position rndPos = new mazerunner.engine.Position();
        rndPos.setX(x);
        rndPos.setY(y);
        return rndPos;
    }

    /**
     * Method that puts a coin element at the random position of the map. Two game elements will never
     * be placed in the same grid.
     */
    private void generateCoinsAtRandom(){
        mazerunner.engine.Position coinPos;
        
        int totalCoinsInMap = 0;
        int coinsX = 0;
        int coinsY = 0;
        while (totalCoinsInMap < 5){
            coinPos = generateRandomPosition();
            if(!gridContainsGameObject(coinPos) ){
                coinsX = coinPos.getX();
                coinsY = coinPos.getY();
                coins.add(new Coins(coinPos));
                totalCoinsInMap++;
                mapGrid[coinsX][coinsY] = Coins.getCoinCode();
            }
            
        }
    }

    /**
     * Method that puts a trap element at the random position of the map. Two game elements will never
     * be placed in the same grid.
     */
    private void generateTrapsAtRandom(){
        mazerunner.engine.Position trapPos;

        int totalTrapsInMap = 0;
        int trapsX = 0;
        int trapsY = 0;
        while (totalTrapsInMap < difficulty){
            trapPos = generateRandomPosition();
            if(!gridContainsGameObject(trapPos) ){
                trapsX = trapPos.getX();
                trapsY = trapPos.getY();
                traps.add(new Traps(trapPos));;
                totalTrapsInMap++;
                mapGrid[trapsX][trapsY] = Traps.getTarpsCode();
            }
        }
    }

    /**
     * Method that puts a apple element at the random position of the map. Two game elements will never
     * be placed in the same grid.
     */
    private void generateApplesAtRandom(){
        mazerunner.engine.Position applePos;

        int totalApplesInMap = 0;
        int appleX = 0;
        int appleY = 0;

        while (totalApplesInMap < (10 - difficulty)){
            applePos = generateRandomPosition();
            if(!gridContainsGameObject(applePos) ){
                appleX = applePos.getX();
                appleY = applePos.getY();
                apples.add(new Apples(applePos));;
                totalApplesInMap++;
                mapGrid[appleX][appleY] = Apples.getAppleCode();
            }
        }
    }

    /**
     * Method that puts a exit door element at the random position of the map. Two game elements will never
     * be placed in the same grid.
     */
    private void generateExitAtRandom(){
        Position exitPos;
        while(!exitPosSet){
            exitPos= generateRandomPosition();
            if(!gridContainsGameObject(exitPos)){
                this.exitPosition = exitPos;
                mapGrid[exitPos.getX()][exitPos.getY()] = EXIT_POSITION_CODE;
                this.exitPosSet = true;
            }
        }
    }
    
    /**
     * Method that initializes the values of all the indexes of the 2d array, that represents the game map, with a 
     * value of -1. If the value of a certain int[x][y] is -1 then that grid of the game map is empty.
     */
    private void initializeGrids(){
        for (int row = 0; row < mapGrid.length; row++){
            for (int col = 0; col < mapGrid[row].length; col++) {
                mapGrid[row][col] = -1;
            }
        }
    }

    /**
     * Method that removes the coin present at the Position p of the game map.
     * @param p -  Position form which the coin is to be removed
     */
    public void removeCoin(Position p){
        int x = p.getX();
        int y = p.getX();
        mapGrid[x][y] = -1;
        for (Coins c: coins) {
            if(c.getCoinPosition().getX() == x && c.getCoinPosition().getY() == y){
                coins.remove(c);
                mapGrid[x][y] = -1;
            }
        }
    }

    /**
     * Method that removes the trap present at the Position p of the game map.
     * @param p -  Position form which the trap is to be removed
     */
    public void removeTraps(Position p){
        int x = p.getX();
        int y = p.getX();
        for (Traps t: traps) {
            if(t.getTrapPosition().getX() == x && t.getTrapPosition().getY() == y){
                traps.remove(t);
                mapGrid[x][y] = -1;
            }
        }
    }

    /**
     * Method that removes the apple present at the Position p of the game map.
     * @param p -  Position form which the apple is to be removed
     */
    public void removeApples(Position p){
        int x = p.getX();
        int y = p.getX();
        for (Apples a: apples) {
            if(a.getApplePosition().getX() == x && a.getApplePosition().getY() == y){
                apples.remove(a);
                mapGrid[x][y] = -1;
            }
        }
    }

    /**
     * Method that returns the 2d array that represents the game map
     * @return - a 2d array of int type, this array represents the game map
     */
    public int[][] getMapGrid() {
        return mapGrid;
    }

    /**
     * Method that puts a game element (traps, coinsn, etc) at the desired Position with in the grid of the map
     * @param pos - Position at which the game element is to be placed
     * @param objectCode -  the type of game element that is to be placed 
     */
    public void setMapGridElement(Position pos, int objectCode) {
        this.mapGrid[pos.getX()][pos.getY()] = objectCode;
    }

    /**
     * Method that sets the game difficulty
     * @param difficulty - game difficulty (range: 0 - 10, where 10 is the hardest)
     */
    public void setDifficulty(int difficulty){
        this.difficulty = difficulty;
    }

    /**
     * Method that returns the Position of the exit door placed in the map
     * @return - Position object representing the position of the exit door placed in the map
     */
    public Position getExiPosition(){
        return this.exitPosition;
    }

    /**
     * Method that returns the exit door code
     * @return - an int representing the exit door code
     */
    public static int getExitPositionCode(){
        return EXIT_POSITION_CODE;
    }

    /**
     * Method that displays the position of all the game elements after the map has been generated.
     * Can be used for text based play.
     */
    public void showMapInitializationStats(){
        System.out.println("**********************************************************************************");
        int i = 0;
        for (Apples a : apples) {
            System.out.println("Apple " + (i+1) + " Position(row,col): " + a.getApplePosition().getX() + ", " + a.getApplePosition().getY());
            i++;
        }
        System.out.println("**********************************************************************************");
        i = 0;
        for (Coins c : coins) {
            System.out.println("Coin " + (i+1) + " Position(row,col): " + c.getCoinPosition().getX() + ", " + c.getCoinPosition().getY());
            i++;
        }
        System.out.println("**********************************************************************************");
        i = 0;
        for (Traps t : traps) {
            System.out.println("Trap " + (i+1) + " Position(row,col): " + t.getTrapPosition().getX() + ", " + t.getTrapPosition().getY());
            i++;
        }
    }

    /**
     * Method that returns the size of the map
     * @return - an int representing the size of the map
     */
    public int getMapSize(){
        return this.mapSize;
    }
    /**
     * Method that reurnts current map difficulty
     * @return - an integer representing current map difficulty
     */
    public int getDifficulty(){
        return this.difficulty;
    }

    /**
     * Method that sets the 2d array that represents the map grid with new value
     * provided in its parameter
     * @param mapGrid - new 2d array that is to be set as a map grid
     */
    public void setMapGrid(int[][] mapGrid){
        this.mapGrid = mapGrid;
    }
}
