import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Position;

public class TestPosition {
    Position pos = new Position(2,3);

    @Test
    public void testGetX(){
        int expected = 2;
        assertEquals(expected, pos.getX());
    }

    @Test
    public void testGetY(){
        int expected = 3;
        assertEquals(expected, pos.getY());
    }
}
