package task1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Class that will be used to read Bond Movies data from the given 
 * text file. The read data will then be stored and accessed in form of 
 * an Arraylist
 */
public class DataReader {
    private Scanner fileScanner; //Scanner that will read each line from the data file
    private String fileName; //directory/name of the data file

    public DataReader(String fileName){
        this.fileName = fileName;
    }

    /**
     * Method that will read each line of the given text file. Then each line of 
     * the data file will be parsed into a BondMovie type which will be then stored
     * in an ArrayList
     * @return an ArrayList of all the BondMovies read from the given text file
     */
    public ArrayList<BondMovie> readDataIntoList(){
        
        ArrayList<BondMovie> movie = null; 
        try{
            fileScanner = new Scanner(new BufferedReader(new FileReader(this.fileName)));
            movie = readDataIntoListHelper(this.fileScanner);
        }catch(FileNotFoundException e){
            System.err.println("File not found on disk. :(");
        }finally{
            fileScanner.close();
        }
        return (new ArrayList<>(movie));
    }

    /**
     * Method that will actually do the reading of each new line from the text file
     * and parse them into a BondMovie type
     * @param currentFileScanner scanner that will read each line form the given text file
     * @return an ArrayList of all the BondMovies read from the given text file
     */
    private ArrayList<BondMovie> readDataIntoListHelper(Scanner currentFileScanner){
        String dataFileLineFeed;

        String[] movieDetails;
        BondMovie movie;
        ArrayList<BondMovie> allMovieData = new ArrayList<>();
       
        while (currentFileScanner.hasNextLine()){
            dataFileLineFeed = currentFileScanner.nextLine();
            movieDetails = dataFileLineFeed.split(":");
            movie = buildBondMovie(movieDetails);
            allMovieData.add(movie);
        }

        return (new ArrayList<>(allMovieData));
    }

    /**
     * Method that parses each line read from the text file and builds a BondMovie type from 
     * the parsed line
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return BondMovie build from the line passed as an Array of String
     */
    private BondMovie buildBondMovie(String[] movieDetails){
        String[] movieTitleAndYear = splitMovieTitleAndYear(movieDetails);
        String[] movieVillanActAndCharName = splitVillianActAndCharName(movieDetails);
        String[] movieHeroineActAndCharName = splitHeroineActAndCharName(movieDetails);
        String[] featuredLocations = splitFeaturedLocations(movieDetails);
        String[] featuredCars = splitFeaturedVehicles(movieDetails);

        BondMovie movie = buildBondMovieWithTitleAndYear(movieTitleAndYear);
        addActorDirectorAndCompser(movie, movieDetails);
        addMovieVillianDetails(movie, movieVillanActAndCharName);
        addMovieHeroineDetails(movie, movieHeroineActAndCharName);
        addFeaturedLocations(movie, featuredLocations);
        addFeaturedVehicles(movie, featuredCars);

        return (new BondMovie(movie));
    }

    /**
     * Helper method of buildBondMovie(String[]) method that parses the movie title and 
     * movie year from the line read from the text file and passed as an Array of String
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return an Array (size 2) of String whose first element is the movie title and second element is the movie year 
     */
    private String[] splitMovieTitleAndYear(String[] movieDetails){
        return (movieDetails[0].split("[()]"));
    }

    /**
     * Helper method of buildBondMovie(String[]) method that parses the villian actor's name and
     * villian character's name from the line read from the text file and passed as an Array of String
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return an Array (size 2) of String whose first element is the movie title and second element is the movie year 
     */
    private String[] splitVillianActAndCharName(String[] movieDetails){
        return (movieDetails[2].split("[()]"));
    }

    /**
     * Helper method of buildBondMovie(String[]) method that parses the heroine actress's name and
     * heroine character's name from the line read from the text file and passed as an Array of String
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return an Array (size 2) of String whose first element is the heroine actress's name and second element is the  heroine character's name
     */
    private String[] splitHeroineActAndCharName(String[] movieDetails){
        return (movieDetails[3].split("[()]"));
    }

    /**
     * Helper method of buildBondMovie(String[]) method that parses the name of all featured locations of movie
     * from the line read from the text file and passed as an Array of String
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return an Array of String whose elements is the name of all featured locations of movie
     */
    private String[] splitFeaturedLocations(String[] movieDetails){
        return (movieDetails[(movieDetails.length - 2)].split("[|]"));
    }

    /**
     * Helper method of buildBondMovie(String[]) method that parses the name of all featured vehicles of movie
     * from the line read from the text file and passed as an Array of String
     * @param movieDetails the line to be parsed passed as an Array of String with each words of the line as an element
     * @return an Array of String whose elements is the name of all featured vehicles of movie
     */
    private String[] splitFeaturedVehicles(String[] movieDetails){
        return (movieDetails[(movieDetails.length - 1)].split("[|]"));
    }

    /**
     * Helper method of buildBondMovie(String[]) that builds a new BondMovie type from the title and year which is
     * passed as elements of an Array of String 
     * @param movieTitleAndYear an Array of String containg th title and movie year of the BondMovie which is to be built.
     * @return a BondMovie type built from the passed (as elements of a Strign Array) movie title and movie year 
     */
    private BondMovie buildBondMovieWithTitleAndYear(String[] movieTitleAndYear){
        return (new BondMovie(movieTitleAndYear[0], Integer.parseInt(movieTitleAndYear[1])));
    }

    /**
     * Helper method of buildBondMovie(String[]) that adds the name of movie actor, director and composer 
     * (Passed as Array of String) to the passed BondMovie type 
     * @param movie BondMovie to which name of movie actor, director and composer is to be added
     * @param movieDetails a String of array which contains name of movie actor, director and composer to be added
     */
    private void addActorDirectorAndCompser(BondMovie movie, String[] movieDetails){
        movie.setBondActor(movieDetails[1]);
        movie.setDirector(new Director(movieDetails[4]));
        movie.setComposer(new Composer(movieDetails[5]));
    }

    /**
     * Helper method of buildBondMovie(String[]) that adds the name of villian actor and villian character 
     * (Passed as Array of String) to the passed BondMovie type  
     * @param movie BondMovie to which name of villian actor and villian character is to be added
     * @param movieVillanActAndCharName a String of array which contains name of villian actor and villian character to be added
     */
    private void addMovieVillianDetails(BondMovie movie, String[] movieVillanActAndCharName){
        movie.setVillainActor(movieVillanActAndCharName[0]);
        movie.setVillainCharacter(movieVillanActAndCharName[1]);
    }

    /**
     * Helper method of buildBondMovie(String[]) that adds the name of heroine actress and heroine character 
     * (Passed as Array of String) to the passed BondMovie type
     * @param movie BondMovie to which name of heroine actress and heroine character is to be added
     * @param movieHeroineActAndCharName a String of array which contains name of heroine actress and heroine character to be added
     */
    private void addMovieHeroineDetails(BondMovie movie, String[] movieHeroineActAndCharName){
        movie.setHeroineActor(movieHeroineActAndCharName[0]);
        movie.setHeroineCharacter(movieHeroineActAndCharName[1]);
    }

    /**
     * Helper method of buildBondMovie(String[]) that adds the name of all locations featured in the movie 
     * (Passed as Array of String) to the passed BondMovie type
     * @param movie BondMovie to which name of all locations featured in the movie is to be added
     * @param featuredLocations a String of array which contains name of all locations featured in the movie to be added
     */
    private void addFeaturedLocations(BondMovie movie, String[] featuredLocations){
        ArrayList<String> featuredLocsList = new ArrayList<>();
        for (String location : featuredLocations) {
            featuredLocsList.add(location);
        }
        movie.setFilmLocations(new ArrayList<>(featuredLocsList));
    }

    /**
     * Helper method of buildBondMovie(String[]) that adds the name of all vehicles featured in the movie 
     * (Passed as Array of String) to the passed BondMovie type
     * @param movie BondMovie to which name of all vehicles featured in the movie is to be added
     * @param featuredVehicles a String of array which contains name of all vehicles featured in the movie to be added
     */
    private void addFeaturedVehicles(BondMovie movie, String[] featuredVehicles){
        ArrayList<String> featuredVehiclesList = new ArrayList<>();
        for (String cars : featuredVehicles){
            featuredVehiclesList.add(cars);
        }
        movie.setVehicles(new ArrayList<>(featuredVehiclesList));
    }
}
