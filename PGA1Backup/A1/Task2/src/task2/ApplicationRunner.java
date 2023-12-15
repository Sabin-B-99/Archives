package task2;

import java.io.File;

/**
 * Class that contains the main program which starts the main game loop 
 */
public class ApplicationRunner {

 
    public static void main(String[] args) {
        String dataFile = System.getProperty("user.dir") + File.separator + "wordlist.txt"; //txt file that contains all the game words
        

        GameManager gm = new GameManager(dataFile);
        
        /* *** Do not delete the commented lines below. Uncomment them to toggle the cheat on *** */ 
        //boolean displayCodeWord = true;
        //gm.isCheatOn(displayCodeWord);
        
        gm.start();
    }

}
