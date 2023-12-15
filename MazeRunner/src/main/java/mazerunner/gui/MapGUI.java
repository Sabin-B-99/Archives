package mazerunner.gui;

import mazerunner.engine.Map;
import mazerunner.engine.Position;

import java.util.ArrayList;
import java.util.Iterator;

import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import java.io.File;

/**
 * MapGUI class which extends the Map Class represents the map that will 
 * hold all the game elemnts like coin, player and traps in the game.
 */
public class MapGUI extends Map{

    private ArrayList<CoinGUI> coins; //ArrayList of coins which will be place on the game map
    private ArrayList<AppleGUI> apples; //ArrayList of apples which will be place on the game map
    private ArrayList<TrapGUI> traps; //ArrayList of traps which will be place on the game map

    /**
     * ImageView that contains the image of the exit door
     */
    private static final String DOOR_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "img" + File.separator + "exitDoor.png";
    private final ImageView DOOR_IMG = new ImageView(DOOR_IMG_DIR);

    private GridPane guiGrids; //GridPane on which the game element images will sit on

    public MapGUI(int mapSize) {
        super(mapSize);
        this.coins = new ArrayList<CoinGUI>();
        this.traps = new ArrayList<TrapGUI>();
        this.apples = new ArrayList<AppleGUI>();
    }
    
    /**
     * Method that initazlizes map grids and puts game elements and player on the map grid
     */
    @Override
    public void generateMap(){
        super.generateMap();
        putTrapsInMap();
        putCoinsInMap();
        putAppleInMap();
        putPlayerOnMap();
        putExitDoorOnMap();
    }


    /**
     * Method that puts traps images on the map at random position
     */
    public void putTrapsInMap(){
        int[][] mapGrid = this.getMapGrid();

        TrapGUI tGui;
        Position trapPos;
        ImageView trapImage;

        for (int row = 0; row < mapGrid.length; row++){
            for (int col = 0; col < mapGrid[row].length; col++) {
                trapPos = new Position(row, col);
                if(mapGrid[row][col] == TrapGUI.getTarpsCode()){
                    tGui = new TrapGUI(trapPos);
                    trapImage = tGui.get_TRAP_IMG();
                    traps.add(tGui);
                    guiGrids.add(trapImage, col, mapGrid[col].length - 1 - row);
                }
            }
        }
    }

    /**
     * Method that puts coins images on the map at random position
     */
    public void putCoinsInMap(){
        int[][] mapGrid = this.getMapGrid();

        CoinGUI cGui;
        Position coinPos;
        ImageView coinImage;

        for (int row = 0; row < mapGrid.length; row++){
            for (int col = 0; col < mapGrid[row].length; col++) {
                coinPos = new Position(row, col);
                if(mapGrid[row][col] == CoinGUI.getCoinCode()){
                    cGui = new CoinGUI(coinPos);
                    coinImage = cGui.get_COIN_IMG();
                    coins.add(cGui);
                    guiGrids.add(coinImage, col, mapGrid[col].length - 1 - row);
                }
            }
        }
    }

    /**
     * Method that puts apples images on the map at random position
     */
    public void putAppleInMap(){
        int[][] mapGrid = this.getMapGrid();

        AppleGUI aGui;
        Position applePos;
        ImageView appleImage;

        for (int row = 0; row < mapGrid.length; row++){
            for (int col = 0; col < mapGrid[row].length; col++) {
                applePos = new Position(row, col);
                if(mapGrid[row][col] == AppleGUI.getAppleCode()){
                    aGui = new AppleGUI(applePos);
                    appleImage = aGui.get_APPLE_IMG();
                    apples.add(aGui);
                    guiGrids.add(appleImage, col, mapGrid[col].length - 1 - row);
                }
            }
        }
    }

    /**
     * Method that puts player image on the map at bottom left position
     */
    public void putPlayerOnMap(){
        int[][] mapGrid = this.getMapGrid();
        PlayerGUI pGui = new PlayerGUI();
        Position playerPos = pGui.getPlayerPos();
        ImageView playerImage = pGui.get_PLAYER_IMG();
        guiGrids.add(playerImage, playerPos.getY(), mapGrid[playerPos.getY()].length - 1 - playerPos.getX());

    }

    /**
     * Method that puts exit door image on the map at random position
     */
    public void putExitDoorOnMap(){
        int[][] mapGrid = this.getMapGrid();
        for (int row = 0; row < mapGrid.length; row++){
            for (int col = 0; col < mapGrid[row].length; col++) {
                if(mapGrid[row][col] == getExitPositionCode()){
                    guiGrids.add(DOOR_IMG, col, mapGrid[col].length - 1 - row);
                }
            }
        }
    }

    /**
     * Method that initializes GridPane on which game elemnts' image will sit on
     * @param mapGrids - GridPane on which game elemnts' image will sit on
     */
    public void setGuiGrids(GridPane mapGrids){
        this.guiGrids = mapGrids;
    }

    /**
     * Method that will change the position of the player to the new positon and also 
     * puts the player image in that new position removing the image form the old 
     * position in the GridPane
     * 
     * @param player - player instance whose position is to be changed
     * @param newPos - new position to which player is to be moved to
     */
    public void changePlayerPos(PlayerGUI player, Position newPos){
        int[][] mapGrid = this.getMapGrid();
        guiGrids.getChildren().remove(player.get_PLAYER_IMG());
        guiGrids.add(player.get_PLAYER_IMG(), newPos.getY(), mapGrid[newPos.getY()].length - 1 - newPos.getX());
    }
    
    /**
     * Method that will remove the coin element and its image from the map when plyer element 
     * hits the coin elemnt during gameplay
     * @param p - the position form which the coin is to be removed
     */
    public void removeCoin(Position p){
        int x = p.getX();
        int y = p.getY();

        int[][] mapGrid = this.getMapGrid();

        for (Iterator<CoinGUI> it = coins.iterator(); it.hasNext(); ) {
            CoinGUI c = it.next();
            if(c.getCoinPosition().getX() == x && c.getCoinPosition().getY() == y){
                guiGrids.getChildren().remove(c.get_COIN_IMG());
                mapGrid[x][y] = -1;
                it.remove();
            }
        }
    }

    /**
     * Method that will remove the apple element and its image from the map when plyer element 
     * hits the apple elemnt during gameplay
     * @param p - the position form which the apple is to be removed
     */
    public void removeApple(Position p){
        int x = p.getX();
        int y = p.getY();

        int[][] mapGrid = this.getMapGrid();

        for (Iterator<AppleGUI> it = apples.iterator(); it.hasNext(); ) {
            AppleGUI a = it.next();
            if(a.getApplePosition().getX() == x && a.getApplePosition().getY() == y){
                guiGrids.getChildren().remove(a.get_APPLE_IMG());
                mapGrid[x][y] = -1;
                it.remove();
            }
        }
    }
}
