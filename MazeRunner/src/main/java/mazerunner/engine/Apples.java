package mazerunner.engine;

/**
 * Class that represents the game element - apple and its properties
 */
public class Apples {
    private Position applePosition; //Current Position of the apple in the map
    public static final int APPLE_CODE = 3; //Apple element's code

    public Apples(Position applePosition) {
        this.applePosition = applePosition;
    }
    /**
     * Method that returns the apple game elemnt code
     * @return - an integer representing apple game element code
     */
    public static int getAppleCode() {
        return APPLE_CODE;
    }
    /**
     * Method that returns current Apple's
     * @return - A Position object representing current Apple's Position
     */
    public Position getApplePosition() {
        return applePosition;
    }
}
