package task2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

/**
 * Class that controls the game control flow, user guesses and game data as well as
 * displays all necessary information on the console.
 */
public class GameManager {
    private ReadData dataFile; //ReadData instance that reads all the words from the txt file
    private boolean cheatOn; //boolean representing whether the cheat is on or not
    private ArrayList<String> gameWords; //list of all the words that has been read from the txt file
    private Scanner userInput; //scanner that reads user word guesses form keyboard 
    private ArrayList<String> guessedWords; //list of all the words the user has already guessed.
    
    /**
     * list of hits(number of charaters matching between the guessed word and secret word) for each guessed words.
     * The guessed words in guessedWords ArrayList and hits in guessWordHits correspond/related by thier index.
     */
    private ArrayList<Integer> guessedWordsHits; 

    private int numberOfGuess; //total number of guesses user has made
    private boolean isGameOver; //boolean representing whether game is over or not
    

    /**
     * Constructor that initializes all the necesssary fields that is required before starting the guessing game. 
     * @param gameDataFile a string representing the name of txt file containing all the game words
     */
    public GameManager(String gameDataFile){
        this.dataFile = new ReadData(gameDataFile);
        this.cheatOn = false;
        this.userInput = new Scanner(System.in);
        this.numberOfGuess = 0;
        this.isGameOver = false;
    }

    /**
     * Method that contains the main program loop. The method also checks whether the user wants
     * to play again if the game is over. This method loads all the words form the txt file into 
     * an arraylist as well as get a random word form that list. This random is used as a secret 
     * word that is to be guessed by the users
     */
    public void start(){
        this.gameWords = loadGameWords();
        this.guessedWords = new ArrayList<>();
        this.guessedWordsHits = new ArrayList<>();
        
        int userMenuChoice = displayMainMenuAndGetChoice();
        String secretWord = randomWord(this.gameWords);

        while(!isGameOver){
            processMenuChoice(userMenuChoice,secretWord);
            
            if(isGameOver){
                userMenuChoice = promptToPlayAgainAfterGameOver();
                secretWord =  randomWord(this.gameWords); //new secret word if user decides to play again
            }

            if(userMenuChoice == 0){
                break;
            }
        }
        userInput.close();
    }

    /**
     * Method that prompts the user to play the game again if the game is over.
     * @return an integer representing user choice to play again(1)  or not(0)
     */
    private int promptToPlayAgainAfterGameOver(){
        int userMenuChoice = displayMainMenuAndGetChoice();
        if(userMenuChoice == 1){
            this.isGameOver = false;
            this.guessedWords.clear();
        }else{
            System.out.println("\nThank you!!! for playing the game. Have a nice day :)");
            this.isGameOver = true;
        }
        return userMenuChoice;
    }

    /**
     * Method that controls the flow of game depending upon the depending upon the choice made 
     * by the user in main menu. This method will end the program if user opts to exit the 
     * game in main-menu. But if the user opts to play the game, this is the method where all 
     * the vital gameplay features like asking users' guess words, adding them to guessed words
     * list, checking the number of hits between the guessed words and secret word as well as displying
     * other game inforamtion takes place. 
     * @param userMenuChoice an integer representing the option that the user selects from the mainmenu
     * @param secretWord an string representing the secret word that is to be guessed by the user
     */
    private void processMenuChoice(int userMenuChoice, String secretWord){
       
        if(userMenuChoice == 1){
            String userGuess;
            int hits;
            
            if(this.cheatOn == true){
                System.out.println("\nSecret Word: " + secretWord);
            }
    
            userGuess = getUserGuessWord();

            if(!userGuess.equals("*")){
                hits = checkHits(userGuess, secretWord);
                System.out.println();
                System.out.println("\nThere are " +  hits + " matching letters in your guess (" + userGuess + ")");
                System.out.println();

                addToGuessedList(userGuess, hits);
                printGuessedWords();
                this.numberOfGuess++;
                System.out.println("\nNumber of guesses so far: " + this.numberOfGuess);
                
                if(userGuess.equals(secretWord)){
                    System.out.println("\nYAY! you guessed the word("+ userGuess +") correctly.");
                    this.isGameOver = true;
                    this.numberOfGuess = 0;
                }

                if(hits == 5){
                    System.out.println("All charcters match. Try changing the order of characters to find the correct words.");
                }
            }

            if(this.numberOfGuess > 9 || userGuess.equals("*")){
                System.out.println("\nSecret word is: " + secretWord);
                this.isGameOver = true;
                this.numberOfGuess = 0;
            }

        }else if(userMenuChoice == 0){
            System.out.println("\nThank you!!! for playing the game. Have a nice day :)");
        }else{
            System.err.println("\nSomething went wrong! Reporting error: At menu choice selection.");
        }
    }

    /**
     * Method that loads all the words from the txt file and puts those words in an Arraylist
     * @return an ArrayList containing all the game words
     */
    private ArrayList<String> loadGameWords(){
        return (new ArrayList<String>(this.dataFile.readDataFile()));
    }


    /**
     * Method that displays Main menu of the game and returns one of the option the user chooses from the main-menu 
     * @return an integer representing the users' main menu option choice
     */
    private int displayMainMenuAndGetChoice(){
        System.out.println("Word Guessing Game");
        System.out.println();
        if(!isGameOver){
            System.out.print("Play (1) or Exit (0) > ");
        }else{
            System.out.print("Play Again (1) or Exit (0) > ");
        }
        return getUserChoice();

    }

    /**
     * Method that asks user to input, in the console, a main-menu choice from the keyboard. This input should be a number.
     * If the user inputs a character then the program will select the default option i.e, the first option of the menu
     * @return an integer representing the users' option choice
     */
    private int getUserChoice(){
        int userMenuChoice = 1;
        
        try{
            while(true){
                userMenuChoice = userInput.nextInt();
                if(userMenuChoice >= 0 && userMenuChoice <= 1){
                    break;
                }else{
                    System.out.println("Please enter a valid choice.");
                    System.out.println("Play (1) or Exit (0)");
                }
            }
        }catch(InputMismatchException e){
            System.err.println("Input Mismatch: Enter either 1 or 0 form your keyboard.");
            System.out.println("Default option: Play(1) selected.");
        }

        userInput.nextLine();
        return userMenuChoice;
    }

    /**
     * Method that asks the user for thier guess and asks them to input it in the console. 
     * @return a lowercase string of the user input
     */
    private String getUserGuessWord(){
        System.out.println("\nGuess a 5-letter word (lower case) or enter * to give up");
        System.out.print("> ");
        return userInput.nextLine().toLowerCase();
    }

    /**
     * Method that selects a random word form all the available game words 
     * @param wordList list of all the available game words
     * @return a string representing a random word that is selected from the list of all the available game words
     */
    private String randomWord(ArrayList<String> wordList){
        Random randomSelector = new Random(System.currentTimeMillis());
        int radomWordIndex = randomSelector.nextInt(wordList.size());
        return (wordList.get(radomWordIndex));
    }

    /**
     * Method that checks the number of matching characters (hits) between the secret word and users' guessed word.
     * @param userChoice users' guessed word
     * @param secretWord game's secret word
     * @return the number of matching characters (hits) bewteen the secret word and users' guessed word.
     */
    private int checkHits(String userChoice, String secretWord){
        int numberOfMatchingCharacters = 0;
        ArrayList<Character> matchedChars = new ArrayList<>();
       
        for(int i = 0; i < userChoice.length(); i++){
            for(int j = 0; j < secretWord.length(); j++){
                if(userChoice.charAt(i) == secretWord.charAt(j)){
                    if(!matchedChars.contains(Character.valueOf(userChoice.charAt(i)))){
                        numberOfMatchingCharacters++;
                    }
                    matchedChars.add(Character.valueOf(userChoice.charAt(i)));
                }
            }
        }
        return (numberOfMatchingCharacters);
    }

    /**
     * Method that adds the users' guessed word along with the number of hits
     * in the ArrayList guessedWords and guessedWordHits respectively
     * @param guessedWord users' guessed words
     * @param hits number of hits between the users' guessed word and game's secret word
     */
    private void addToGuessedList(String guessedWord, int hits){
        this.guessedWords.add(guessedWord);
        this.guessedWordsHits.add(Integer.valueOf(hits));
    }

    /**
     * Method that prints all the guessed words for current game instance as well as its corresponding hits to the console
     */
    private void printGuessedWords(){     
        ArrayList<String> tempGuess = new ArrayList<>(this.guessedWords);
        ArrayList<Integer> tempHits = new ArrayList<>(this.guessedWordsHits);

        Collections.reverse(tempGuess);
        Collections.reverse(tempHits);

        StringBuilder guessedWordsTable = new StringBuilder();
        guessedWordsTable.append("-------------\n");
        for (int i = 0; i < guessedWords.size(); i++) {
            guessedWordsTable.append("| " + tempGuess.get(i) + " | " + tempHits.get(i) + " |\n");
        }
        guessedWordsTable.append("-------------\n");
        System.out.println(guessedWordsTable.toString());
    }

    /**
     * setter method that sets toggles the cheat for the game to on/off
     * @param cheatOn boolean value that will toggle the game cheat on/off
     */
    public void isCheatOn(boolean cheatOn){
        this.cheatOn = cheatOn;
    }
}

