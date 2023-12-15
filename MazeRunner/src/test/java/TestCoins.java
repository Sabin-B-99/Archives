import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import mazerunner.engine.Coins;
import mazerunner.engine.Position;

public class TestCoins {
    Position pos = new Position(8,6);
    Coins coin = new Coins(pos);

    @Test
    void testGetCoinPosition(){
        assertEquals(pos, coin.getCoinPosition());
    }

    @Test
    void testCoinCode(){
        assertEquals(Coins.COIN_CODE, Coins.getCoinCode());
    }
}
