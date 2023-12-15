package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

/**
 * Class whose object holds every information of a Trainer in a Gym. These infomation includes
 * trainer's name, employer gym's name, list of member's assigned to this trainer by current 
 * empoyer gym as well as list of all the Training sessions this trainer will take.
 * Note: This class implements the Comparable interface whose compareTo method is overloaded
 *        to compare between two Trainer objects. This comparision takes on basis of the 
 *        name of two Trainers being compared
 */
public class Trainer implements Comparable<Trainer>{
    private String name; //name of current Trainer
    private String employerName; //name of current Trainer's employer gym
    private ArrayList<Member> assignedMembers; //list of all the Member's assigned to current gym
    private ArrayList<TrainingSession> trainingSessions; //list of all the Training sessions taken by this Trainer 

    public Trainer(String name, String employerName){
        this.name = name;
        this.employerName = employerName;
        this.assignedMembers = new ArrayList<>();
        this.trainingSessions = new ArrayList<>();
    }

    //copy constructor
    public Trainer(Trainer rhs){
        this.name = rhs.name;
        this.assignedMembers = rhs.assignedMembers;
    }

    /**
     * Method to add a new Training Session being taken by this Trainer to this Trainer's sessions list
     * @param session Training Session to be added to this Trainer's sessions list
     * @return true if addition of the session to the sessions list is successful, false otherwise
     */
    public boolean addTrainingSession(TrainingSession session){
       if(!trainerHasSessionAtTimeOf(session.getDate(), session.getStartTime())){
            return trainingSessions.add(session);
       }else{
           System.err.println("\nSession Time Overlaps. Pick another time for this session");
       }
       return false;
    }

    /**
     * Method to check whether this trainer has any other training sessions at the given date and time
     * @param date date in which a session existence is to be checked
     * @param time time in which a session existence is to be checked
     * @return true if this trainer has any other session at the given date and time, false otherwise
     */
    public boolean trainerHasSessionAtTimeOf(LocalDate date, LocalTime time){
        boolean timeOverlaps = false;

        for (TrainingSession ts : trainingSessions) {
            if(date.equals(ts.getDate())){
                timeOverlaps = !time.isAfter(ts.getStartTime().plusHours(1));
                if(timeOverlaps){
                    return true;
                }
            }
        }
        return timeOverlaps;
    }


    /**
     * Method to check if this trainer has more than 25 assigned members or not
     * @return true if this trainer has more than 25 assigned members, false otherwise
     */
    public boolean isMembersListFull(){
        if(this.assignedMembers.size() > 25){
            return true;
        }
        return false;
    }

    /**
     * Method that will display information of all the Training Sessions of this Trainer  at the given date to the console to
     * @param date date of training session whose information is to be displayed 
     */
    public void displayAllClassSessionsOfTrainerAt(LocalDate date){
        System.out.println("\n******************** Every Class Session of " + this.name + " at " + date.toString() + " ******************");
        for (TrainingSession session : trainingSessions) {
            if(session.getDate().equals(date) && (session instanceof ClassSession)){
                System.out.println(session.toString());
            }
        }
    }

    /**
     * Method to add a new member to this trainer's members list
     * @param member member who is to be assigned with this trainer
     * @return true if assign is successful, false otherwise
     */


    /***************************** Setter and Getter Method starts ******************************** */
    public ArrayList<TrainingSession> getTrainingSessions(){
        return trainingSessions;
    }

    public boolean assignMember(Member member){
        return (assignedMembers.add(member));
    }

    public String getName(){
        return name;
    }

    public String getEMployerName(){
        return employerName;
    }
    
    public ArrayList<Member> getAssignedMembers(){
        return assignedMembers;
    }
    /***************************** Setter and Getter Method ends ******************************** */

    /**
     * Overriden method from the Comparable interface that compres two
     * trainer on the basis of their String names
     */
    @Override
    public int compareTo(Trainer o) {
        return (this.name.compareTo(o.getName()));
    }
    
}
