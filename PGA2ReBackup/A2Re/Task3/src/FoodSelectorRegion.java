
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;

/**
 * A Singelton class that is used to build a Pane that will hold all the required nodes
 * that will be available in (and used to control) the food selector (food menu) region of this EPOS.
 */
public final class FoodSelectorRegion {
    private static Pane foodMenuPane = FoodMenuPane.menuPane("m"); //Pane that displays all the available food menu in the EPOS
    private static VBox foodSelectorRegionPane = new VBox(); //Pane that will hold all the required nodes that will be available in the food selector region
    
    private FoodSelectorRegion(){
    }

    public static Pane foodSelectorPane(){
        HBox foodTypeControlButtons = foodTypesControlBox();
        HBox priceConfirmButtons = priceConformationButtons();
        foodSelectorRegionPane.getChildren().addAll(foodTypeControlButtons, foodMenuPane, priceConfirmButtons);
        return foodSelectorRegionPane;
    }

    /**
     * A static method that builds a Pane with all the necessary buttons to switch between different types (Mains,Startres and Desserts) 
     * of food items available in the EPOS.
     * @return Pane with all the necessary buttons to switch between different types of food items
     */
    private static HBox foodTypesControlBox(){
        HBox foodTypeControlButtonBox = new HBox();
        foodTypeControlButtonBox.setPadding(new Insets(10,10,10,10));
        foodTypeControlButtonBox.setSpacing(20);
        foodTypeControlButtonBox.setStyle("-fx-background-color: #ffffff");
        
        Button startersButton = CustomizedButton.menuControlButton("Starters", 140, 10, "#01008c" , 18);
        Button mainsButton = CustomizedButton.menuControlButton("Mains", 140, 10, "#01008c" , 18);
        Button dessertsButton = CustomizedButton.menuControlButton("Desserts", 140, 10, "#01008c" , 18);

        foodTypeControlButtonBox.getChildren().addAll(startersButton,mainsButton,dessertsButton);

        startersButton.setOnAction(e ->{
            foodSelectorRegionPane.getChildren().remove(foodMenuPane);
            foodMenuPane = FoodMenuPane.menuPane("s");
            foodSelectorRegionPane.getChildren().add(1, foodMenuPane);
        });

        mainsButton.setOnAction(e ->{
            foodSelectorRegionPane.getChildren().remove(foodMenuPane);
            foodMenuPane = FoodMenuPane.menuPane("m");
            foodSelectorRegionPane.getChildren().add(1, foodMenuPane);
        });

        dessertsButton.setOnAction(e ->{
            foodSelectorRegionPane.getChildren().remove(foodMenuPane);
            foodMenuPane = FoodMenuPane.menuPane("d");
            foodSelectorRegionPane.getChildren().add(1, foodMenuPane);
        });

        return foodTypeControlButtonBox;
    }

    /**
     * A static method that is used to build a Pane that contains all the buttons required 
     * for the final confirmation after selecting desired food item from the food menu region
     * of the EPOS. These buttons include the option to cancel, see discount etc. after 
     * selecting all the food items from the list. 
     * @return Pane that contains all the buttons required for the final confirmation after selecting desired food item from the food menu region of the EPOS
     */
    private static HBox priceConformationButtons(){
        HBox priceConfirmBox = new HBox();
        priceConfirmBox.setPadding(new Insets(10,10,10,15));
        priceConfirmBox.setSpacing(20);
        priceConfirmBox.setStyle("-fx-background-color: #ffffff");

        Button discountButton = CustomizedButton.menuControlButton("Discount", 100, 0, "#aadae8" , 18);
        Button settleButton = CustomizedButton.menuControlButton("Settle", 100, 0, "#ffa400" , 18);
        Button finishButton = CustomizedButton.menuControlButton("Finish", 100, 0, "#8fed90" , 18);
        Button cancelButton = CustomizedButton.menuControlButton("Cancel", 100, 0, "#f88071" , 18);

        priceConfirmBox.getChildren().addAll(discountButton,settleButton,finishButton,cancelButton);
        
        return priceConfirmBox;
    }
}
