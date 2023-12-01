package task1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeSet;

/**
 * Class whose objects can be used to sort all the bond movies either by Directors or
 * by Composer. The methods of this class can be used to display the sorted tables to the
 * console screen.
 */
public class BondMovieSorter extends BondMoviesDataTable{

    /**
     * List of all the directors who have directed a bond movie at least once. 
     * Director who have directed bond movie more than once are also listed only once.
     */
    private TreeSet<Director> allUniqueDirectors;
    /**
     * List of all the Composers who have composed theme music for a bond movie at least once. 
     * Composer who  have composed theme music more than once are also listed only once.
     */ 
    private TreeSet<Composer> allUniqueComposers;
 
    public BondMovieSorter(ArrayList<BondMovie> allMovieData) {
        super(allMovieData);
        this.allUniqueDirectors = new TreeSet<>();
        this.allUniqueComposers = new TreeSet<>();
        findAllUniqueComposers();
        findAllUniqueDirectors();
        findAllUniqueComposerMovies();
        findAllUniqueDirectorMovies();
    }

    /**
     * Method that will sort all the Bond Movies by the name of Composers and 
     * display the sorted table in the console
     */
    public void sortByComposers(){
        TreeSet<Director> directorsOfMovieOfComposer = new TreeSet<>();
        
        System.out.println("\n" + sortedTableHeader('c')); 
        for (Composer composer : allUniqueComposers) {
            directorsOfMovieOfComposer = composersMovieDirector(composer);  
            System.out.print(buildComposerInfoRow(composer, directorsOfMovieOfComposer));
            System.out.println((getTablesHorizontalMargin(4.5)));
        }
    }

    /**
     * Method that will sort all the Bond Movies by the name of Directors and 
     * display the sorted table in the console
     */
    public void sortByDirectors(){
        TreeSet<BondMovie> directorAllBondMovie = null;

        System.out.println("\n" + sortedTableHeader('d'));
        for (Director director : allUniqueDirectors) {
            directorAllBondMovie = new TreeSet<>(director.getMovieList());
            System.out.print(buildDirectorInfoRow(director, directorAllBondMovie));
            System.out.println((getTablesHorizontalMargin(4.5)));
        }
    }

    /**
     * Method that will build a list of all the Directors with whom a Composer
     * has worked alongside in a bond movie
     * @param composer Composer whose colleague director's list is to be build
     * @return  a Treeset<Director> representing list of all the Directors with whom a Composer has worked alongside in a bond movie
     */
    private TreeSet<Director> composersMovieDirector(Composer composer){
        List<Director> directors = new ArrayList<>();
        for (BondMovie movie : composer.getMovieList()) {
            directors.add(movie.getDirector());
        }
        Collections.sort(directors);
        return new TreeSet<>(directors);
    }

    /**
     * Method that will build a list of bond movies in which both the Director and Composer have 
     * worked together
     * @param dir Director of the movie with which the Composer has worked with
     * @param comp Composer of the movie with which the Director has worked with
     * @return an ArrayList of bond movies in which both the Director and Composer have worked together
     */
    private ArrayList<BondMovie> findMovieTitleFormDirAndComp(Director dir, Composer comp){
        boolean validity = false;
        ArrayList<BondMovie> matchingMovies = new ArrayList<>();
        for (BondMovie bondMovie : allMovieData) {
            validity = bondMovie.getDirector().getName().equals(dir.getName()) &&  bondMovie.getComposer().getName().equals(comp.getName());
            if(validity){
                matchingMovies.add(bondMovie);
            }
        }
        return new ArrayList<>(matchingMovies);
    }

    /**
     * Method that finds all the unique composers who have composed theme music for a bond movie at
     * least once. After finding the unique composer, this method will add the Composer to the allUniqueComposers
     * field variable of this class
     */
    private void findAllUniqueComposers(){
        for (BondMovie bondMovie : allMovieData) {
            allUniqueComposers.add(bondMovie.getComposer());
        }
    }


    /**
     * Method that will find all the movies for which a unique composer in allUniqueComposers field of this class
     * in has composed theme music for
     */
    private void findAllUniqueComposerMovies(){
        for (Composer composer : allUniqueComposers) {
            for (BondMovie bondMovie : allMovieData) {
                if(composer.getName().equals(bondMovie.getComposer().getName())){
                    composer.addMovie(bondMovie);
                }
            }   
        }
    }

    /**
     * Method that will find all the movies directed a unique director 
     * in allUniqueComposers field of this class
     */
    private void findAllUniqueDirectorMovies(){
        for (Director director : allUniqueDirectors) {
            for (BondMovie bondMovie : allMovieData) {
                if(director.getName().equals(bondMovie.getDirector().getName())){
                    director.addMovie(bondMovie);
                }
            }   
        }
    }

    /**
     * Method that finds all the unique directors who have composed theme music for a bond movie at
     * least once. After finding the unique director, this method will add the director to the allUniqueDirectors
     * field variable of this class
     */
    private void findAllUniqueDirectors(){
        for (BondMovie bondMovie : allMovieData) {
            allUniqueDirectors.add(bondMovie.getDirector());
        }
    }

    /**
     * Method to build a String which contains the first row (header row) of the sorted table
     * that will be displayed in the console
     * @param flag flag which specifies the type (by composer or by director) of sorted table that will be built
     * @return  String which contains the first row (header row) of the sorted table 
     */
    private String sortedTableHeader(char flag){


        String firstCell;
        String secondCell = "Title";
        String thirdCell = "Year";
        String fourthCell;

        if(flag == 'c'){
            firstCell = "Composer";
            fourthCell = "Director";
        }else{
            firstCell = "Director";
            fourthCell = "Bond Actor";
        }

        StringBuilder builder = new StringBuilder();
        builder.append(getTablesHorizontalMargin(4.5)).append("\n");
        
        builder.append("| ").append(firstCell);
        if(flag == 'c'){
            builder.append(getWhiteSpaces(longestComposerNameLength - firstCell.length() + whiteSpaceToRightOfEachCell));
        }else{
            builder.append(getWhiteSpaces(longestDirectorNameLength - firstCell.length() + whiteSpaceToRightOfEachCell));
        }        

        builder.append(" | ").append(secondCell);
        builder.append(getWhiteSpaces(longestMovieTitleLength - secondCell.length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(thirdCell);


        builder.append(" | ").append(fourthCell);

        if(flag == 'c'){
            builder.append(getWhiteSpaces(longestDirectorNameLength - fourthCell.length() + whiteSpaceToRightOfEachCell));
        }else{
            builder.append(getWhiteSpaces(longestActorNameLength - fourthCell.length() + whiteSpaceToRightOfEachCell)).append(" ");
        }     
        
        builder.append(" |").append("\n");
        builder.append(getTablesHorizontalMargin(4.5));
        return builder.toString();
    }
    
    /**
     * Method to build a String that contains all the information that needs to be printed while displaying the table
     * sorted by Composer on the console
     * @param composer composer whose info is to be displayed on this row of the table
     * @param directorsOfMovieOfComposer all the directors composer has worked with
     * @return  a String that contains all the information that needs to be printed while displaying the table sorted by Composer on the console
     */
    private String buildComposerInfoRow(Composer composer, TreeSet<Director> directorsOfMovieOfComposer){
        StringBuilder builder = new StringBuilder();
        boolean composerPrintedOnce = false;
        ArrayList<BondMovie> allMoviesOfBothDirectorAndComposer = new ArrayList<>();

        for (Director dir : directorsOfMovieOfComposer) {
            allMoviesOfBothDirectorAndComposer = findMovieTitleFormDirAndComp(dir, composer);
            
            for (BondMovie bondMovie : allMoviesOfBothDirectorAndComposer) {
                if(!composerPrintedOnce){
                    builder.append("| ").append(composer.getName());
                    builder.append(getWhiteSpaces(longestComposerNameLength - composer.getName().length() + whiteSpaceToRightOfEachCell));
                    builder.append(" | ").append(bondMovie.getTitle());
                    builder.append(getWhiteSpaces(longestMovieTitleLength - bondMovie.getTitle().length() + whiteSpaceToRightOfEachCell));
                    builder.append(" | ").append(bondMovie.getYear()).append(" ");
                    builder.append("| ").append(dir.getName());
                    builder.append(getWhiteSpaces(longestDirectorNameLength - dir.getName().length() + whiteSpaceToRightOfEachCell));
                    builder.append(" |").append("\n");
                    composerPrintedOnce = true;
                }else{
                    builder.append("| ");
                    builder.append(getWhiteSpaces(longestComposerNameLength + whiteSpaceToRightOfEachCell));
                    builder.append(" | ").append(bondMovie.getTitle());
                    builder.append(getWhiteSpaces(longestMovieTitleLength - bondMovie.getTitle().length() + whiteSpaceToRightOfEachCell));
                    builder.append(" | ").append(bondMovie.getYear()).append(" ");
                    builder.append("| ").append(dir.getName());
                    builder.append(getWhiteSpaces(longestDirectorNameLength - dir.getName().length() + whiteSpaceToRightOfEachCell));
                    builder.append(" |").append("\n");
                }
            }

        }
        return builder.toString();
    }


    /**
     * Method to build a String that contains all the information that needs to be printed while displaying the table
     * sorted by Director on the console
     * @param director director whose info is to be displayed on this row of the table
     * @param directorAllBondMovie all the movies the director has directed
     * @return a String that contains all the information that needs to be printed while displaying the table sorted by Director on the console
     */
    private String buildDirectorInfoRow(Director director, TreeSet<BondMovie> directorAllBondMovie){
        StringBuilder builder = new StringBuilder();
        boolean directorPrintedOnce = false;

        for (BondMovie bondMovie : directorAllBondMovie) {
            if(!directorPrintedOnce){
                builder.append("| ").append(director.getName());
                builder.append(getWhiteSpaces(longestDirectorNameLength - director.getName().length() + whiteSpaceToRightOfEachCell));
                builder.append(" | ").append(bondMovie.getTitle());
                builder.append(getWhiteSpaces(longestMovieTitleLength - bondMovie.getTitle().length() + whiteSpaceToRightOfEachCell));
                builder.append(" | ").append(bondMovie.getYear()).append(" ");
                builder.append("| ").append(bondMovie.getBondActor());
                builder.append(getWhiteSpaces(longestActorNameLength - bondMovie.getBondActor().length() + whiteSpaceToRightOfEachCell));
                builder.append("  |").append("\n");
                directorPrintedOnce = true;
            }else{
                builder.append("| ");
                builder.append(getWhiteSpaces(longestDirectorNameLength + whiteSpaceToRightOfEachCell));
                builder.append(" | ").append(bondMovie.getTitle());
                builder.append(getWhiteSpaces(longestMovieTitleLength - bondMovie.getTitle().length() + whiteSpaceToRightOfEachCell));
                builder.append(" | ").append(bondMovie.getYear()).append(" ");
                builder.append("| ").append(bondMovie.getBondActor());
                builder.append(getWhiteSpaces(longestActorNameLength - bondMovie.getBondActor().length() + whiteSpaceToRightOfEachCell));
                builder.append("  |").append("\n");
            }
        }
        return builder.toString();
    }
}
