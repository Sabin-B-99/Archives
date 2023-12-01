package mazerunner.gui;

import mazerunner.engine.Apples;
import mazerunner.engine.Position;

import javafx.scene.image.ImageView;
import java.io.File;

/**
 * Class that extends the Apples class so that it can add hold
 * an image of an apple that wlll be displayed in the game GUI.
 */
public class AppleGUI extends Apples{

    private static final String APPLE_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "img" + File.separator + "apple.png";
    private final ImageView APPLE_IMG = new ImageView(APPLE_IMG_DIR);
    public AppleGUI(Position applePosition) {
        super(applePosition);
    }
    
    /**
     * Method that returns an image of the apple object
     * @return ImageView containg image of the apple
     */
    public ImageView get_APPLE_IMG(){
        return this.APPLE_IMG;
    }
}
