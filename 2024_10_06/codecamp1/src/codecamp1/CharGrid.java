package codecamp1;

public class CharGrid {
	private char[][] grid;
	
	/**
	 * Constructs a new CharGrid with the given grid.
	 * Does not make a copy.
	 * @param grid
	 */
	public CharGrid(char[][] grid) {
		this.grid = grid;
	}
	
	/**
	 * Returns the area for the given char in the grid. (see handout)
	 * @param ch char to look for
	 * @return area for given char
	 */
	public int charArea(char ch) {
		int r = grid.length, c = grid[0].length;
		int rmin=r, rmax=-1, cmin=c, cmax=-1;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (grid[i][j] == ch) {
					if (i < rmin)
						rmin = i;
					if (i > rmax) 
						rmax = i;
					if (j < cmin)
						cmin = j;
					if (j > cmax)
						cmax = j;
				}
			}
		}
		
        // If the character is not found, return 0
        if (rmax == -1 || cmax == -1) {
            return 0;
        }
		return (rmax - rmin + 1) * (cmax - cmin + 1);
	}
}
