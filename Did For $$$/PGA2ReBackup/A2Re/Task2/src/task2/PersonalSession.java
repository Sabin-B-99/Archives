package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

/**
 * Concrete class of the abstract TrainingSession class that holds
 * every information of the Personal Session TrainingSession type
 */
public class PersonalSession extends TrainingSession{
    
    private int duration; //duration in hours of current Personal Session

    public PersonalSession(int duration){
        this.duration = duration;
        this.sessionMembers = new ArrayList<>();
    }

    @Override
    protected void setTrainingDate(int month, int day) {
        this.date = LocalDate.of(LocalDate.now().getYear(), month, day);
        
    }

    @Override
    protected void setTrainingTime(int hrs, int min) {
        this.startTime = LocalTime.of(hrs, min);
        
    }

    /**
     * Getter method to retrive duration in hours for current Personal session
     * @return int reprenting current Personal session's duration in hours
     */
    public int getDuration(){
        return duration;
    }

    @Override
    protected void setSessionTrainer(Trainer sessionTrainer) {
        this.sessionTrainer = sessionTrainer; 
    }

    @Override
    protected LocalDate getDate() {
        return date;
    }

    @Override
    protected LocalTime getStartTime() {
        return startTime;
    }

    @Override
    protected boolean addMember(Member member) {
        return sessionMembers.add(member);
    }

    @Override
    protected Trainer getSessionTrainer() {
        return sessionTrainer;
    }

    /**
     * Method to retrive every info of current Personal Session in form of a string
     * @return A String consisting of every info of current Personal Session in form of a string
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("\nPersonal Session: ").append("\n");
        builder.append("Session Duration: " + duration).append(" hours").append("\n");
        builder.append("Session Date: " + this.getDate().toString()).append("\n");
        builder.append("Session Time: " + this.getStartTime().toString()).append("\n");
        builder.append("Session Trainer: " + this.sessionTrainer.getName()).append("\n");
        builder.append("Session Gym: " + this.sessionTrainer.getEMployerName()).append("\n");
        builder.append("-------------------------------------------------------------------------------------------\n");
        builder.append("Members registered for the session:").append("\n");
        builder.append("-------------------------------------------------------------------------------------------\n");

        
        int i = 0;
        for (Member member : sessionMembers) {
            builder.append(++i + ")").append(member.getName()).append("\n");
        }
        return builder.toString();
    }
    
}
