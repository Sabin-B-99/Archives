package task1;

import java.util.ArrayList;
/**
 * Class whose objects can b be used to store and access information of various Bond Movies realesed
 * throught the years. This method implements the Comparable infterface whose compareTo method is 
 * overriden in this class to compare two different type of Bond Movies on the basis of their 
 * String title
 */
public class BondMovie implements Comparable<BondMovie> {
    private int year; //year of release
    private String title; //title of movie
    private String bondActor; //name of lead actor of the movie
    private String villainActor; //name of actrot playing main villian of the movie
    private String villainCharacter; //name of villian character of the movie
    private String heroineActor; //name of actress playing the herrione of the movie
    private String heroineCharacter; //name of heroine character of the movie
    private Director director; //Director of the movie
    private Composer composer; //Composer of main theme song of the movie
    private ArrayList<String> filmLocations; //list of name of all the locations featured in the movie
    private ArrayList<String> vehicles; //list of name of all the vehicles featured in the movie

    public BondMovie(String title, int year){
        this.title = title;
        this.year = year;
    }

    public BondMovie(BondMovie rhs){
        this.year = rhs.getYear();
        this.title = rhs.getTitle();
        this.bondActor = rhs.getBondActor();
        this.villainActor = rhs.getVillainActor();
        this.villainCharacter = rhs.getVillainCharacter();
        this.heroineActor = rhs.getHeroineActor();
        this.heroineCharacter = rhs.getHeroineCharacter();
        this.director = rhs.getDirector();
        this.composer = rhs.getComposer();
        this.filmLocations = rhs.getFilmLocations();
        this.vehicles = rhs.getVehicles();
    }

    //******************** Getters And Setters for all private fields of this class ************ */
    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getBondActor() {
        return bondActor;
    }

    public void setBondActor(String bondActor) {
        this.bondActor = bondActor;
    }

    public String getVillainActor() {
        return villainActor;
    }

    public void setVillainActor(String villainActor) {
        this.villainActor = villainActor;
    }

    public void setVillainCharacter(String villainCharacter) {
        this.villainCharacter = villainCharacter;
    }

    public String getVillainCharacter(){
        return villainCharacter;
    }

    public String getHeroineActor() {
        return heroineActor;
    }

    public void setHeroineActor(String heroineActor) {
        this.heroineActor = heroineActor;
    }

    public String getHeroineCharacter() {
        return heroineCharacter;
    }

    public void setHeroineCharacter(String heroineCharacter) {
        this.heroineCharacter = heroineCharacter;
    }

    public Director getDirector() {
        return director;
    }

    public void setDirector(Director director) {
        this.director = director;
    }

    public Composer getComposer() {
        return composer;
    }

    public void setComposer(Composer composer) {
        this.composer = composer;
    }

    public ArrayList<String> getFilmLocations() {
        return filmLocations;
    }

    public void setFilmLocations(ArrayList<String> filmLocations) {
        this.filmLocations = filmLocations;
    }

    public ArrayList<String> getVehicles() {
        return vehicles;
    }

    public void setVehicles(ArrayList<String> vehicles) {
        this.vehicles = vehicles;
    }
    // *********************** Setters and Getters Ends *********************************************

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("\nTitle: ").append(title + "\n");
        builder.append("Bond: ").append(bondActor + "\n");
        builder.append("Villain: ").append("\"" + villainCharacter + "\" played by ").append(villainActor + "\n");
        builder.append("Heroine: ").append("\"" + heroineCharacter + "\" played by ").append(heroineActor + "\n");
        builder.append(allLocationString());
        builder.append(allVheiclesString());
        return builder.toString();
    }

    /**
     * Method that concatinates name of all the location featured in the movie and returns 
     * in in a form of String which can be printed directly to the console in a meaningful way
     * @return a String represnting name of all the location featured in the movie
     */
    private String allLocationString(){
        StringBuilder builder = new StringBuilder();
        builder.append("----------------------------\n");
        builder.append("Locations depicted in movie:\n");
        builder.append("----------------------------\n");
        for (String locs : filmLocations) {
            builder.append(locs).append("\n");
        }
        return builder.toString();
    }

    /**
     * Method that concatinates name of all the vheicles featured in the movie and returns 
     * in in a form of String which can be printed directly to the console in a meaningful way
     * @return a String represnting name of all the vheicles featured in the movie
     */
    private String allVheiclesString(){
        StringBuilder builder = new StringBuilder();
        builder.append("---------------------------\n");
        builder.append("Vehicles featured in movie:\n");
        builder.append("---------------------------\n"); 
        for (String vhecs : vehicles) {
            builder.append(vhecs).append("\n");
        }
        return builder.toString();
    }

    @Override
    public int compareTo(BondMovie o) {
        return (this.title.compareTo(o.getTitle()));
    }
}
