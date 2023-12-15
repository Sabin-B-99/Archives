import java.io.File;

import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

/**
 * Class whose objects can be used to build a Pane that holds the information (name, price and delete button)
 * of the food item selected for the food selector region and added in the food listing region
 */
public class SelectedFoodItemInfoPane {

    private FoodItem selectedItem; //food item selected from the food selector region
    private Button deleteButton; //delete button that will delete currently listed food item from the food listing region
    private final String DELETE_BUTTON_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "delete-bin-white.png"; //directroy for the image of delete button
    private ImageView deleteButtonImage; //image that will be displayed in the deleteButton
    private static ListView<Node> parentListView; //Listview that is used to display/list currently selected food item
    private Pane currentFoodInfoPane; //Pane holds the information (name, price and delete button) of the food item selected for the food selector region and added in the food listing region
    private static Label totalPriceLabel; //Label that tracks the total price of all the items available in the food listing region

    public SelectedFoodItemInfoPane(FoodItem selectedItem, ListView<Node> parentList, Label totalPrice){
        this.selectedItem = selectedItem;
        this.deleteButtonImage = new ImageView(DELETE_BUTTON_IMG_DIR);
        this.deleteButton = CustomizedButton.menuButton(deleteButtonImage, 30, 30);
        parentListView = parentList;
        this.currentFoodInfoPane = foodItemInfo();
        totalPriceLabel = totalPrice;
    }
    
    /**
     * A method that builds the pane that holds the information (name, price and delete button)
     * of the food item selected for the food selector region and added in the food listing region
     * @return Pane holds the information of the food item selected for the food selector region and added in the food listing region
     */
    private Pane foodItemInfo(){
        BorderPane foodInfo = new BorderPane();
       
        Label foodName = new Label(selectedItem.getName());
        foodName.setTextFill(Color.valueOf("#01008c"));
        foodName.setFont(Font.font("Verdana", FontWeight.SEMI_BOLD, 12));

        Label foodPrice = new Label(String.valueOf(selectedItem.getPrice()));
        foodPrice.setTextFill(Color.valueOf("#01008c"));
        foodPrice.setFont(Font.font("Verdana", FontWeight.SEMI_BOLD, 12));

        
        HBox priceAndDelButton = new HBox();
        priceAndDelButton.setSpacing(30);
        priceAndDelButton.getChildren().addAll(foodPrice, deleteButton);
        priceAndDelButton.setAlignment(Pos.CENTER);

        foodInfo.setLeft(foodName);
        foodInfo.setRight(priceAndDelButton);

        BorderPane.setAlignment(foodName, Pos.CENTER);
        BorderPane.setAlignment(priceAndDelButton, Pos.CENTER);
        
        /**
         * Event handler that handles the removal of selected food item from the listing
         * area as well as track the total price change after removal 
         */
        deleteButton.setOnAction(e->{
            parentListView.getItems().remove(currentFoodInfoPane);
            
            double totalPrice = Double.parseDouble(totalPriceLabel.getText());
            totalPrice -= selectedItem.getPrice();

            totalPriceLabel.setText(String.format("%.2f", totalPrice));
            parentListView.scrollTo(parentListView.getItems().size() - 1);
        });

        return foodInfo;
    }

    public Pane getSelectedFoodInfoPane(){
        return currentFoodInfoPane;
    }

}