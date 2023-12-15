package task2;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

/**
 * Concrete class of the abstract TrainingSession class that holds every 
 * information of the Class Session TrainingSession type
 */
public class ClassSession extends TrainingSession{
    private String name; //name of the class session
    private int limit;  //member limit for current class session


    public ClassSession(String name, int limit){
        this.name = name;
        this.limit = limit;
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
     * Getter method to retrive current Class Session's name (Ex: Zumba, Pilates, etc.)
     * @return String representing current class session's name
     */
    public String getName(){
        return name;
    }

    /**
     * Getter method to retrive member limit for current class session
     * @return int reprenting current class session's member limit
     */
    public int getLimit(){
        return limit;
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
        if(sessionMembers.size() >= this.limit){
            System.err.println("\nBooking Failed. Session Member Limit Reached. Try to book at another gym in the chain");
            return false;
        }
        if(!member.doesMemberHaveSessionOverlapAt(this.date, this.startTime, this.limit)){
            return sessionMembers.add(member);
        }else{
            System.err.println("\nBooking Failed. Member has another session at: " + this.date.toString() + " | " + this.startTime.toString());
            return false;
        }
    }

    /**
     * Method to retrive every info of current Class Session in form of a string
     * @return A String consisting of every info of current Class Session in form of a string
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("\nClass Session: ").append("\n");
        builder.append("Session Name: " + name).append("\n");
        builder.append("Session Member Limits: " + limit).append("\n");
        builder.append("Session Date: " + this.getDate().toString()).append("\n");
        builder.append("Session Time: " + this.getStartTime().toString()).append("\n");
        builder.append("Session Trainer: " + this.sessionTrainer.getName()).append("\n");
        builder.append("Session Gym: " + this.sessionTrainer.getEMployerName()).append("\n");
        builder.append("-------------------------------------------------------------------------------------------\n");
        builder.append("All Members registered for the session:").append("\n");
        builder.append("-------------------------------------------------------------------------------------------\n");

        
        int i = 0;
        for (Member member : sessionMembers) {
            builder.append(++i + ")").append(member.getName()).append("\n");
        }
        return builder.toString();
    }

    @Override
    protected Trainer getSessionTrainer() {
        return sessionTrainer;
    }
}
