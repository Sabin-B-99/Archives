package task1;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Singelton class whose methods can be used to display different menu of the program 
 * and interact with the user through the console
 */
public final class ProgramManager {
    private static Scanner userMenuInput = new Scanner(System.in); //Scanner that takes user input from the console 
    private static ArrayList<BondMovie> programData = null; //list of all the bond movie data read from the given text file
    
    private ProgramManager(){
    }

    /**
     * Method to initialize the list of all the bond movie data read from the given text file
     * @param moviesData list which contains all the bond movie data read from the given text file
     */
    public static void initializeProgramData(ArrayList<BondMovie> moviesData){
        programData = moviesData; 
    }

    /**
     * Method that can be used to display main menu to the cosnole
     */
    public static void displayMainMenu(){
        System.out.println("\n----------------------");
        System.out.println("Main menu");
        System.out.println("----------------------");
        System.out.println("List.................1");
        System.out.println("Select...............2");
        System.out.println("Sort.................3");
        System.out.println("Exit.................0");
        System.out.println("----------------------\n");
    }

    /**
     * Method that can be used to read users' input (Main-menu option choice) once the main-menu 
     * is displayed
     * @return an int corrresponding to one of main menu options representing the users' main menu choice
     */
    public static int getMainMenuChoice(){
        int userChoice = 1;
        try {
            while (true) {
                System.out.print("Enter choice :> ");
                userChoice = userMenuInput.nextInt();
                if(userChoice >=0 && userChoice <=3){
                    break;
                }else{
                    System.err.println("Please enter a correct number from the list above.");
                }   
            }
        } catch (InputMismatchException e) {
            System.err.println("Error: InputMismatch. Enter a number, not a (string of) characters");
            System.out.println("Default choice: List (1) selected");
        }
        return userChoice;
    }

    /**
     * Method that can be used to display sorting menu to the cosnole
     */
    private static void displaySortingMenu(){
        System.out.println("\n----------------------");
        System.out.println("Sort options");
        System.out.println("----------------------");
        System.out.println("Sort by director.....1");
        System.out.println("Sort by composer.....2");
        System.out.println("Back to main menu....0");
        System.out.println("----------------------\n");
    }

    /**
     * Method that can be used to read users' input (sorting-menu option choice) once the sorting-menu 
     * is displayed
     * @return an int corrresponding to one of sorting menu options representing the users' sorting menu choice
     */
    private static int getSortMenuChoice(){
        int userChoice = 1;
        try {
            while (true) {
                System.out.print("Enter choice :> ");
                userChoice = userMenuInput.nextInt();
                if(userChoice >=0 && userChoice <=2){
                    break;
                }else{
                    System.err.println("Please enter a correct number from the list above.");
                }   
            }
        } catch (InputMismatchException e) {
            System.err.println("Error: InputMismatch. Enter a number, not a (string of) characters");
            System.out.println("Default choice: List (1) selected");
        }
        return userChoice;
    }

    /**
     * Method that can be used to read users' input from the console. This input represents the year of release of 
     * a bond movie whose infromation is to be printed to the console
     * @return an int representing the year of release of
     */
    private static int getYearChoice(){
        int userChoice = 2015;
        System.out.print("\nEnter year of movie :> ");
        try {
            userChoice = userMenuInput.nextInt();   
        } catch (InputMismatchException e) {
            System.err.println("Error: InputMismatch. Enter a number, not a (string of) characters");
            System.out.println("Default choice: Year 2015 selected");
        }
        return userChoice;
    }

    /**
     * Method to process further steps that needs to be taken once the user selects a choice from 
     * the main-menu
     * @param userChoice an int corrresponding to one of main menu options representing the users' main menu choice
     */
    public static void processMainMenuChoices(int userChoice){
        BondMoviesDataTable moviesDataTable = new BondMoviesDataTable(programData);
        
        if(programData != null){
            if(userChoice == 1){
                moviesDataTable.displayMoviesTable();
            }else  if(userChoice == 2){
                int yearChoice = getYearChoice();
                BondMovie movie = findBondMovieByYear(yearChoice);
                if(movie != null){
                    System.out.println(movie.toString());
                }else{
                    System.err.println("No Bond Movies found for year: " + yearChoice);
                }
            }else if(userChoice == 3){
                displaySortingMenu();
                processSortingMenuChoice(getSortMenuChoice());
            }else if(userChoice == 0){
                System.out.println("Thank you for using the program. :)");
            }else{
                System.err.println("Unexpected Error: At Main-menu Chocice Processor");
            }
        }
    }

    /**
     * Method to process further steps that needs to be taken once the user selects a choice from 
     * the sorting-menu
     * @param userChoice an int corrresponding to one of main menu options representing the users' choice in the sorting menu
     */
    private static void processSortingMenuChoice(int userChoice){
        BondMovieSorter movieSorter = new BondMovieSorter(programData);
        if(userChoice == 1){
            movieSorter.sortByDirectors();
        }else if(userChoice == 2){
            movieSorter.sortByComposers();
        }else if(userChoice == 0){
            System.out.println("Returning to main-menu ...");
        }else{
            System.err.println("Unexpected Error: At Sorting Menu Chocice Processor");
        }  
    }

    /**
     * Method to search a movie by the year in the database (Arraylist which contains all 
     * the bond movie data read from the given text file)
     * @param year the year for which the movie is to be searched for
     * @return BondMovie type for the given year if found, null otherwise
     */
    private static BondMovie findBondMovieByYear(int year){
        for (BondMovie bondMovie : programData) {
            if (bondMovie.getYear() == year) {
                return bondMovie;
            }
        }
        return null;
    }
}
