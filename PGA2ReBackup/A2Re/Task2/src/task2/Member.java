package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

/**
 * Class whose objects represents a Member of a Gym. This clas contains every inforation of a member
 * including member's name, unique id number, personal trainer and list of all the sessions that 
 * this member has booked into.
 */
public class Member {
    private String name; //name of the member
    private int number; //unique id of the member
    private Trainer personalTrainer; //personal trainer of the member
    private ArrayList<TrainingSession> sessions; //all the training session the member is booked into

    public Member(String name, int number){
        this.name = name;
        this.number= number;
        this.sessions = new ArrayList<>();
    }

    /**
     * Method to check whether session in which member tries to book into
     * overlaps with other sessions this member has already booked into
     * @param date date of the new session to be be compared with existing booked sessions
     * @param time time of the new session to be be compared with existing booked sessions
     * @param sessTimeLimit time duration/limit of session to be be compared with existing booked sessions
     * @return true if two session's date/time overlaps, false otherwise
     */
    public boolean doesMemberHaveSessionOverlapAt(LocalDate date, LocalTime time, int sessTimeLimit){
        boolean sessionOverlaps = false;
        for (TrainingSession trainingSession : sessions) {
            if(trainingSession.getDate().equals(date)){
                sessionOverlaps = !trainingSession.getStartTime().isAfter(time.plusHours(sessTimeLimit));
                if(sessionOverlaps){
                    break;
                }
            }
        }
        return sessionOverlaps;
    }

    /**
     * Method with which current Member can book a personal session with his/her trainer.
     * @param sessDate date of a pesonal session to be booked
     * @param sessTime time of a pesonal session to be booked
     * @param durationInHrs duration in hours of a pesonal session to be booked
     * @return true if personal session booking is successful, false otherwise
     */
    public boolean bookPersonalSession(LocalDate sessDate, LocalTime sessTime, int durationInHrs){
        
        int duration = 2;
        if(durationInHrs > 6){
            System.err.println("\nPersonal Training duration can't be greater than 6 hrs.");
            System.out.println("Setting new duration for 2 hrs");
            System.out.println("Rebook with a new duration of less than 6 hours, if you are not satisfied with default 2 hrs booking.");
        }else{
            duration = durationInHrs;
        }

        PersonalSession session = new PersonalSession(duration);
        session.setTrainingDate(sessDate.getMonthValue(), sessDate.getDayOfMonth());
        session.setTrainingTime(sessTime.getHour(), sessTime.getMinute());

        if(this.personalTrainer.trainerHasSessionAtTimeOf(sessDate, sessTime) || this.doesMemberHaveSessionOverlapAt(sessDate, sessTime, duration)){
            System.err.println("\nSessions Time Overlapped");
            return false;
        };
        
        if(this.personalTrainer.addTrainingSession(session)){
            session.addMember(this);
            session.setSessionTrainer(this.personalTrainer);
            System.out.println("\nPersonal Session Booking Successful!");
            System.out.println("Session booked with your personal trainer: " + this.personalTrainer.getName());
            System.out.println("Session Date: " + sessDate.toString() + " | Session Time: " + sessTime.toString() + " | Session Duration: " + duration);
        } 
        
        return this.sessions.add(session);
    }

    /**
     * Method to add a new Training session to current Member's all booked sessions list
     * @param session Training session to be added to the list
     * @return true if addition is successful, fasle otherwise
     */
    public boolean addClassSession(TrainingSession session){
        return this.sessions.add(session);
    }

    /***************************** Setter and Getter Method starts ******************************** */
    public String getName(){
        return name;
    }

    public int getNumber(){
        return number;
    }

    public Trainer getPersonalTrainer(){
        return personalTrainer;
    }

    public void setPerosnalTrainer(Trainer personalTrainer){
        this.personalTrainer = personalTrainer;
    }
    /***************************** Setter and Getter Method ends ******************************** */


    /**
     * Method that returns every informaton about current Member in form of a String
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("\nMember name: ").append(this.name).append("\n");
        builder.append("************************** Info about all bookings ******************************************\n");
        for (TrainingSession trainingSession : sessions) {
            builder.append(trainingSession.toString());
            builder.append("\n-------------------------------------------------------------------------------------------");
        }
        return builder.toString();
    }
}
