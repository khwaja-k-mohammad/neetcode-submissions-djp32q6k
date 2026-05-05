class Solution {
    /**
     * @param {number[][]} grid
     */

    queue = [];

    markGrid(grid, row, col, numRows, numCols)
    {
        this.queue.push([ row, col, 0 ]);

        while(this.queue.length > 0)
        {
            const [currRow, currCol, steps] = this.queue.shift();

            grid[currRow][currCol] = Math.min(grid[currRow][currCol], steps + 1);

            const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];

            for(const [r, c] of dir)
            {
                if(
                    (currRow + r >= 0 && currRow + r < numRows) && 
                    (currCol + c >=0 && currCol + c < numCols) &&
                    (grid[currRow + r][currCol +c] > 0)
                ) {
                    if(grid[currRow + r][currCol + c] > grid[currRow][currCol] + 1)
                    {
                        this.queue.push([ currRow + r, currCol + c, grid[currRow][currCol]]);
                    }
                }
            }  
        } 
    }

    islandsAndTreasure(grid) {

        const numRows = grid.length, numCols = grid[0].length;

        for(let i=0;i<numRows;i++)
        {
            for(let j=0;j<numCols;j++)
            {
                if(grid[i][j] == 0)
                {
                    this.markGrid(grid, i, j, numRows, numCols, 0);
                }
            }
        }

        return grid;
    }
}
