package task1;

import java.io.File;

/**
 * Class contains the main program thrugh which the .txt script file is read, analyzed
 * and related information are printed out to the console.
 */
public class ApplicationRunner {

    public static void main(String[] args) {
        
        String dataFile = System.getProperty("user.dir") + File.separator + "film-script.txt";
        ScriptReader fileReader = new ScriptReader(dataFile);
        fileReader.openFileAndAnalyzeData();
	}

}
