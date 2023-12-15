package mazerunner.gui;

import mazerunner.engine.Coins;
import mazerunner.engine.Position;

import javafx.scene.image.ImageView;
import java.io.File;

/**
 * Class that extends the Coins class so that it can add hold
 * an image of a coin that wlll be displayed in the game GUI.
 */
public class CoinGUI extends Coins{
    private static final String COIN_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "img" + File.separator + "coin.png";
    private final ImageView COIN_IMG = new ImageView(COIN_IMG_DIR);

    public CoinGUI(Position coinPosition) {
        super(coinPosition);
    }

    /**
     * Method that returns an image of the coin object
     * @return ImageView containg image of a coin
     */
    public ImageView get_COIN_IMG(){
        return this.COIN_IMG;
    }
}
