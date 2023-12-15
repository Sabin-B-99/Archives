import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

/**
 * Singelton class that is used to build Food Listing region of the user interface.
 * This region contains the list of food items selected from the menu and information
 * on the total accumulated price for all the selected items.
 */
public final class FoodListingRegion {
    private FoodListingRegion(){
    }

    /**
     * A static method that is used to build a Pane that will together hold different nodes
     * related to listing of selected food, total price etc. together.
     * @return A Pane that holds all the required nodes that lists all the selected food items and total price
     */
    public static Pane foodListingPane(){
        Pane orderListingHeaders = listingHeaderPane();
        ListView<Node> orderListings = FoodMenuPane.getOrderListingPane(); //node that lists all the selected food items
        Pane totalPrice = totalPriceTextAndLabel();

        VBox foodListingRegionPane = new VBox();
        foodListingRegionPane.getChildren().addAll(orderListingHeaders, orderListings, totalPrice);
        return foodListingRegionPane;
    }

    /**
     * A static method that will build pane that will all hold all the nodes that displays 
     * all information related to user who is currently using the EPOS to order food items off 
     * of it. These inforamtion inculdes user name, table number and order number 
     * @return pane that will all hold all the nodes that displays all information related to user
     */
    private static Pane listingHeaderPane(){
        Label userNameLabel = new Label("Smith");
        userNameLabel.setTextFill(Color.valueOf("#01008c"));
        userNameLabel.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
        
        
        Label tableNumLabel = new Label("Table 6 (2 seats)");
        tableNumLabel.setTextFill(Color.valueOf("#01008c"));
        tableNumLabel.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
        
        
        Label orderNumLabel = new Label("Order #12345");
        orderNumLabel.setTextFill(Color.valueOf("#01008c"));
        orderNumLabel.setFont(Font.font("Verdana", FontWeight.BOLD, 13));

        BorderPane orderListingHeaders = new BorderPane();
        orderListingHeaders.setPrefHeight(50);
        orderListingHeaders.setStyle("-fx-background-color: #aed8e6");

        
        orderListingHeaders.setLeft(userNameLabel);
        orderListingHeaders.setCenter(tableNumLabel);
        orderListingHeaders.setRight(orderNumLabel);
        
        BorderPane.setAlignment(userNameLabel, Pos.CENTER);
        BorderPane.setAlignment(orderNumLabel, Pos.CENTER);
        BorderPane.setAlignment(tableNumLabel, Pos.CENTER);

        BorderPane.setMargin(userNameLabel, new Insets(0, 15, 0, 15));
        BorderPane.setMargin(orderNumLabel, new Insets(0, 15, 0, 15));


        return orderListingHeaders;

    }

    /**
     * A static method to build build a pane that holds the information of the total price of 
     * all the selected food items from the menu
     * @return Pane that holds the information of the total price of all the selected food items from the menu
     */
    private static Pane totalPriceTextAndLabel(){
        Label totalPriceText = new Label("Total");
        totalPriceText.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
        totalPriceText.setTextFill(Color.WHITE);
        totalPriceText.setAlignment(Pos.CENTER_LEFT);

        Label totalPrice = FoodMenuPane.getTotalPricLabel(); //Label that contains the number of the total price
        totalPrice.setAlignment(Pos.CENTER_RIGHT);
        
        BorderPane totalPriceBox = new BorderPane();
        totalPriceBox.setPadding(new Insets(10,10,10,5));
        totalPriceBox.setPrefHeight(50);
        totalPriceBox.setStyle("-fx-background-color: #01008c");

        totalPriceBox.setLeft(totalPriceText);
        totalPriceBox.setRight(totalPrice);
        
        BorderPane.setAlignment(totalPriceText, Pos.CENTER);
        BorderPane.setAlignment(totalPrice, Pos.CENTER);
        
        BorderPane.setMargin(totalPriceText, new Insets(0, 15, 0, 15));
        BorderPane.setMargin(totalPrice, new Insets(0, 15, 0, 15));

        return totalPriceBox;
    }    
}
