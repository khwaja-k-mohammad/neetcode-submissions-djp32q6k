class Solution {

    queue = [];

    countIslands(grid, row, col, numRows, numCols)
    {
        this.queue.push([ row, col ]);
        grid[row][col] = "0";

        let totalCells = 0;

        while(this.queue.length > 0)
        {
            const [currRow, currCol] = this.queue.shift();

            totalCells += 1;
            
            const dir = [[-1, 0], [0, 1], [1, 0], [0, -1]];

            for(let i=0;i<4;i++)
            {
                const nextRow = currRow + dir[i][0];
                const nextCol = currCol + dir[i][1];

                if(
                    (nextRow >= 0 && nextRow < numRows) &&
                    (nextCol >= 0 && nextCol < numCols) &&
                    (grid[nextRow][nextCol] == "1")
                ) {
                    grid[nextRow][nextCol] = "0";
                    this.queue.push([ nextRow, nextCol ]);
                }
            }
        }

        return totalCells;
    }

    maxAreaOfIsland(grid) {

        const numRows = grid.length, numCols = grid[0].length;
        let result = 0;

        for(let i=0;i<numRows;i++)
        {
            for(let j=0;j<numCols;j++)
            {
                if(grid[i][j] == "1")
                {
                    result = Math.max(result, this.countIslands(grid, i, j, numRows, numCols));
                }
            }
        }

        return result;
    }
}
