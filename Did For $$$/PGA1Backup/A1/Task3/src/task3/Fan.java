package task3;


import java.util.HashMap;

/**
 * Class that contains information of different fan speed types
 * The fan speed values are:
 * off,slow, medium, and fast with their corresponding integer
 * values being 1,2,3 and 4 respectively
 */
public class Fan {
    
    /**
     * An enum representing fan speed. The fan speed values are:
     * off,slow, medium, and fast with their corresponding integer
     * values being 1,2,3 and 4 respectively
     */
    private enum FanSpeedType{
        Off(1),
        Slow(2),
        Medium(3),
        Fast(4);

        private final int fanTypeIndex; //corresponding values of all the fanspeed types: can be 1,2,3 or 4
        private static HashMap<Integer, FanSpeedType> fanTypes = new HashMap<>(); 

        //constructor for the enum
        FanSpeedType(int fanTypeIndex) {
            this.fanTypeIndex = fanTypeIndex;
        }
        
        /**
         * Method to return the current correspoding integer value of the current FanSpeedType
         * @return
         */
        private int getfanTypeIndex() {
            return this.fanTypeIndex;
        }

        /**
         * Static block to add all four fan speed type in a hashmap with key being the 
         * corresponding number of the fan speed type 
         */
        static{
            for (FanSpeedType fs : FanSpeedType.values()) {
                fanTypes.put(fs.fanTypeIndex, fs);
            }
        }

        /**
         * Method that returns the Fan Speed Type depending upon the integer value corresponding to the
         * speed type
         * @param value an integer representing the value of fanspeed type that is to be returned
         * @return FanSpeedType that will be returned depending upon the integer passed as parameter
         */
        private static FanSpeedType valueOf(int value){
            return fanTypes.get(value);
        }
    }

    private String currentSpeed; //String represention of current fan speed
    private int currentTypeIndex; //int representing the index of current fan speed

    public Fan(){
        this.currentSpeed = FanSpeedType.Off.toString(); //default fan state
        this.currentTypeIndex = FanSpeedType.Off.getfanTypeIndex();
    }

    /**
     * Method to increase the fan speed
     */
    public void increaseSpeed(){
        if(currentTypeIndex >= 1 && currentTypeIndex < 4){
            this.currentTypeIndex++;
        }
        this.currentSpeed = FanSpeedType.valueOf(this.currentTypeIndex).toString();
    }
    
    /**
     * Method to decrease fan speed
     */
    public void decreaseSpeed(){
        if(currentTypeIndex > 1 && currentTypeIndex <= 4){
            this.currentTypeIndex--;
        }
        this.currentSpeed = FanSpeedType.valueOf(this.currentTypeIndex).toString();
    }

    /**
     * Method that returns the string representation of current fan speed
     */
    @Override
    public String toString() {
        return  ("Fan Speed: " + currentSpeed);
    }

}
