package task1;

import java.util.ArrayList;

/**
 * Class whose objects can be used to store and access information of a Composer
 * who has written a theme music for a movie. This class implements the Comparable
 * interface and overrides its compareTo method. So, two Composer are compared by 
 * their String name
 */
public class Composer implements Comparable<Composer>{
    private String name; //name of the composer
    private ArrayList<BondMovie> movieList; //list of all the movies this composer has worked on

    public Composer(String name){
        this.name = name;
        this.movieList = new ArrayList<>();
    }

    /**
     * Method to add a movie to this composers movie list 
     * (list of all the movies this composer has worked on)
     * @param m Movie to be added to this composers worked-movies list
     */
    public void addMovie(BondMovie m){
        movieList.add(m);
    }

    /**
     * Getter method that returns a String representing the name of this composer
     * @return a String representing the name of this composer
     */
    public String getName(){
        return name;
    }

    /**
     * Getter method that returns an ArrayList with all the  movies this composer has worked on
     * @return an ArrayList with all the  movies this composer has worked on
     */
    public ArrayList<BondMovie> getMovieList(){
        return movieList;
    }
    
    @Override
    public int compareTo(Composer o) {
        return this.getName().compareTo(o.getName());
    }

}
