package task1;

import java.util.ArrayList;

/**
 * Class whose objects can be used to store and access information of a Director
 * who has written a theme music for a movie. This class implements the Comparable
 * interface and overrides its compareTo method. So, two Director are compared by 
 * their String name
 */
public class Director implements Comparable<Director>{
    private String name; //name of the director
    private ArrayList<BondMovie> movieList; //list of all the movies this director has worked on

    public Director(String name){
        this.name = name;
        this.movieList = new ArrayList<>();
    }

    /**
     * Method to add a movie to this directors movie list 
     * (list of all the movies this director has worked on)
     * @param m Movie to be added to this directors worked-movies list
     */
    public void addMovie(BondMovie m){
        movieList.add(m);
    }

    /**
     * Getter method that returns a String representing the name of this director
     * @return a String representing the name of this director
     */
    public String getName(){
        return name;
    }

    /**
     * Getter method that returns an ArrayList with all the  movies this director has worked on
     * @return an ArrayList with all the  movies this director has worked on
     */
    public ArrayList<BondMovie> getMovieList(){
        return movieList;
    }
    
    @Override
    public int compareTo(Director o) {
        return (this.name.compareTo(o.getName()));
    }
}
