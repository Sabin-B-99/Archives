package mazerunner.gui;

import mazerunner.engine.Position;
import mazerunner.engine.Traps;

import javafx.scene.image.ImageView;
import java.io.File;

/**
 * Class that extends the Traps class so that it can add hold
 * an image of a trap that wlll be displayed in the game GUI.
 */
public class TrapGUI extends Traps{

    private static final String TRAP_IMG_DIR = "file:" + System.getProperty("user.dir") + File.separator + "img" + File.separator + "bearTrap.png";
    private final ImageView TRAP_IMG = new ImageView(TRAP_IMG_DIR);

    public TrapGUI(Position trapPosition) {
        super(trapPosition);
    }

    /**
     * Method that returns an image of the trap object
     * @return ImageView containg image of the trap
     */
    public ImageView get_TRAP_IMG(){
        return this.TRAP_IMG;
    }
    
}
