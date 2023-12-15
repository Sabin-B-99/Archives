package task3;

/**
 * Class that extends the Menu class so that it can create a suitable menu that works properly only when
 * used to increase and decrease the values of different traing targets of the TrainingGola from the 
 * Manual Programme Menu. In other words this class can be used to create the sub-menu for the Manual 
 * Programme Menu
 */
public class TrainingGoalsMenu extends Menu{
    
    public TrainingGoalsMenu(String menuTitle) {
        super(menuTitle); 
    }

    /**
     * Method that add the three option that can either increase/decrease the selected training traget
     * (target distance,time, resistance level) or go back to the parent menu(usually Manual Programme menu) 
     */
    public void createTrainingGoalsMenu(){
        addOption("Increase");
        addOption("Decrease");
        addOption("GO BACK");
    }

    /**
     * Method that displays the options of this menu
     * @return  an integer representing one of the options of this menu which has been selected by the user.
     */
    public int displayGoalMenuAnGetUserChoice(){
        return displayMenuAndGetUserChoice();
    }
}
