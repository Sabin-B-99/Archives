
package task3;

/**
 * Class that contains the main program and the Cross-Trainer's program loop
 */
public class ApplicationRunner {
    
    public static void main(String[] args) {

       ProgramManager.initializeAllMenu();
       int userChoice;

       //Cross-Trainer's program loop
       while(!ProgramManager.isCrossTrainerOff){
           userChoice = ProgramManager.displayMainMenuAndGetUserChoice();
           ProgramManager.processMainMenuChoice(userChoice);
       }
    }  
}
