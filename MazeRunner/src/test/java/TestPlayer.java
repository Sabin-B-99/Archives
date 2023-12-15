import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Player;
import mazerunner.engine.Position;

public class TestPlayer {
    Player p = new Player();
    Position pos = new Position(4,5);

    private class PlayerProtectedMethodTest extends Player{
        public boolean playerHitsBoundary(Position newPos){
            return super.playerHitsBoundary(newPos);
        }
    }

    @Test 
    public void testGetPlayerCode(){
        assertEquals(0, Player.getPlayerCode());
    }

    @Test
    public void testGetPlayerPosition(){
        p.setPlayerPos(pos);
        assertEquals(pos, p.getPlayerPos());
    }
    @Test
    public void testGetStamina(){
        p.setStamina(11);
        assertEquals(11, p.getStamina());
    }    

    @Test
    public void testIsPlayerDead(){
        p.setStamina(4);
        assertEquals(false, p.isPlayerDead());

        p.setStamina(0);
        assertEquals(true, p.isPlayerDead());

        p.setStamina(-3);
        assertEquals(true, p.isPlayerDead());
    }

    @Test
    public void testChangePlayerPosition(){
        Position posWTestTrue = new Position(0,0);
        Position playerHitWallOnA = new Position(0,0);
        Position posSTestTrue = new Position (3,4);
        Position posATestTrue = new Position(5,6);
        Position posDTestTrue = new Position(7,8);

        p.setPlayerPos(posWTestTrue);
        assertEquals(true, p.changePlayerPosition("w"));
        //player hits boundary
        p.setPlayerPos(playerHitWallOnA);
        assertEquals(false, p.changePlayerPosition("a"));

        p.setPlayerPos(posSTestTrue);
        assertEquals(true, p.changePlayerPosition("s"));

        p.setPlayerPos(posATestTrue);
        assertEquals(true, p.changePlayerPosition("a"));

        p.setPlayerPos(posDTestTrue);
        assertEquals(true, p.changePlayerPosition("d"));

        assertEquals(false, p.changePlayerPosition("f"));
    }

    @Test
    public void testPlayerHitsBoundary(){
        Position hitWallPos = new Position(0, 13);
        Position hitWallPosition = new Position(-1,2);
        Position dosentHitwallPos = new Position(3,4);

        PlayerProtectedMethodTest player = new PlayerProtectedMethodTest();

        assertEquals(true, player.playerHitsBoundary(hitWallPos));
        assertEquals(true, player.playerHitsBoundary(hitWallPosition));
        assertEquals(false, player.playerHitsBoundary(dosentHitwallPos));
    }

    @Test
    public void testPlayerHasCoin(){
        p.giveCoinToPlayer(pos);
        assertEquals(true, p.playerHasCoins());

        p.removeCoinFromPlayer();
        assertEquals(false, p.playerHasCoins());
    }
}
