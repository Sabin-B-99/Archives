import javafx.scene.control.Button;
import javafx.scene.image.ImageView;

/**
 * A class that holds information about a specific type of food in the food-menu of the 
 * program
 */
public class FoodItem {
    private String name; //name of food in the menu
    private double price; //price of food in the menu
    private ImageView image; //Image of the food that will be displayed in the menu
    private Button button; //Button associated with this food item which will be used in the user interface to select this food item


    public FoodItem(String name, double price, String imageDir){
        this.name = name;
        this.price = price;
        this.image = new ImageView(imageDir);
        button = CustomizedButton.menuButton(this.image, 110, 110);
    }

    public String getName(){
        return name;
    }

    public double getPrice(){
        return price;
    }

    public ImageView getImage(){
        return image;
    }

    public Button getButton(){
        return button;
    }

}
