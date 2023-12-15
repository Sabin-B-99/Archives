
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

/**
 * A class that will handle the event when the menu button (FoodItem.button) is pressed to 
 * select a food. This class will add the selected food item to the food listing area
 * as well as track the total price
 */
public class FoodMenuButtonEventHandler implements EventHandler<ActionEvent>{
    private FoodItem item; //FoodItem which is selected for the menu i.e, item whose button is pressed
    SelectedFoodItemInfoPane foodInfo; //Object that holds/builds pane that will display selected food item's info i.e, name, price and delete butons 
    private ListView<Node> orderList; //Node in which the selected food item will be added
    private static Label totalPriceLabel; //Node that tracks the total price for all the food selected/added in the food listing area

    public FoodMenuButtonEventHandler(FoodItem item,ListView<Node> orderList, Label totalPrice){
        this.item = item;
        this.orderList = orderList;
        totalPriceLabel = totalPrice;
    }

    /**
     * Hander method that handles the button click event
     */
    @Override
    public void handle(ActionEvent e) {
        this.foodInfo = new SelectedFoodItemInfoPane(item, orderList, totalPriceLabel);
        orderList.getItems().add(foodInfo.getSelectedFoodInfoPane());
        orderList.scrollTo(orderList.getItems().size() - 1);
        
        double totalPrice = Double.parseDouble(totalPriceLabel.getText());
        totalPrice += item.getPrice();

        totalPriceLabel.setText(String.format("%.2f", totalPrice));
    }
}
