package task1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * Class that reads all the lines of the .txt Script file and anlayzes the frequency of different 
 * types of characters present in that .txt Script file
 */
public class ScriptReader {
    private String fileDir; //Script file directory
    private Scanner fileScanner; //Scanner that will read through the .txt script file

    int noOfUpperCaseLetters; //total number of upper case letters in the .txt script file
    int noOfLowerCaseLetters; //total number of lower case letters in the .txt script file

    public ScriptReader(String fileDir){
        this.fileDir = fileDir;
        noOfUpperCaseLetters = 0;
        noOfLowerCaseLetters = 0;
    }

    /**
     * Method that opens the .txt script file, reads each line of that file and counts 
     * the total frequencty of different type of characters present in that .txt file
     */
    public void openFileAndAnalyzeData(){
        try{
            fileScanner = new Scanner(new BufferedReader(new FileReader(fileDir)));
            analyzeData(fileScanner);

        }catch(IOException e){
            System.err.println("Script file not found on disk.");
        }finally{
            if(fileScanner != null){
                fileScanner.close();
            }
        }
    }

    /**
     * Method that actually goes through each line of the .txt file and counts the 
     * total number of uppercase, lowecase as well as frequency of different types 
     * of characters present in that script file. Along with counting the frequency 
     * this method sorts and displays all the result on the console
     * 
     * @param Scanner that reads each line of the .txt scriptfile
     */
    private void analyzeData(Scanner dataFile){
        String scriptLine;
        TreeMap<Character, Integer> freqTable = new TreeMap<>();
        initialzieTable(freqTable);
        while(dataFile.hasNextLine()){
            scriptLine = dataFile.nextLine();
            countUpperAndLowerCase(scriptLine);
            countCharacterFreq(scriptLine.toCharArray(), freqTable);
        }
        System.out.println("Total number of uppercase letters = " + this.noOfUpperCaseLetters);
        System.out.println("Total number of lowercase letters = " + this.noOfLowerCaseLetters);


        ArrayList<CharAndFreq> charFreqList = listOfCharAndFreqs(freqTable);
        Collections.sort(charFreqList);
        Collections.reverse(charFreqList);
        printFreqList(charFreqList);
    }

    /**
     * Method that counts the total number of upper case and lower case letters in
     * a line of String
     * @param a String in which the total number of upper case and lower case characters is to be counted
     */
    private void countUpperAndLowerCase(String line){
        for (char c : line.toCharArray()) {
            if(Character.isUpperCase(c)){
                this.noOfUpperCaseLetters++;
            }

            if(Character.isLowerCase(c)){
                this.noOfLowerCaseLetters++;
            }
        }
    }

    /**
     * Method that counts the frequency of each characters present in a given array of characters
     * @param scriptLineCharArr an array of characters from which the frequency of each characters will be counted
     * @param charFreqTable a TreeMap that acts as a frequency table for all the uppercase and lowecase characters of english alphabet
     */
    private void countCharacterFreq(char[] scriptLineCharArr, TreeMap<Character, Integer> charFreqTable){
        Character currentCharacter;
        Integer currentCharacterFreq;
        for (char c : scriptLineCharArr) {
            currentCharacter = Character.valueOf(c);
            currentCharacterFreq = charFreqTable.get(currentCharacter);
           
            if(currentCharacterFreq != null){
                charFreqTable.put(currentCharacter, (currentCharacterFreq + 1));   
            }
        }
    }

    /**
     * Method that initializes a TreeMap that acts as a frequency table for all the uppercase and 
     * lowecase characters of english alphabet
     * @param tableOfFreq a TreeMap that acts as a frequency table for all the uppercase and lowecase characters of english alphabet
     */
    private void initialzieTable(TreeMap<Character, Integer> tableOfFreq){
        for(Character c = 'a'; c <= 'z';  c++){
            tableOfFreq.put(c, 0);
        }
        
        for(Character c = 'A'; c <= 'Z';  c++){
            tableOfFreq.put(c, 0);
        }
    }

    /**
     * Method that prints the frequency table i.e, frequency of all the charactes in the script file to the console
     * @param charFreqTable an ArrayList acting as a frequency table of CharAndFreq (which is a type that condenses a Charatcter and its corresponding Integer(frequency) into a single type)
     */
    private void printFreqList(ArrayList<CharAndFreq> charFreqTable){
        for (CharAndFreq o : charFreqTable) {
            System.out.println(o.getType() + " --> " + o.getFrequency());
        }
    }

    /**
     * Method that maps the Treemap of Character and Integer acting as a frequency table to an ArrayList of 
     * CharAndFreq, which is a type that condeses a Charatcer and its corresponding Integer(frequency) into 
     * a single type
     * @param charFreqTable a TreeMap that acts as a frequency table for all the uppercase and lowecase characters of english alphabet
     * @return an ArrayList acting as a frequency table of CharAndFreq (which is a type that condneses a Charatcter and its corresponding Integer(frequency) into a single type)
     */
    private ArrayList<CharAndFreq> listOfCharAndFreqs(TreeMap<Character, Integer> charFreqTable){
        ArrayList<CharAndFreq> listOfCharFreq = new ArrayList<CharAndFreq>();
        for (Character c : charFreqTable.keySet()) {
            listOfCharFreq.add(new CharAndFreq(c, charFreqTable.get(c)));
        }
        return (new ArrayList<CharAndFreq>(listOfCharFreq));
    }
}