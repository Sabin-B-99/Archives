package task3;

/**
 * Utility class that creates all different types of menus (ex: main-menu, fan speed increase menu
 * , Manual prgramme menu, Preset Programmes menu .etc.). The class also displays all these menu 
 * while processing all the menu choices/inputs from the user. In short this class controls all the 
 * menu interactions of the program. Moreover, since it is a singelton class it cannot be further
 * inherited by other classes. Hence, it is a final class. 
 */
public final class ProgramManager {
    private static Menu mainMenu = new Menu("Home Menu"); //main-menu of the program 
    private static Menu fanSpeedMenu = new Menu("Fan Speed Menu"); //menu to increase and decrease fan speed
    private static Menu bpmMenu = new Menu("Heart Sensors Menu"); //menu to display heart rate

    private static Menu manualProgramme = new Menu("Manual Programme Menu"); //Manual Programme Menu
    private static TrainingGoalsMenu targetDistance = new TrainingGoalsMenu("Targe Distance Menu"); //sub-menu of manual program menu to control target distance
    private static TrainingGoalsMenu targetTime = new TrainingGoalsMenu("Target Time"); //sub-menu of manual program menu to control target time
    private static TrainingGoalsMenu ressistanceLev = new TrainingGoalsMenu("Resistance Level Menu"); //sub-menu of manual program menu to control ressistance level

    private static Menu presetMenu = new Menu("Preset Programme Menu"); //Preset program menu
    private static PresetsProg preset = new PresetsProg(); //Instance of class that conrols all types of presets in the program
    private static Menu presetConfirmationMenu = new Menu("Confirm Preset?"); //menu that asks user for confirmation of selection of a certain preset



    private static TrainingGoals currentTrainingGoals = new TrainingGoals(); //Training goals inculdes target distance, target time and target resistance
    private static Fan currentSpeed = new Fan(); //Fan speeds inculdes off,slow,medium,fast
    private static BPM heartSensors = new BPM(); //BPM instance to check and display users' current heart rate

    public static boolean isCrossTrainerOff = false; // boolean variable to check wether the program/cross-trainer is closed or not

    //private constructor so that no class can have an instance of this singelton class
    private ProgramManager(){
    }

    /**
     * Static Method that initializes all the different types of menu listed above with respective options for each
     * menu types. 
     */
    public static void initializeAllMenu(){
        createMainMenu();
        createFanMenu();
        createBPMMenu();
        createManualProgramMenu();
        targetDistance.createTrainingGoalsMenu();
        targetTime.createTrainingGoalsMenu();
        ressistanceLev.createTrainingGoalsMenu();
        createPresetProgramMenu();
        createPreasetConfirmMenu();
    }

    /**
     * Static Method that adds all the options that needs to be in the main-menu/Home menu of the 
     * cross-trainer machine.
     */
    private static void createMainMenu(){
        mainMenu.addOption("Fan Speed");
        mainMenu.addOption("BPM");
        mainMenu.addOption("Preset Programmes");
        mainMenu.addOption("Manual Programme");
        mainMenu.addOption("Reset to defaults");
        mainMenu.addOption("Turn off Cross-Trainer");
    }

    /**
     * Static Method that adds all the options that needs to be in the Fan Speed menu of the 
     * cross-trainer machine. This is the menu where the user can increase and decrease fan 
     * speeds.
     */
    private static void createFanMenu(){
        fanSpeedMenu.addOption("Increase Fan Speed");
        fanSpeedMenu.addOption("Decrease Fan Speed");
        fanSpeedMenu.addOption("HOME");
    }

    /**
     * Static Method that adds all the options that needs to be in the BPM menu of the 
     * cross-trainer machine. This is the menu where user can see his/her heart rate and 
     * opt to return to home menu after doing so.
     */
    private static void createBPMMenu(){
        bpmMenu.addOption("Home");
    }

    /**
     * Static Method that adds all the options that needs to be in the Manual Programmer menu of the 
     * cross-trainer machine. This is the menu where user can set (increase/decrease) target distance,
     * target time and restsiance level.
     */
    private static void createManualProgramMenu(){
        manualProgramme.addOption("Set Target Distance");
        manualProgramme.addOption("Set Time Goal");
        manualProgramme.addOption("Set Resistance Level");
        manualProgramme.addOption("HOME");
    }

    /**
     * Static Method that adds all the options that needs to be in the Preset Programmes menu of the 
     * cross-trainer machine. This is the menu where user can view and select one among different preset training 
     * programmes. 
     */
    private static void createPresetProgramMenu(){
        presetMenu.addOption("See Next Preset");
        presetMenu.addOption("See Last Preset");
        presetMenu.addOption("HOME");
    }

    /**
     * Static method that adds the yes/no conformations options. So that once a user views a preset training 
     * program, he/she can opt to choose that program for training. 
     */
    private static void createPreasetConfirmMenu(){
        presetConfirmationMenu.addOption("Yes");
        presetConfirmationMenu.addOption("No");
    }

    /**
     * Static Method that displays the main/menu/home menu of the cross-trainers and asks the user to select
     * one of the option of the main-menu.
     * @return an integer index of the the option that the user chooses from the main-menu
     */
    public static int displayMainMenuAndGetUserChoice(){

        System.out.println("\n\n*************************** XYZ Cross-Trainer 2.0 **************************");
        System.out.println("                           Default Training Values                          ");
        System.out.println("****************************************************************************");
        System.out.println(currentTrainingGoals.toString());
        System.out.println(currentSpeed.toString());
        System.out.println("****************************************************************************");
        return mainMenu.displayMenuAndGetUserChoice();
    }

    /**
     * Static Method that displays the Fan Speed Menu in which user can increase or decresae the fan speed.
     * @return an Integer index of the option that user chooses from the option of the fan speed menu
     */
    private static int displayFanMenuAndGetUserChoice(){
        return fanSpeedMenu.displayMenuAndGetUserChoice();
    }

    /**
     * Static Method that displays the BPM Menu in which user can see his/her heart rate.
     * @return an Integer index of the option that user chooses from the option of the BPM menu
     */
    private static int displayBPMMenuAndGetUserChoice(){
        return bpmMenu.displayMenuAndGetUserChoice();
    }

    /**
     * Static Method that displays the Manual Programme Menu in which user can increase/decrease 
     * different training goals like target distance, target time and target resistance
     * @return an Integer index of the option that user chooses from the option of the Manual Programme menu
     */
    private static int displayManualGoalsMenuAndGetChoice(){
        return manualProgramme.displayMenuAndGetUserChoice();
    }

    /**
     * Static method that displays a menu form which user can increase and decrease the target distance.
     * @return an Integer index of the option that user chooses from the option of the menu
     */
    private static int displayDistanceTargetMenuAndGetChoice(){
        return targetDistance.displayGoalMenuAnGetUserChoice();
    }

    /**
     * Static method that displays a menu form which user can increase and decrease the target time.
     * @return an Integer index of the option that user chooses from the option of the menu
     */
    private static int displayTimeTargetMenuAndGetChoice(){
        return targetTime.displayGoalMenuAnGetUserChoice();
    }

    /**
     * Static method that displays a menu form which user can increase and decrease the target resistance.
     * @return an Integer index of the option that user chooses from the option of the menu
     */
    private static int displayResistanceTargetMenuAndGetChoice(){
        return ressistanceLev.displayGoalMenuAnGetUserChoice();
    }

    /**
     * Static Method that displays the preset programmes menu in which user can select one preset among 
     * differet training program presets.
     * @return an Integer index of the option that user chooses from the option of the menu
     */
    private static int displayPresetMenuAndGetChoice(){
        return presetMenu.displayMenuAndGetUserChoice();
    }

    /**
     * Static Method that displays the confimation menu of the preset programme selection.
     * @return an Integer index of the option that user chooses from the option of the menu
     */
    private static int displayPresetConfirmMenuAndGetChoice(){
        return presetConfirmationMenu.displayMenuAndGetUserChoice();
    }

    /**
     * Static Method that controls the program flow once the user selects a certain option from the main-menu.
     * This method redirects the program to the next appropiriate menu/decision control that needs to be taken 
     * depending upon the option user selects from the main-menu.  
     * @param userChoice an integer representing option that the user selects form the main-menu
     */
    public static void processMainMenuChoice(int userChoice){
        switch(userChoice){
            case 1:
                processFanMenuIncreaseDecreaseOptions();
                break;
            case 2:
                heartSensors.checkCurrentBPM();
                processBPMMenuChoice(displayBPMMenuAndGetUserChoice());
                break;
            case 3:
                //displaying initial preset type
                System.out.println("\n***************************** Current Preset ********************************");
                System.out.println("Preset Type: " + preset.getPresetType());
                System.out.println(preset.getCurrentPresetGoal().toString());
                processPresetMenuChoice(displayPresetMenuAndGetChoice());
                break;
            case 4:
                processManualMenuChoice(displayManualGoalsMenuAndGetChoice());
                break;
            case 5:
                System.out.println("Resetting to default settings...");
                System.out.println("Resetting Complete!");
                currentTrainingGoals = new TrainingGoals();
                currentSpeed = new Fan();
                break;
            case 6:
                System.out.println("Thank you for trusting our Cross-Trainer");
                isCrossTrainerOff = true;
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Main Menu");
                break;
        }
    }

    /**
     * Static Method that controls the program flow once the user selects an option form the Fan-speed
     * menu
     */
    private static void processFanMenuIncreaseDecreaseOptions(){
        int increaseDecreaseFanSpeedChoice;
        while(true){
            increaseDecreaseFanSpeedChoice = displayFanMenuAndGetUserChoice();
            if(increaseDecreaseFanSpeedChoice == 3){
                System.out.println("Loading... Main Menu...");
                break;
            }
            processFanSpeedMenuChoice(increaseDecreaseFanSpeedChoice);
        }
    }

    /**
     * Static method that helps processFanMenuIncreaseDecreaseOptions() method to actually increase and decrease the 
     * fan speed depending upon the option that the user chooses from that method(Fan-speed menu). 
     * @param choice an integer representing option (increase/decrease/home) that the user selects from the fan-speed menu
     */
    private static void processFanSpeedMenuChoice(int choice){
        System.out.println("****************************************************************************");
        switch(choice){
            case 1:
                currentSpeed.increaseSpeed();
                System.out.println("Fan Speed Increased...");
                System.out.println(currentSpeed.toString());
                break;
            case 2:
                currentSpeed.decreaseSpeed();
                System.out.println("Fan Speed Decreased... ");
                System.out.println(currentSpeed.toString());
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Fan Speed Selection");
                break;
        }
    }

    /**
     * This method controls the program flow once the user is in BPM menu and selects an option inside of that menu
     * @param choice an integer representing option that the user selects from the BPM menu
     */
    private static void processBPMMenuChoice(int choice){
        switch(choice){
            case 1:
                System.out.println("Loading... Main Menu...");
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at BPM Menu");
                break;
        }
    }

    /**
     * Static method that controls the flow of the once the user selects an oprion form within the 
     * manual programmes menu.
     * @param choice an integer representing option that the user selects from the Manual Programmme menu
     */
    private static void processManualMenuChoice(int choice){
        int trainingGoalIncreaseDecrease = 0;
        while(true){

            if(choice == 4 || trainingGoalIncreaseDecrease == 3){
                System.out.println("Loading... Main Menu...");
                break;
            }

            switch(choice){
                case 1:
                    trainingGoalIncreaseDecrease = displayDistanceTargetMenuAndGetChoice();
                    processDistanceGoalMenuChoice(trainingGoalIncreaseDecrease);
                    break;
                case 2:
                    trainingGoalIncreaseDecrease = displayTimeTargetMenuAndGetChoice();
                    processTimeGoalMenuChoice(trainingGoalIncreaseDecrease);
                    break;
                case 3:
                    trainingGoalIncreaseDecrease = displayResistanceTargetMenuAndGetChoice();
                    processResistanceGoalMenuChoice(trainingGoalIncreaseDecrease);
                    break;
                default:
                    System.err.println("Unexpected Error: Reporting error at Target Resistance Menu");
                    break;
            }
        }
    }

    /**
     * Method that increases/decreases the target distance depending upon the option user chooses form the 
     * sub-menu of manual program menu that asks user to increase/decrease the target distance.
     * @param choice an integer representing option that the user selects from the sub-menu of Manual Programmme menu which increases/decreases the target distance 
     */
    private static void processDistanceGoalMenuChoice(int choice){
        switch(choice){
            case 1:
                currentTrainingGoals.increaseDistance();
                System.out.println("Training Distance Increased to: " + currentTrainingGoals.getTargetDistance());
                break;
            case 2:
                currentTrainingGoals.decreaseDistance();
                System.err.println("Training Distance Decreased to: " + currentTrainingGoals.getTargetDistance());
                break;
            case 3:
                processManualMenuChoice(displayManualGoalsMenuAndGetChoice());
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Target Distance Menu");
                break;
        }
    }

    /**
     * Method that increases/decreases the target time depending upon the option user chooses form the 
     * sub-menu of manual program menu that asks user to increase/decrease the target time.
     * @param choice an integer representing option that the user selects from the sub-menu of Manual Programmme menu which increases/decreases the target time 
     */
    private static void processTimeGoalMenuChoice(int choice){
        switch(choice){
            case 1:
                currentTrainingGoals.increaseTime();
                System.out.println("Training Time Increased to: " + currentTrainingGoals.getTargetTime());
                break;
            case 2:
                currentTrainingGoals.decreaseTime();
                System.err.println("Training Time Decreased to: " + currentTrainingGoals.getTargetTime());
                break;
            case 3:
                processManualMenuChoice(displayManualGoalsMenuAndGetChoice());
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Target Time Menu");
                break;
        }
    }

    /**
     * Method that increases/decreases the target resistance depending upon the option user chooses form the 
     * sub-menu of manual program menu that asks user to increase/decrease the target resistance.
     * @param choice an integer representing option that the user selects from the sub-menu of Manual Programmme menu which increases/decreases the target resistance 
     */
    private static void processResistanceGoalMenuChoice(int choice){
        switch(choice){
            case 1:
                currentTrainingGoals.increaseResistanceLevel();;
                System.out.println("Training Resistance Increased to: " + currentTrainingGoals.getTargetResistance());
                break;
            case 2:
                currentTrainingGoals.decreaseResistanceLevel();
                System.err.println("Training Resistance Decreased to: " + currentTrainingGoals.getTargetResistance());
                break;
            case 3:
                processManualMenuChoice(displayManualGoalsMenuAndGetChoice());
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Target Resistance Menu");
                break;
        }
    }

    /**
     * Static Method that controls the flow of program depending upon the option that the user chooses inside of the 
     * Preset Menu.
     * @param choice an integer representing option that the user selects from the Preset Programmes menu
     */
    private static void processPresetMenuChoice(int choice){
        switch(choice){
            case 1:
                preset.seePreset(choice);
                processPresetConfirmMenu(displayPresetConfirmMenuAndGetChoice());
                break;
            case 2:
                preset.seePreset(choice);
                processPresetConfirmMenu(displayPresetConfirmMenuAndGetChoice());
                break;
            case 3:
                System.out.println("Loading... Main Menu...");
                processMainMenuChoice(displayMainMenuAndGetUserChoice());
                break;
            default:
                System.err.println("Unexpected Error: Reporting error at Preset Cycle Menu");
                break;
        }
    }

    /**
     * Static Method that controls the program flow once the user selects an option from the preset selection 
     * confirmation sub-menu inside of the preset programme menu
     * @param choice an integer representing option that the user selects from the Preset Programme confirmation sub-menu inside of the preset programmes menu.
     */
    private static void processPresetConfirmMenu(int choice){
        switch(choice){
            case 1:
                currentTrainingGoals = new TrainingGoals(preset.getCurrentPresetGoal());
                System.out.println("****** New Preset Selected ******");
                System.out.println(preset.getPresetType());
                System.err.println(currentTrainingGoals.toString());
                break;
            case 2:
                processPresetMenuChoice(displayPresetMenuAndGetChoice());
                break;
            case 3:
                System.err.println("Unexpected Error: Reporting error at Preset Confrimation Menu");
                break;
        }
    }
}
