package task2;

import java.util.ArrayList;


/**
 * Class that contains the main method and main program loop which runs the program 
 */
public class ApplicationRunner {
    
    public static void main(String[] args) {
        ArrayList<Gym> applicationData = new ArrayList<>();
        ApplicationData.initializeData(applicationData);
        ApplicationManager.initializeProgramData(applicationData);

        //Uncomment all lines below to find all information about program in the gym
        // for (Gym gym : applicationData) {
        //     System.out.println("Gym Name: " + gym.getName());
        //     System.out.println("*************************** Members ************************");
        //     for (Member member : gym.getGymMembers()) {
        //         System.out.println("Name: " + member.getName() + ", Number: " + member.getNumber() + ", Personal Trainer: " + member.getPersonalTrainer().getName());
        //     }
        //     System.out.println("*************************** Trainer ************************");
        //     for (Trainer trainer : gym.getGymTrainers()) {
        //         System.out.println("Name: " + trainer.getName());
        //         for (TrainingSession trainingSession : trainer.getTrainingSessions()) {
        //             System.out.println("Date: " + trainingSession.getDate().toString()+ " ,Session start time: " + trainingSession.getStartTime().toString());
        //         }
        //     }
        //     System.out.println("********************* Class Sessions ************************");
        //     TreeMap<String, ClassSession> gymClassSessions = gym.getClassSessions();
        //     for (String session : gymClassSessions.keySet()) {
        //         System.out.println("Session Name: " + gymClassSessions.get(session).getName() + " , Date: " +gymClassSessions.get(session).getDate().toString()+ " ,Session start time: " + gymClassSessions.get(session).getStartTime().toString());
        //     }
        // }

        int userChoice;

        //main program loop
        while(true){
            ApplicationManager.displayMainMenu();
            userChoice = ApplicationManager.getMainMenuChoice();
            ApplicationManager.processMainMenuChoices(userChoice);

            if(userChoice == 0){
                break;
            }
        }
    }
    
}
