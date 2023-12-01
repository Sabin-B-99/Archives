package task2;


import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Random;
import java.util.TreeMap;

/**
 * A class whose objects represents a gym in the chain. Objects of this class contains every information
 * related to a gym in the chain. These information includes the list of gym trainers, list of gym members,
 * all class session that these gym takes and so on. 
 * NOTE: The name of class session that a gym class is expected to be different. Ex: No gym can have two
 *        class sessions both named Zumba. Suggestion to resolve such conflicts can be using different class names
 *        like Zumba@Date etc. 
 */
public class Gym {
    private String name; //name of the gym
    private ArrayList<Trainer> gymTainers; //list of all Trainers of current gym
    private ArrayList<Member> gymMembers; //list of all members of current gym
    private static int uniqueMemberId = 0; //unique id that will be handed to each new member when he/she joins the gym

    /**
     * list of all the class sessions that this gym is holding. 
     * Key: String -> Class Session's name, Value -> Class Session's
     */
    private TreeMap<String,ClassSession> classSessions; 

    /**
     * random number generator which will be used to retrive a random trainer from the trainers list
     * who will be assigned as a personal trainer to the new member when he joins the gym
     */
    private static Random randomSelector = new Random(System.currentTimeMillis());

    public Gym(String name){
        this.name = name;
        this.gymTainers = new ArrayList<>();
        this.gymMembers = new ArrayList<>();
        this.classSessions = new TreeMap<>();
    }


    /**
     * Method to add new member to current gym
     * @param memberName name of Member who is to be added
     * @return true if member is added to current gym, false otherwiser
     */
    public boolean addMember(String memberName){
        uniqueMemberId++;
        int uniqueMemberNumber = uniqueMemberId;
        Member member = new Member(memberName, uniqueMemberNumber);
        
        if(!assignToTrainer(member)){
            uniqueMemberId--;
            return false;
        }

        gymMembers.add(member);
        return true;
    }


    /**
     * Method to add a new trainer to current gym
     * @param trainerName name of Trainer who is to be added
     */
    public void addTrainer(String trainerName){
        Trainer trainer = new Trainer(trainerName, this.getName());
        gymTainers.add(trainer);
    }


    /**
     * Method that assigns a personal trainer to a Member of the gym
     * @param member Member who is to be assigned with a personal trainer
     * @return true if a personal Trainer is successfully assigned to the Member, false otherwise
     */
    private boolean assignToTrainer(Member member){
        ArrayList<Trainer> trainerMembersFull = new ArrayList<>();
        ArrayList<Trainer> trainersNotFull = new ArrayList<>(); 
        
        for (Trainer trainer: gymTainers) {
            if(trainer.isMembersListFull()){
                trainerMembersFull.add(trainer);
            }else{
                trainersNotFull.add(trainer);
            }
        }

        if(trainerMembersFull.size() == gymTainers.size()){
            System.err.println("\nAll gym trainers are fully assigned. Add more trainers to your gym");
            return false;
        }

        int randomTrainerSelector = getRandom(trainersNotFull.size()); 
        Trainer trainer = trainersNotFull.get(randomTrainerSelector);
        member.setPerosnalTrainer(trainer);
        return (trainer.assignMember(member));
    }

    /**
     * Method that can be used to hold a class session by current gym
     * @param name name of the class session to be held
     * @param memLim member limit for the class session to be held
     * @param month month of current year for the class session to be held
     * @param day day of month for the class session to be held
     * @param hrs hour of day for the class session to be held
     * @param min minute of day for the class session to be held
     */
    public void takeClassSession(String name, int memLim, int month, int day, int hrs, int min){
        ClassSession cSession = new ClassSession(name, memLim);
        cSession.setTrainingDate(month, day);
        cSession.setTrainingTime(hrs, min);

        int randomTrainerSelector = getRandom(gymTainers.size());
        Trainer trainer = gymTainers.get(randomTrainerSelector);

        if(trainer.addTrainingSession(cSession)){
            cSession.setSessionTrainer(trainer);
            classSessions.put(name, cSession);
        }else{
            System.err.println("\nTrainer occupied with another session at the given date and time");
            System.err.println("for class Session at: Date" + cSession.getDate().toString() + ", Time: " + cSession.getStartTime().toString());
        }
    }


    /**
     * Method that can be used by any Member in the gym chain to book a class session (held by this gym)
     * @param member Member who is booking for the class session 
     * @param sessName name of the session (should be held by this gym) for which member likes to book into
     * @return true if booking is successful, false otherwise
     */
    public boolean bookClassSession(Member member, String sessName){
        for (String sessionName : classSessions.keySet()) {
            if(sessionName.equals(sessName)){
                String sessionTrainerName = classSessions.get(sessionName).getSessionTrainer().getName();
                LocalDate sessionDate = classSessions.get(sessionName).getDate();
                LocalTime sessionTime = classSessions.get(sessionName).getStartTime();

                System.out.println("\nClass Session Booking Successful!");
                System.out.println("Session booked with trainer: " + sessionTrainerName);
                System.out.println("Session Name: " + sessName + " | Session Date: " + sessionDate.toString() + " | Session Time: " + sessionTime.toString());
                if(classSessions.get(sessionName).addMember(member)){
                    member.addClassSession(classSessions.get(sessionName));
                }
            }
        }
        return false;
    }

    /**
     * Method to check whether current gym has a Member with given name and id or not
     * @param name name of Member whose existence is to be checked 
     * @param idNum id number of Member whose existence is to be checked
     * @return true if the Member with given name and id exists (is a member) in this gym, false otherwise
     */
    public boolean doesGymHaveMember(String name, int idNum){
        for (Member member : gymMembers) {
            if(member.getName().equals(name) && member.getNumber() == idNum){
                return true;
            }
        }
        return false;
    }

    /**
     * Method to retrive a Member with given name and id or not
     * @param name name of Member who is to be retrived 
     * @param idNum id number of Member who is to be retrived
     * @return Member with the given name and id num if found, null pointer otherwise
     */
    public Member findMemberByNameAndId(String name, int idNum){
        for (Member member : gymMembers) {
            if(member.getName().equals(name) && member.getNumber() == idNum){
                return member;
            }
        }
        return null;
    }

    /**
     * Method to retrive a Trainer with given name
     * @param name name of Trainer who is to be retrived 
     * @return Trainer with the given name if found, null pointer otherwise
     */
    public Trainer findTrainerByName(String name){
        for (Trainer trainer : gymTainers) {
            if(trainer.getName().equals(name)){
                return trainer;
            }
        }
        return null;
    }


    /**
     * Method to get a random number between 0 (inclusive) and the given bound (exclusive)
     * @param bound bound for the pseudo random number generator
     * @return an int representing a random number between 0 (inclusive) and the given bound (exclusive)
     */
    private int getRandom(int bound){
        return randomSelector.nextInt(bound);
    }

    //****************** Getter methods for field of current class starts ****************** */
    public ArrayList<Member> getGymMembers(){
        return gymMembers;
    }

    public ArrayList<Trainer> getGymTrainers(){
        return gymTainers;
    }

    public String getName(){
        return name;
    }

    public TreeMap<String,ClassSession> getClassSessions(){
        return classSessions;
    }
    //****************** Getter methods for field of current class ends ****************** */
    
}
