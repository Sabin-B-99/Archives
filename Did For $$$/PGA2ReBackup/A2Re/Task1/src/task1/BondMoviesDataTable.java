package task1;

import java.util.ArrayList;

/**
 * Class whose objects can be used to build a table which lists info of all the 
 * bond movies realesed over the years (read from the given text file)
 */
public class BondMoviesDataTable {
    
    protected int longestMovieTitleLength = 0; //length of the longest movie title among all the movies read from the file
    protected int longestActorNameLength = 0; //length of the longest name of bond actor among actors of all the movies read from the file
    protected int longestDirectorNameLength = 0; //length of the longest name of movie Director among directors of all the movies read from the file
    protected int longestComposerNameLength = 0; //length of the longest name of Composer among all composers of all the movies read from the file
    protected static final int whiteSpaceToRightOfEachCell = 2; //number of white spaces that must be placed after printable charactes in each cell of the table
    
    protected ArrayList<BondMovie> allMovieData;
    
    public BondMoviesDataTable(ArrayList<BondMovie> allMovieData){
        this.allMovieData = allMovieData;
        longestMovieTitleLength = findLongestMovieTitleLength();
        longestActorNameLength = findLongestBondActornNameLength();
        longestDirectorNameLength = findLongestDirectorNameLength();
        longestComposerNameLength = findLongestComposerNameLength();
    }


    /**
     * Method that displays, in the console, a table that contains information of all the Bond
     * Movies read from the text file
     */
    public void displayMoviesTable(){
        System.out.println(buildTableTitileRow());
        for(BondMovie m: allMovieData){
            System.out.println(buildMovieDetailRow(m));
        }
        System.out.println(getTablesHorizontalMargin(14));
    }

    /**
     * Method that builds a String which contains the first row (header row) of the Movies-info-table. This row will
     * contain all the header for each coloumn of the table. These headers represents the info delivered 
     * by data of its column.
     * @return a String which contains the first row (header row) of the Movies-info-table.
     */
    private  String buildTableTitileRow(){
        String year = "Year";
        String title = "Title";
        String actor = "Bond Actor";
        String director = "Director";
        String composer = "Composer";

        StringBuilder builder = new StringBuilder();
        builder.append(getTablesHorizontalMargin(14)).append("\n");
        builder.append("| ").append(year).append(" ");
        builder.append("| ").append(title);
        builder.append(getWhiteSpaces(longestMovieTitleLength - title.length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(actor);
        builder.append(getWhiteSpaces(longestActorNameLength - actor.length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(director);
        builder.append(getWhiteSpaces(longestDirectorNameLength - director.length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(composer);
        builder.append(getWhiteSpaces(longestComposerNameLength - composer.length() + whiteSpaceToRightOfEachCell));
        builder.append(" |").append("\n");
        builder.append(getTablesHorizontalMargin(14));
        return builder.toString();
    }

    /**
     * Method to build a String which contains a horizontal line that can be used as a border each row
     * of the table 
     * @param multipier a double which will be multiplied to the number of white space required right off of each cell, which then will be summed to all the int fields of thi class
     * @return  String which contains a horizontal line that can be used as a border each row of the table 
     */
    protected String getTablesHorizontalMargin(double multipier){
        StringBuilder builder = new StringBuilder();
        int marginLength = (int)(longestActorNameLength + longestComposerNameLength + longestDirectorNameLength + longestMovieTitleLength + (whiteSpaceToRightOfEachCell * multipier));
        for (int i = 0; i < marginLength  ; i++) {
            builder.append("-");
        }
        return builder.toString();
    }

    /**
     * Method that builds a String which contains all the information of movie that needs to be printed
     * in each row of the movie-info-table
     * @param movie name of movie whose info will be printed in this row
     * @return String which contains all the information of movie that needs to be printed in each row of the movie-info-table
     */
    private  String buildMovieDetailRow(BondMovie movie){
        StringBuilder builder = new StringBuilder();
        builder.append("| ").append(movie.getYear());
        builder.append(" | ").append(movie.getTitle());
        builder.append(getWhiteSpaces(longestMovieTitleLength - movie.getTitle().length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(movie.getBondActor());
        builder.append(getWhiteSpaces(longestActorNameLength - movie.getBondActor().length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(movie.getDirector().getName());
        builder.append(getWhiteSpaces(longestDirectorNameLength - movie.getDirector().getName().length() + whiteSpaceToRightOfEachCell));
        builder.append(" | ").append(movie.getComposer().getName());
        builder.append(getWhiteSpaces(longestComposerNameLength - movie.getComposer().getName().length() + whiteSpaceToRightOfEachCell));
        builder.append(" |");
        return builder.toString();
    }

    /**
     * Method to calculate the length of the longest movie title among all the movie titles read
     * from the text file 
     * @return int representing the length of the longest movie title among all the movie titles read
     */
    private  int findLongestMovieTitleLength(){
        int longestMovieNameLength = 0;
        for (BondMovie m : allMovieData) {
            if(m.getTitle().length() > longestMovieNameLength){
                longestMovieNameLength = m.getTitle().length();
            }
        }
        return longestMovieNameLength;
    }

    /**
     * Method to calculate the length of the longest name of bond actor's among all the bond actor's names read
     * from the text file 
     * @return int representing the length of the longest name of bond actor's among all the bond actor's names read
     */
    private  int findLongestBondActornNameLength(){
        int lonestBondActorNameLen = 0;
        for (BondMovie m : allMovieData) {
            if(m.getBondActor().length() > lonestBondActorNameLen){
                lonestBondActorNameLen = m.getBondActor().length();
            }
        }
        return lonestBondActorNameLen;
    }

    /**
     * Method to calculate the length of the longest name of director among all the director names read
     * from the text file 
     * @return int representing the length of the longest name of director among all the director names read
     */
    private int findLongestDirectorNameLength(){
        int lonestDirectorNameLen = 0;
        for (BondMovie m : allMovieData) {
            if(m.getDirector().getName().length() > lonestDirectorNameLen){
                lonestDirectorNameLen = m.getDirector().getName().length();
            }
        }
        return lonestDirectorNameLen;
    }

    /**
     * Method to calculate the length of the longest name of composer among all the composer names read
     * from the text file 
     * @return int representing the length of the longest name of composer among all the composer names read
     */
    private int findLongestComposerNameLength(){
        int lonestComposerNameLen = 0;
        for (BondMovie m : allMovieData) {
            if(m.getComposer().getName().length() > lonestComposerNameLen){
                lonestComposerNameLen = m.getComposer().getName().length();
            }
        }
        return lonestComposerNameLen;
    }


    /**
     * Method to build a String which contains only white spaces
     * @param length length of the String to be built
     * @return a String, of specified length, with only whitespaces
     */
    protected String getWhiteSpaces(int length){
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < length; i++) {
            builder.append(" ");
        }
        return builder.toString();
    }
}
