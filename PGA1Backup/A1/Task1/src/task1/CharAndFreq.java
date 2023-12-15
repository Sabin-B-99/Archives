package task1;

/**
 * CharAndFreq is a class/data-type that condenses a Charatcter 
 * and its corresponding Integer(frequency) into a single type.
 * This class implements a Comparable interface so that it can 
 * be compared with other objects of same class. It is implmented
 * so that it will be easier to later sort them.
 */
public class CharAndFreq implements Comparable<CharAndFreq> {
    private Character type; 
    private Integer frequency;
    
    public CharAndFreq(Character type, Integer frequency){
        this.type = type;
        this.frequency = frequency;
    }

    /**
     * Method to increase the frequency related current Character type
     */
    public void increaseFrequency(){
        this.frequency++;
    }

    /**
     * Getter method that returns the current frequency related current Character type
     * @return an integer representing current frequency related current Character type
     */
    public int getFrequency(){
        return this.frequency;
    }

    /**
     * Getter method that returns the current type of Character
     * @return an integer representing current Character type
     */
    public Character getType(){
        return this.type;
    }

    /**
     * Overriden compareTo method of the Comparable interface that compares
     * two types of the CharAndFreq class base on the frequency fields of each 
     * class.
     *  @return a positive num (1) if object of current class is greater than the object of class that is being compared to
     *          a negative num (-1) if object of current class is smaller than the object of class that is being comapred to
     *          a zero (0) if both of the objects being compared are equal
     */
    @Override
    public int compareTo(CharAndFreq o) {
        if(this.getFrequency()> o.getFrequency()){
            return 1;
        }else if(this.getFrequency()< o.getFrequency()){
            return -1;
        }else{
            return 0;
        }
    }
}
