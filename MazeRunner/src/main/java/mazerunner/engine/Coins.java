package mazerunner.engine;
/**
 * Class that represents the game element - coin and its properties
 */
public class Coins {
    private Position coinPosition; //Current Position of the coin in the map
    public static final int  COIN_CODE = 1; //Coin element's code

    public Coins(Position coinPosition) {
        this.coinPosition = coinPosition;
    }
    /**
     * Method that returns the coin game elemnt code
     * @return - an integer representing coin game element code
     */
    public static int getCoinCode() {
        return COIN_CODE;
    }
    /**
     * Method that returns current Coin's
     * @return - A Position object representing current Coin's Position
     */
    public Position getCoinPosition() {
        return coinPosition;
    }
}
