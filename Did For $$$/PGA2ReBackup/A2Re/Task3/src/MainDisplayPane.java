import java.io.File;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

/**
 * A singelton class that is used to build all the Pane that will hold all the required nodes
 * that will display every region (food listing, food selector and other non-iteractable regions)
 * of the EPOS.
 */
public final class MainDisplayPane {

    /**
     * String that holds directory information of the all the images that will be used in the non-ineractable 
     * regions of the EPOS
     */
    private static final String DELIVERY_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "delivery1.png";
    private static final String WIFI_SIGNAL_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "wifi2-icon.png";
    private static final String ONLINE_ORDER_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "online-order-icon.png";
  
    /**
     * All the images that will be used in the non-ineractable regions of the EPOS
     */
    private static final ImageView DELIVERY_IMG = new ImageView(DELIVERY_IMG_DIR);
    private static final ImageView WIFI_IMG = new ImageView(WIFI_SIGNAL_IMG_DIR);
    private static final ImageView ORDER_IMG = new ImageView(ONLINE_ORDER_IMG_DIR);

    
    private MainDisplayPane(){
    }

    /**
     * Static method that is used to build a pane that will hold all other nodes (in this case all other panes)
     * that will be displayed in the main interface of the EPOS
     * @return Pane that will hold all other nodes that will be displayed in the main interface of the EPOS
     */
    public static Pane mainDisplayPane(){
        Pane foodSelectorPane = FoodSelectorRegion.foodSelectorPane();
        Pane foodListingPane = FoodListingRegion.foodListingPane();

        HBox foodSelectorAndListing = new HBox();
        foodSelectorAndListing.getChildren().addAll(foodListingPane, foodSelectorPane);

        Pane onlineOptionsIcons = onlineOrderAndDeliveryPane();
        Pane cafeNameRegion = cafeNameBar("MDX Caf\u00E9"); 

        BorderPane mainDisplay = new BorderPane();
        mainDisplay.setStyle("-fx-background-color: #01008c");
        
        mainDisplay.setLeft(onlineOptionsIcons);
        mainDisplay.setTop(cafeNameRegion);
        mainDisplay.setCenter(foodSelectorAndListing);
        
        BorderPane.setAlignment(onlineOptionsIcons, Pos.CENTER);
        BorderPane.setAlignment(cafeNameRegion, Pos.CENTER_RIGHT);
        BorderPane.setAlignment(foodSelectorAndListing, Pos.CENTER);

        BorderPane.setMargin(cafeNameRegion, new Insets(5, 40, 0, 0));

        return mainDisplay;
    }

    /**
     * A static method to build a Pane that displays all the nodes that is used to display 
     * the non-interactable region of the EPOS which contains the icons that can if used
     * by the user for online ordering and delivery had those icons actually been a button instead
     * of images
     * @return Pane that displays all the nodes that is used to display the non-interactable region of the EPOS which contains the icons
     */
    private static Pane onlineOrderAndDeliveryPane(){
        WIFI_IMG.setPreserveRatio(true);
        WIFI_IMG.setFitWidth(40);
        WIFI_IMG.setFitHeight(40);
        
        ORDER_IMG.setPreserveRatio(true);
        ORDER_IMG.setFitWidth(40);
        ORDER_IMG.setFitHeight(40);

        DELIVERY_IMG.setPreserveRatio(true);
        DELIVERY_IMG.setFitWidth(40);
        DELIVERY_IMG.setFitHeight(40);

        VBox iconBox = new VBox();
        iconBox.setSpacing(10);
        iconBox.getChildren().addAll(WIFI_IMG, ORDER_IMG, DELIVERY_IMG);

        BorderPane iconBoxPane = new BorderPane();
        iconBoxPane.setPrefWidth(50);
        iconBoxPane.setTop(iconBox);
        BorderPane.setAlignment(iconBox, Pos.CENTER);
        BorderPane.setMargin(iconBox, new Insets(80, 10, 0, 10));

        return iconBoxPane;
    }

    /**
     * A static method that is used to build a Pane that contains all the nodes that used to display
     * the non-interactable region, which contains the name of cafe/resturants, of this EPOS
     * @param cafeName name of the cafe to be displayed
     * @return Pane that contains all the nodes that used to display name of cafe/resturants of this EPOS
     */
    private static Pane cafeNameBar(String cafeName){
        HBox nameBarBox = new HBox();
        nameBarBox.setAlignment(Pos.CENTER_RIGHT);
        nameBarBox.setPrefHeight(40);

        Label cafeNameLabel = new Label(cafeName);
        cafeNameLabel.setTextFill(Color.WHITE);
        cafeNameLabel.setFont(Font.font("Verdana", FontWeight.EXTRA_BOLD, 24));

        nameBarBox.getChildren().addAll(cafeNameLabel);
        return nameBarBox;
    }
}
