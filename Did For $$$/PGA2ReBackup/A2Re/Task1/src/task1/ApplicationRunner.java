package task1;


import java.io.File;
import java.util.ArrayList;

/**
 * Class which contains the main method of the program and the main program loop
 */
public class ApplicationRunner {
    
    public static void main(String[] args) {
        
        String dataFile = System.getProperty("user.dir") + File.separator + "bond-movies.txt";
        DataReader rdr = new DataReader(dataFile);
        ArrayList<BondMovie> moviesData = rdr.readDataIntoList();
        ProgramManager.initializeProgramData(moviesData);

        int userChoice;
        //main program loop
        while(true){
            ProgramManager.displayMainMenu();
            userChoice = ProgramManager.getMainMenuChoice();
            ProgramManager.processMainMenuChoices(userChoice);

            if(userChoice == 0){
                break;
            }
        }
    }
    
}
