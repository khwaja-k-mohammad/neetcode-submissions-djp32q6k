class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */

    countIslands(grid, row, col, numRows, numCols)
    {
        grid[row][col] = 0;
        
        const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];

        for(let i=0;i<4;i++)
        {
            const nextRow = row + dir[i][0];
            const nextCol = col + dir[i][1];

            if(
                (nextRow >= 0 && nextRow < numRows) &&
                (nextCol >= 0 && nextCol < numCols) &&
                (grid[nextRow][nextCol] == 1)
            ) {
                this.countIslands(grid, nextRow, nextCol, numRows, numCols);
            }
        }
    }

    numIslands(grid) {

        const numRows = grid.length, numCols = grid[0].length;
        let count = 0;

        for(let i=0;i<numRows;i++)
        {
            for(let j=0;j<numCols;j++)
            {
                if(grid[i][j] == 1)
                {
                    count += 1;
                    this.countIslands(grid, i, j, numRows, numCols);
                }
            }
        }

        return count;
    }
}
