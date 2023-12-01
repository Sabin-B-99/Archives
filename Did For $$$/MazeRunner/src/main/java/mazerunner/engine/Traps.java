package mazerunner.engine;

/**
 * Class that represents the game element - traps and its properties
 */
public class Traps {
    private Position trapPosition; //Current Position of the trap in the map
    public static final int TRAP_CODE = 2; //Trap element's code

    public Traps(Position trapPosition) {
        this.trapPosition = trapPosition;
    }

    /**
     * Method that returns the trap game elemnt code
     * @return - an integer representing trap game element code
     */
    public static int getTarpsCode() {
        return TRAP_CODE;
    }
    /**
     * Method that returns current Trap's
     * @return - A Position object representing current Trap's Position
     */
    public Position getTrapPosition() {
        return trapPosition;
    }
}
