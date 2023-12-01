import java.io.File;
import java.util.ArrayList;


import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

/**
 * Class that is used to build the Pane that holds all the buttons with images of food items 
 * that will be displayed in the food menu of this EPOS interface
 */
public final class FoodMenuPane {
    
    /**
     * Strings that holds the info for path of images of all the food items that will be displayed in the 
     * food menu region of this EPOS
     */
    private static final String D_BROWNIE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "brownie.png";
    private static final String D_BRUSHETTA_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "brushetta.png";
    private static final String D_STRAWB_SHORTCAKE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "strawberry-shortcake.png";
    private static final String D_TIRAMISU_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "tiramisu.png";
    private static final String D_TROPIC_ICE_CRM_SUNDAE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "tropical-ice-cream-sundae.png";
    private static final String D_CHOCOLATE_CAKE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "chocolate-cake.png";
    private static final String D_PROFITEROLE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "profiterole.png";
    private static final String D_RSPB_CHEESCAKE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "raspberry-cheesecake.png";
    private static final String D_STRAWB_GATEAUX_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "strawberry-gateaux.png";
    private static final String D_NY_CHEESE_CAKE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "new-york-cheesecake.png";
    private static final String D_GREEK_SALAD_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "greek-salad.png";
    private static final String M_TOASTIE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "toastie.png";
    private static final String M_RAVIOLI_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "ravioli.png";
    private static final String M_CHICKEN_ESC_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "chicken-escalope.png";
    private static final String M_FISH_FINGERS_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "fish-fingers.png";
    private static final String M_FISH_PLATTER_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "fish-platter.png";
    private static final String M_SPAGHETTI_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "spaghetti.png";
    private static final String M_TUNA_STEAK_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "tuna-steak.png";
    private static final String M_WARM_SALAD_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "warm-salad.png";
    private static final String M_PASTA_N_SAUCE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "pasta-and-sauce.png";
    private static final String S_FRIED_MUSHROOMS_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "fried-mushrooms.png";
    private static final String S_GARLIC_BREAD_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "garlic-bread.png";
    private static final String S_MUSSELS_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "mussels.png";
    private static final String S_FRESH_FRUIT_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "fresh-fruit.png";
    private static final String S_CALIMARI_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "calimari.png";
    private static final String S_OLIVES_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "olives.png";
    private static final String S_PEPPERS_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "peppers.png";
    private static final String S_SAVOURY_PASTRIES_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "savoury-pastries.png";
    private static final String S_SOUP_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "icons" + File.separator + "soup.png";
    
    
    
    /**
     * ArrayList that holds information of all the food items to be displayed in the menu of the EPOS
     */
    private static ArrayList<FoodItem> allDeserts = new ArrayList<>();
    private static ArrayList<FoodItem> allMains = new ArrayList<>();
    private static ArrayList<FoodItem> allStarters = new ArrayList<>();
    

    private static ListView<Node> orderList = new ListView<>(); //Node that is used as the listing area to list the selected food item from the list
    private static Label totalPriceLabel = new Label("0.00"); //Node that is used to track the total price of all the food items in the listing area


    private FoodMenuPane(){
    }


    /**
     * A static method to build a Pane that will hold and display all the buttons with images of 
     * different types of food items (Starters, Mains, Desserts) that are available in the menu of
     * this EPOS system
     * @param flag flag to specify the type of food item to be displayed in the menu of this EPOS. Flag: 'm' for Mains, 'd' for desserts, anything else for Starters 
     * @return Pane that will hold and display all the buttons with images of different types of food items
     */
    public static Pane menuPane(String flag){
        GridPane menu = new GridPane();
        menu.setPadding(new Insets(5, 5, 5, 5));
        menu.setHgap(50);
        menu.setVgap(10);
        menu.setStyle("-fx-background-color: #ffffff");
        menu.setPrefSize(400, 400);

        addMainsToList();
        addDessertsToList();
        addStartersToList();
        initializeFoodOrderListProperties();
        initializeTotalPriceLabel();


        FoodItem item = null;
        int itemIdex = 0;
        Button button = null;

        for (int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++){
                
                if(flag.equals("m")){
                    item = allMains.get(itemIdex);
                }else if(flag.equals("d")){
                    item = allDeserts.get(itemIdex);
                }else{
                    item = allStarters.get(itemIdex);
                }

                button = item.getButton();
                button.setOnAction(new FoodMenuButtonEventHandler(item,orderList, totalPriceLabel)); //action handler when a food is selected from the menu
                menu.add(button, col, row);
                itemIdex++;
            }
        }
        return menu;
    }

    
    public static ListView<Node> getOrderListingPane(){
        return orderList;
    }

    public static Label getTotalPricLabel(){
        return totalPriceLabel;
    }

    
    /**
     * Static method to add all the available Desserts food types to the list of food items
     */
    private static void addDessertsToList(){
        allDeserts.add(new FoodItem("Brownie", 4.99, D_BROWNIE_IMG_DIR));
        allDeserts.add(new FoodItem("Brushetta", 4.69, D_BRUSHETTA_IMG_DIR));
        allDeserts.add(new FoodItem("Strawberry Shortcake", 5.49, D_STRAWB_SHORTCAKE_IMG_DIR));
        allDeserts.add(new FoodItem("Tiramisu", 7.99, D_TIRAMISU_IMG_DIR));
        allDeserts.add(new FoodItem("Greek Salad", 6.99, D_GREEK_SALAD_IMG_DIR));
        allDeserts.add(new FoodItem("Tropical Ice Cream Sundae", 9.99, D_TROPIC_ICE_CRM_SUNDAE_IMG_DIR));
        allDeserts.add(new FoodItem("Chocolate Cake", 6.99, D_CHOCOLATE_CAKE_IMG_DIR));
        allDeserts.add(new FoodItem("Profitrole", 5.09, D_PROFITEROLE_IMG_DIR));
        allDeserts.add(new FoodItem("Raspberry Cheesecake", 3.99, D_RSPB_CHEESCAKE_IMG_DIR));
        allDeserts.add(new FoodItem("Strawberry Gateaux", 10.99, D_STRAWB_GATEAUX_IMG_DIR));
        allDeserts.add(new FoodItem("New York Cheesecake", 6.99, D_NY_CHEESE_CAKE_IMG_DIR));
    }


    /**
     * Static method to add all the available Mains food types to the list of food items
     */
    private static void addMainsToList(){
        allMains.add(new FoodItem("Chicken Escalope", 24.69, M_CHICKEN_ESC_IMG_DIR));
        allMains.add(new FoodItem("Fish Fingers", 25.49, M_FISH_FINGERS_IMG_DIR));
        allMains.add(new FoodItem("Pasta and Sauce", 25.09, M_PASTA_N_SAUCE_IMG_DIR));
        allMains.add(new FoodItem("Fish Platter", 27.99, M_FISH_PLATTER_IMG_DIR));
        allMains.add(new FoodItem("Ravioli", 28.99, M_RAVIOLI_IMG_DIR));
        allMains.add(new FoodItem("Toastie", 24.59, M_TOASTIE_IMG_DIR));
        allMains.add(new FoodItem("Spaghetti", 23.99, M_SPAGHETTI_IMG_DIR));
        allMains.add(new FoodItem("Tuna Steak", 25.09, M_TUNA_STEAK_IMG_DIR));
        allMains.add(new FoodItem("Warm Salad", 23.99, M_WARM_SALAD_IMG_DIR));
    }

    /**
     * Static method to add all the available Starters food types to the list of food items
     */
    private static void addStartersToList(){
        allStarters.add(new FoodItem("Mussels", 14.99, S_MUSSELS_IMG_DIR));
        allStarters.add(new FoodItem("Fresh Fruit", 14.69, S_FRESH_FRUIT_IMG_DIR));
        allStarters.add(new FoodItem("Calimari", 15.49, S_CALIMARI_IMG_DIR));
        allStarters.add(new FoodItem("Olives", 17.99, S_OLIVES_IMG_DIR));
        allStarters.add(new FoodItem("Peppers", 14.59, S_PEPPERS_IMG_DIR));
        allStarters.add(new FoodItem("Savoury Pastries", 19.99, S_SAVOURY_PASTRIES_IMG_DIR));
        allStarters.add(new FoodItem("Soup", 16.99, S_SOUP_IMG_DIR));
        allStarters.add(new FoodItem("Fried Mushroom", 14.59, S_FRIED_MUSHROOMS_IMG_DIR));
        allStarters.add(new FoodItem("Garlic Bread", 19.99, S_GARLIC_BREAD_IMG_DIR));
    }

    /**
     * Static method to set the properties and style of the Listing area that will list 
     * all the selected food items from the menu list.
     */
    private static void initializeFoodOrderListProperties(){
        orderList.setOrientation(Orientation.VERTICAL);
        orderList.setFixedCellSize(50);
        orderList.setStyle("-fx-control-inner-background-alt: #ffffff");
        orderList.setPrefWidth(400);;
        orderList.setPrefHeight(400);
        orderList.setFocusTraversable(false);
    }

    /**
     * Static method to set the properties and style of the Label that will track 
     * the total price of all the selected food items from the menu list.
     */
    private static void initializeTotalPriceLabel(){
        totalPriceLabel.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
        totalPriceLabel.setTextFill(Color.WHITE);
    }
}
