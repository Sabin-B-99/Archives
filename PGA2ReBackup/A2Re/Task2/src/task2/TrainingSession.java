package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

public abstract class TrainingSession {
    protected LocalDate date; //date of current training session
    protected LocalTime startTime; //time of current training session
    protected Trainer sessionTrainer;  //trainer who is taking current training session 
    protected ArrayList<Member> sessionMembers; //all members who are taking part in current training session


    /**
     * Method that sets the Training sessions's date to current year's month and day, 
     * which are provided as parameter to this method
     *
     * @param month month in which the Training session takes place
     * @param day day in which the Training session takes place
     */
    protected abstract void setTrainingDate(int month, int day);

    /**
     * Method that sets the Training sessions's time hours and minutes (in 24 hours time format), 
     * which are provided as parameter to this method
     * @param hrs hour in which the Training session takes place
     * @param min minute in which the Training session takes place
     */
    protected abstract void setTrainingTime(int hrs, int min);

    /**
     * Method to set the current Training sessions's trainer
     * @param sessionTrainer current session's trainer
     */
    protected abstract void setSessionTrainer(Trainer sessionTrainer);
    
    /**
     * Method to retrive current Training Session's date
     * @return LocalDate representing current training session's date
     */
    protected abstract LocalDate getDate();

    /**
     * Method to retrive current Training Session's time
     * @return LocalTime representing current training session's time
     */
    protected abstract LocalTime getStartTime();

    /**
     * Method to add a member to current Training session
     * @param member Member who is to be added in current Training sessio
     * @return true if addition of member to session's member list is successful, false otherwise
     */
    protected abstract boolean addMember(Member member);

    /**
     * Method to retrive current Training Session's trainer
     * @return
     */
    protected abstract Trainer getSessionTrainer();
}
