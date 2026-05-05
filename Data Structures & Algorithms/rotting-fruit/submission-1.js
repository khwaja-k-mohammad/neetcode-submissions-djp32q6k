class Solution {
    /**
     * @param {number[][]} grid
     * @return {number}
     */
    orangesRotting(grid) {

        let queue = [], count = 0, totalTime = 0;
        const numRows = grid.length, numCols = grid[0].length;

        for(let r = 0; r < numRows; r++)
        {
            for(let c = 0; c < numCols; c++)
            {
                if(grid[r][c] == 1) count+=1;
                else if(grid[r][c] == 2) queue.push([r, c, 0]);
            }
        }

        while(queue.length > 0 && count)
        {
            const [ currRow, currCol, time ] = queue.shift();

            const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];

            for(const [r, c] of dirs)
            {
                const nextRow = currRow + r;
                const nextCol = currCol + c;

                if(nextRow < 0 || nextRow >= numRows || nextCol < 0 || nextCol >= numCols || grid[nextRow][nextCol] !== 1) continue;

                grid[nextRow][nextCol] = 2;
                count -= 1;
                totalTime = time + 1;
                queue.push([nextRow, nextCol, time + 1]);
            }
        }

        return count > 0 ? -1 : totalTime;
    }
}
