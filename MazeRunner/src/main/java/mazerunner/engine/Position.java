package mazerunner.engine;

/**
 * A class that represents a 2d point/position
 */
public class Position{
    private int x; // x-axis point
    private int y; //y-axis point

    public Position(){
        this.x = 0;
        this.y = 0;
    }

    public Position(int x, int y){
        this.x  = x;
        this.y = y;
    }
    /**
     * Method that returns an integer representing the x-axis value of the 2d point/position
     * @return - an integer representing the x-axis point
     */
    public int getX() {
        return x;
    }

    /**
     * Method that sets the x-axis value of the current 2d point/position
     * @param x - an integer representing the new x-axis value for the current 2d point/position
     */
    public void setX(int x) {
        this.x = x;
    }
    /**
     * Method that returns an integer representing the y-axis value of the 2d point/position
     * @return - an integer representing the y-axis point
     */
    public int getY() {
        return y;
    }

    /**
     * Method that sets the y-axis value of the current 2d point/position
     * @param y - an integer representing the new y-axis value for the current 2d point/position
     */
    public void setY(int y) {
        this.y = y;
    }

}
