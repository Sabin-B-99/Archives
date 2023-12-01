package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Singelton class that is used to run the overall program. It contains methods that displays 
 * different menu options as well as methods that can be used to get user inputs from the console.
 * It also has methods that processes the next steps to  be takes once it get useful inputs form
 * the console
 */
public final class ApplicationManager {
    private static ArrayList<Gym> applicationData; //List that contains all hardcoded program data
    private static Scanner userInpuScanner = new Scanner(System.in); //Scanner that is used to get user inputs
    private ApplicationManager(){
    }

    public static void initializeProgramData(ArrayList<Gym> data){
        applicationData = data; 
    }

    /**
     * Method to display the main-menu of the program
     */
    public static void displayMainMenu(){
        System.out.println("\n----------------------------------------------");
        System.out.println("Main menu");
        System.out.println("----------------------------------------------");
        System.out.println("Book pesonal training session................1");
        System.out.println("Book member on class session.................2");
        System.out.println("List trainer's class.........................3");
        System.out.println("List Member Booking..........................4");
        System.out.println("Exit.........................................0");
        System.out.println("----------------------------------------------\n");
    }

    /**
     * Method that is used to get read user's MainMenu option choice from the console.
     * @return the number corresponding to user's mainmenu option choice
     */
    public static int getMainMenuChoice(){
        int userChoice = 1;
        try {
            while (true) {
                System.out.print("Enter choice :> ");
                userChoice = userInpuScanner.nextInt();
                if(userChoice >=0 && userChoice <=4){
                    break;
                }else{
                    System.err.println("\nPlease enter a correct number from the list above.");
                }   
            }
        } catch (InputMismatchException e) {
            System.err.println("\nError: InputMismatch. Enter a number, not a (string of) characters");
            System.out.println("\nDefault choice: 'Book pesonal training session' (0) selected");
        }
        userInpuScanner.nextLine(); //Eating the new line character form previous buffer
        return userChoice;
    }

    /**
     * Method to further control, process and display relevant information to the console once the user
     * selects an option from the main menu 
     * @param userChoice the number corresponding to user's mainmenu option choice
     */
    public static void processMainMenuChoices(int userChoice){
        if(userChoice == 1){
            personalSessionBookingInfo();
        }else if(userChoice == 2){
            classSessionBookingInfo();
        }else if(userChoice == 3){
            trainerClassInfo();
        }else if(userChoice == 4){
            memberBookingInfo();
        }else if(userChoice == 0){
            System.out.println("\nThank you for using the gym services.");
        }else{
            System.err.println("\nUnexpected Error: At Main-menu Chocice Processor");
        }
    }

    /**
     * Method that needs to be invoked once first option from the main menu is selected.
     * This method is used to book a personal session by the member of the gym.
     * @return true if perosnal session booking is successful, false otherwise
     */
    private static boolean personalSessionBookingInfo(){

        String[] memberNameAndNum = getMemberNameAndNum();
        
        boolean memberFound = doesAnyGymInChainHasMemberWith(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));
        if(!memberFound){
            System.err.println("\nNo members of name: " + memberNameAndNum[0] + " ,and id number: " + memberNameAndNum[1] + " found in gym chain");
            return false;
        }

        Member member = findMemberWithNameAndId(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));


        System.out.println("\nEnter session date in format --> (yyyy-mm-dd)");
        String dateInput = userInpuScanner.nextLine();
        LocalDate date = null;
        try{
            date = LocalDate.parse(dateInput);
        }catch(DateTimeParseException e){
            System.err.println("Date Input Format Wrong... Booking Failed. Try again");
            return false;
        }

        System.out.println("\nEnter session time in format --> (hh:mm)(24 hrs clock)");
        String timeInput = userInpuScanner.nextLine();
        LocalTime time = null;
        try{
            time = LocalTime.parse(timeInput);
        }catch(DateTimeParseException e){
            System.err.println("\nTime Input Format Wrong... Booking Failed. Try again");
            return false;
        }

        System.out.println("\nEnter duration for session (in hours). Recommended at least 1 hours: ");
        int duration = userInpuScanner.nextInt();

        if(member != null){
            return member.bookPersonalSession(date, time, duration);
        }else{
            System.err.println("\nBooking failed. Error at final Stage of booking.... Reporting error.");
            return false;
        }
    }

    /**
     * Method that needs to be invoked once second option from the main menu is selected.
     * This method is used to book a class session by the member of the gym in any of the gym in chain.
     * @return
     */
    private static boolean classSessionBookingInfo(){
        String[] memberNameAndNum = getMemberNameAndNum();
        boolean memberFound = doesAnyGymInChainHasMemberWith(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));
        if(!memberFound){
            System.err.println("\nNo members of name: " + memberNameAndNum[0] + " ,and id number: " + memberNameAndNum[1] + " found in gym chain");
            return false;
        }

        Member member = findMemberWithNameAndId(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));

        System.out.println("\nEnter gym's name: ");
        String gymName  = userInpuScanner.nextLine();

        System.out.println("\nEnter session's name: ");
        String sessName  = userInpuScanner.nextLine();

        for (Gym gym : applicationData) {
            if(gym.getName().equals(gymName)){
                return gym.bookClassSession(member, sessName);
            }
        }

        System.err.println("\nNo gym named: " + gymName + " in chain");
        return false;
    }

    /**
     * Method that needs to be invoked once third option from the main menu is selected.
     * This method is used to see information of all 'Class Sessions' a certain trainer  in the given Date
     * @return true if the program can find and display the desired trainer's all class info, false otherwise 
     */
    private static boolean trainerClassInfo(){
        System.out.println("\nEnter trainer's name: ");
        String trainerName = userInpuScanner.nextLine();
        
        System.out.println("\nEnter session date in format --> (yyyy-mm-dd)");
        String dateInput = userInpuScanner.nextLine();
        LocalDate date = null;
        try{
            date = LocalDate.parse(dateInput);
        }catch(DateTimeParseException e){
            System.err.println("\nDate Input Format Wrong... Booking Failed. Try again");
            return false;
        }

        Trainer trainer = null;
        for (Gym gym : applicationData) {
            trainer = gym.findTrainerByName(trainerName);
            if(trainer != null){
                System.out.println("\n*********** At gym " + gym.getName() + " **************");
                trainer.displayAllClassSessionsOfTrainerAt(date);
                return true;
            }
        }

        System.err.println("Can't find the trainer named: " + trainerName + " in any of the gym in chain.");
        return false;
    }

    /**
     * Method that needs to be invoked once fourth option from the main menu is selected.
     * This method is used to see information of all Sessions a certain member has booked into 
     * @return true if the given user is found and his/her bookings is displayed on the console, false otherwise
     */
    private static boolean memberBookingInfo(){
        String[] memberNameAndNum = getMemberNameAndNum();
        boolean memberFound = doesAnyGymInChainHasMemberWith(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));
        if(!memberFound){
            System.err.println("\nNo members of name: " + memberNameAndNum[0] + " ,and id number: " + memberNameAndNum[1] + " found in gym chain");
            return false;
        }

        Member member = findMemberWithNameAndId(memberNameAndNum[0], Integer.parseInt(memberNameAndNum[1]));
        System.out.println(member.toString());
        return true;
    }

    /**
     * Utility method that can be used to get a member's name and unique membership id as an input from the console.
     * This method can be used in any other part of the program that requires member's name and id to be entered from
     * the console. 
     * @return an primitive array of String whose size is 2 and member's name is in the first index (0) whereas member's id is in the second index (1)
     */
    private static String[] getMemberNameAndNum(){
        System.out.println("\nEnter member's name: " );
        String name = userInpuScanner.nextLine();
        System.out.println("\nEnter member's identification Number: " );
        int idNum = userInpuScanner.nextInt();
        userInpuScanner.nextLine(); //Eating the new line character form previous buffer

        return new String[]{name, String.valueOf(idNum)};
    }


    /**
     * Utilty method to check whether any gym in the chain has a member with the given name and id
     * @param name name of member who is to be searched for
     * @param id id of member who is to be searched for
     * @return true if a member with the given name and id exists in any of the gym in chain, false otherwise
     */
    private static boolean doesAnyGymInChainHasMemberWith(String name, int id){
        for (Gym gym : applicationData) {
            if(gym.doesGymHaveMember(name, id)){
                return true;
            }
        }
        return false;
    }

    /**
     * Utilty method to get the Member (object) with the given name and address from the application's temprary database 
     * @param name name of member who is to be retrived from the application's temprary database
     * @param id id of member who is to be retrived from the application's temprary database
     * @return true if retrival is successful, false otherwise
     */
    private static Member findMemberWithNameAndId(String name, int id){
        for (Gym gym : applicationData) {
            if(gym.doesGymHaveMember(name, id)){
                return gym.findMemberByNameAndId(name, id);
            }
        }
        return null;
    }

}
