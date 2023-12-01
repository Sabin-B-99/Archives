import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Position;
import mazerunner.engine.Traps;

public class TestTraps {
    Position pos = new Position(6,7);
    Traps trap = new Traps(pos);

    @Test
    void testGetTrapPosition(){
        assertEquals(pos, trap.getTrapPosition());
    }

    @Test
    void testTrapsCode(){
        assertEquals(Traps.TRAP_CODE, Traps.getTarpsCode());
    }
}
