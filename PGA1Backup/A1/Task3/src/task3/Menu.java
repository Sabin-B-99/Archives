package task3;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * A class that simulates a menu of the program. This menu includes different options among 
 * which the user can select one.
 */
public class Menu {
    
    private String menuTitle; //titile of the current menu
    private ArrayList<String> menuOptions; //list of all the options available in current menu context
    private static Scanner userInput = new Scanner(System.in); //scanner to get users' menu option choice form console 

    public Menu(String menuTitle){
        this.menuTitle = menuTitle;
        this.menuOptions = new ArrayList<>();
    }

    /**
     * Method that adds an option to the list of options of this menu in current context. This method 
     * doesn't add dupilcate options
     * @param option an string that is to be added to current menu options list
     */
    protected void addOption(String option){
        if(!this.menuOptions.contains(option)){
            menuOptions.add(option);
        }
    }

    /**
     * Method that prints the current menu to the console. It prints the current menu title along with
     * all the available menu options.
     */
    private void displayMenu(){
        System.out.println("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        System.out.println(this.menuTitle);
        System.out.println("____________________________________________________________________________");
        int i = 0;
        for(String o: menuOptions){
            System.out.println(o + " (" + (++i) + ")");
        }
        System.out.println("____________________________________________________________________________");
    }


    /**
     * Method that asks the user to select one of the opton form the available options in current menu.
     * The method asks the user to input a number corresponding to the option. If the user enters other
     * characters from keyboard and not a number then the method selects the first option from the list
     * by default.
     * @return an integer repreenting the option that the user selects from the current menu
     */
    private int getUserChoice(){
        int userMenuChoice = 1; 
        try{
            while(true){
                userMenuChoice = userInput.nextInt();
                if(userMenuChoice >= 1 && userMenuChoice <= this.menuOptions.size()){
                    break;
                }else{
                    if(this.menuOptions.size() == 1){
                        System.out.println("Please enter a valid choice.");
                        System.out.println("Enter 1 from the keyboard.");
                    }else{
                        System.out.println("Please enter a valid choice.");
                        System.out.println("Enter any number in range of: 1 - " + this.menuOptions.size());
                    }
                }
            }
        }catch(InputMismatchException e){
            System.err.println("Input Mismatch: Enter a number form your Keyboard.");
            System.out.println("Default option selected: " + this.menuOptions.get(userMenuChoice - 1));
        }
        userInput.nextLine();
        return userMenuChoice;
    }

    /**
     * Method that calculates the total number of options available in current menu
     * @return an integer representing total number of options available in current menu
     */
    private int getTotalNumOfOptions(){
        return this.menuOptions.size();
    }


    /**
     * Method that displays current menu and returns the option selected by the user.
     * The method uses tha already available private methods of this class to achieve this functionality
     * @return an integer repreenting the option that the user selects from the current menu
     */
    public int displayMenuAndGetUserChoice(){
        this.displayMenu();

        if(this.menuOptions.size() == 1){
            System.out.println("\nSelect an option form the list above.");
            System.out.println("Enter 1 from the keyboard.");
        }else{
            System.out.println("\nSelect an option form the list above. (1-" + this.getTotalNumOfOptions() + ")");
            System.out.println("Enter a number (1-" + this.getTotalNumOfOptions() + "), from Keyboard, corresponding of the option.\n");
        }

        System.out.print("> ");
        return this.getUserChoice();
    }

}
