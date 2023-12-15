package task2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Class that reads all the game words form the provided txt file
 */
public class ReadData {

    private String fileName; //txt file name from which the words are to be read
    private Scanner fileReader;// scanner that will read each line of the txt file to read the game words

    public ReadData(String fileName){
        this.fileName = fileName;
    }

    /**
     * Method that reads all the game words from the given txt file
     * @return an ArrayList containing all the game words that has been read form the txt file
     */
    public ArrayList<String> readDataFile(){
       ArrayList<String> wordList = new ArrayList<>();
       try{
            fileReader = new Scanner(new BufferedReader(new FileReader(fileName)));
            readAllWords(fileReader, wordList);
        }catch(IOException e){
            System.out.println("File not found on disk");
        }finally{
            if(fileReader != null){
                fileReader.close();
            }
        }

        return (new ArrayList<>(wordList));
    }


    /**
     * Method that actually reads all the words from the txt file into a ArrayList in temporaru Memory
     * @param fileReader Sacnner that will be used to read through the file
     * @param wordList list of all the words that has been read from the txtfile
     */
    private void readAllWords(Scanner fileReader, ArrayList<String> wordList){
        String word;
        while(fileReader.hasNextLine()){
            word = fileReader.nextLine();
            wordList.add(word);
        }
    }

}