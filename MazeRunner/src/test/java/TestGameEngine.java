import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.GameEngine;
import mazerunner.engine.Position;
public class TestGameEngine {

    private class GameEngineProtectedMethodTest extends GameEngine{

        private GameEngineProtectedMethodTest(int mapSize) {
            super(mapSize);
        }

        public int typeOfObjectHit(Position pos, int[][] mapGrid){
            return super.typeOfObjectHit(pos, mapGrid);
        }

        public boolean checkIfPlayerHitsGameObject(Position pos, int[][] mapGrid){
            return super.checkIfPlayerHitsGameObject(pos, mapGrid);
        }        
    }

    GameEngineProtectedMethodTest ge = new GameEngineProtectedMethodTest(10);

    @Test
    void testGetDifficulty() {
        assertEquals(5, GameEngine.getDifficulty());
    }

    @Test 
    void testTypeOfObjectHit(){
        int[][] mapGrid = new int[10][10];
        mapGrid[0][5] = 4;
        mapGrid[0][0] = -1;
        
        Position pos = new Position(0,5);
        Position otherPos = new Position(0,0);
        
        assertEquals(4, ge.typeOfObjectHit(pos, mapGrid));
        assertEquals(-1, ge.typeOfObjectHit(otherPos, mapGrid));
    }
    @Test
    void testCheckIfPlayerHitsGameObject(){
        int[][] mapGrid = new int[10][10];
        mapGrid[0][5] = 4;
        mapGrid[0][0] = -1;

        Position pos = new Position(0,5);
        Position otherPos = new Position(0,0);
        assertEquals(true, ge.checkIfPlayerHitsGameObject(pos, mapGrid));
        assertEquals(false, ge.checkIfPlayerHitsGameObject(otherPos, mapGrid));
    }
}