import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Apples;
import mazerunner.engine.Position;

public class TestApples {
    Position pos = new Position(2,3);
    Apples apple = new Apples(pos);

    @Test
    void testGetApplePosition(){
        assertEquals(pos, apple.getApplePosition());
    }

    @Test
    void testAppleCode(){
        assertEquals(Apples.APPLE_CODE, Apples.getAppleCode());
    }
}
