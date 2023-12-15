package task3;

/**
 * Class that contains information regarding the training goals of the user. With the help of 
 * this class the machine tracks the users' training golas which includes: traget distance, taget time,
 * and target resistance level.
 */
public class TrainingGoals {
    private int targetDistance; //users' target distance for training
    private int targetTime; //users' target time for training
    private int resistanceLevel; //users' target resistance level for training

    /**
     * Constructor that creates the instacnce of this class with default values of 
     * 500 meters, 40 minutes and 5 for traget distance, target time and target 
     * resistance level respectively
     */
    public TrainingGoals(){
        this.targetDistance = 500;
        this.targetTime = 40;
        this.resistanceLevel = 5;
    }

    /**
     * Parameterized constructor that creates instacne of this class with the user defined values for
     * target distance, target time and target resistance level
     * @param targetDistance an integer representing target distance
     * @param targetTime an integer representing target distance
     * @param resistanceLevel an integer representing target resistance level
     */
    public TrainingGoals(int targetDistance, int targetTime, int resistanceLevel){
        this.targetDistance = targetDistance;
        this.targetTime = targetTime;
        this.resistanceLevel = resistanceLevel;
    }
  
    /**
     * Parameterized constructor that creates an instance of this class using already existing
     * instance, copying all the values of all fields from already existing instance
     * @param rhs already existing instacne of TraingGoals to be copied
     */
    public TrainingGoals(TrainingGoals rhs){
        this.targetDistance = rhs.targetDistance;
        this.targetTime = rhs.targetTime;
        this.resistanceLevel = rhs.resistanceLevel;
    }

    /**
     * Method to increase the target distance by 500 meters. Maximum target distance 
     * can be 10000 meters
     */
    public void increaseDistance(){
        if(this.targetDistance >= 0 && this.targetDistance < 10000){
            this.targetDistance += 500;
        }
    }

    /**
     * Method to decrease the target distance by 500 meters. Minimum target distance 
     * can be 10000 meters
     */
    public void decreaseDistance(){
        if(this.targetDistance > 500 && this.targetDistance <= 10000){
            this.targetDistance -= 500;
        }
    }

    /**
     * Method to increase the target time by 1 minutes. Maximum target time 
     * can be 60 minutes
     */
    public void increaseTime(){
        if(this.targetTime >= 0 && this.targetTime < 60){
            this.targetTime += 1;
        }
    }

    /**
     * Method to decrease the target time by 1 minutes. Minimum target time 
     * can be 0 minutes
     */
    public void decreaseTime(){
        if(this.targetTime > 1 && this.targetTime <= 59){
            this.targetTime -= 1;
        }
    }

    /**
     * Method to increase the target resistance level by 1 unit. Maximum target resistance level 
     * can be 30 units
     */
    public void increaseResistanceLevel(){
        if(this.resistanceLevel >= 1 && this.resistanceLevel < 30){
            this.resistanceLevel += 1;
        }
    }

    /**
     * Method to decrease the target resistance level by 1 unit. Minimum target resistance level 
     * can be 1 units
     */
    public void decreaseResistanceLevel(){
        if(this.resistanceLevel > 2 && this.resistanceLevel <= 30){
            this.resistanceLevel -= 1;
        }
    }

    /**
     * Method that returns current target distance of current training goal
     * @return an integer representing current target distance
     */
    public int getTargetDistance(){
        return this.targetDistance;
    }

    /**
     * Method that returns current target time of current training goal
     * @return an integer representing current target time
     */
    public int getTargetTime(){
        return this.targetTime;
    }

    /**
     * Method that returns current target resistance level of current training goal
     * @return an integer representing current target resistance level
     */
    public int getTargetResistance(){
        return this.resistanceLevel;
    }

    /**
     * Method that returns the string instacne of the current class. This string contains
     * all the information of the training target distance, taget time and target resistance level.
     * This method overrides the default toString() method
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Target Distance: " + this.targetDistance + " meters.\n");
        builder.append("Time Goal: " + this.targetTime + " minutes.\n");
        builder.append("Resistance Level: " + this.resistanceLevel);
        return builder.toString();
    }
}
