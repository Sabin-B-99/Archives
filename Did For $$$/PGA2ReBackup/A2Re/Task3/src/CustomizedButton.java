import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

/**
 * Singelton class that can be used to build buttons, via builder methods of this class
 * for controlling different aspects of the EPOS system.
 */

public final class CustomizedButton {

    private CustomizedButton(){
    }

    /**
     * Builder method that is used to build a button with an image in it with the dimensions
     * as provided in the parameters
     * @param buttonImage   Image to be used for the button
     * @param width required width for the button
     * @param height    required height for the button
     * @return a Button of required size with the required image  
     */
    public static Button menuButton(ImageView buttonImage, double width, double height){
        buttonImage.setPreserveRatio(true);
        buttonImage.setFitWidth(width);
        buttonImage.setFitHeight(height);
        
        Button btn = new Button();
        btn.setPrefWidth(width);
        btn.setPrefHeight(height);
        btn.setGraphic(buttonImage);
        btn.setStyle("-fx-background-color: #ffffff; -fx-border-color: #ffffff" );
        return btn;
    }

    /**
     * Builder method that can be used to build a Button with the required text, dimension, background
     * color and button radius.
     * @param buttonText    text to be used on the button
     * @param width width of the button
     * @param height height of the button
     * @param backgColorCode background color for the button
     * @param radius radius for the edges of the button
     * @return  Button with the required text, dimension, background color and button radius.
     */
    public static Button menuControlButton(String buttonText, double width, double height, String backgColorCode, double radius){
        Button btn = new Button(buttonText);
        btn.setPrefWidth(width);
        btn.setPrefHeight(height);
        btn.setTextFill(Color.WHITE);
        btn.setAlignment(Pos.CENTER);
        btn.setFont(Font.font("Verdana", FontWeight.BOLD, 14));
        btn.setStyle("-fx-background-color: " + backgColorCode + "; -fx-border-color: White; -fx-border-radius: "+ radius +"; -fx-border-color: " + backgColorCode);
        return btn;
    }
}

