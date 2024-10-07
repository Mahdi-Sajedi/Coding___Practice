package codecamp1;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class CharGridTest {

	@Test
	public void test1() {
		char[][] grid = {
            {'a', 'a', 'b'},
            {'a', 'a', 'b'},
            {'b', 'b', 'b'}
        };
        CharGrid charGrid = new CharGrid(grid);
        int area = charGrid.charArea('a');
        assertEquals(4, area); // Area of 'a' should be 4 (2x2)
        
        // Print the output to console
        System.out.println("Test1 passed for char 'a'. Calculated area: " + area);
	}
	
	@Test
	public void test2() {
		char[][] grid = new char[][] {
			{'c', 'a', ' '},
			{'b', ' ', 'b'},
			{' ', ' ', 'a'}
		};
		
		CharGrid cg = new CharGrid(grid);
		
		int area1, area2, area3;
		area1 = cg.charArea('a');
		area2 = cg.charArea('b');
		area3 = cg.charArea('c');
		
		assertEquals(6, area1);
		assertEquals(3, area2);
		assertEquals(1, area3);
		System.out.println("Test2 passed for char 'a'. Calculated area: " + area1);
		System.out.println("Test2 passed for char 'b'. Calculated area: " + area2);
		System.out.println("Test2 passed for char 'c'. Calculated area: " + area3);
	}

}
