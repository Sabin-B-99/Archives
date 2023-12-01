package task3;

/**
 * Class that represents the heart sensors that checks users' current heart rate
 */
public class BPM {
    private int currentHeartRate; //users' current heart rate

    /**
     * Constructor that consturcts current instance of BPM with a default static heart rate of
     * 70
     */
    public BPM(){
        this.currentHeartRate = 70;
    }

    /**
     * Method that displays current heart rate to the console
     */
    public void checkCurrentBPM(){
        System.out.println("\n****************************** Checking BPM ********************************");
        System.out.println("Adjusting Machine Sensors...");
        System.out.println("Checking your current heart rate...\n");
        System.out.println("Your current heart rate is: " + this.currentHeartRate + " BPM");
    }

    /**
     * Setter method that sets the users' current heart rate with the new value provided as parameter
     * @param currentHeartRate a new value that is to be used/set as users' current heart rate
     */
    public void setCurrentHeartRate(int currentHeartRate){
        this.currentHeartRate = currentHeartRate;
    }
}
