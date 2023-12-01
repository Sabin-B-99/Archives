import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Map;

public class TestMap {
    Map map = new Map(10);
    
    @Test
    public void testGetMapSize(){
        assertEquals(10, map.getMapSize());
    }

    @Test
    public void testGetExitPositionCode(){
        assertEquals(4, Map.getExitPositionCode());
    }


}
