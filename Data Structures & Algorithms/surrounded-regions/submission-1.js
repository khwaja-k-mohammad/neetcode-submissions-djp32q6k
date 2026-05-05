class Solution {
    /**
     * @param {character[][]} board
     * @return {void} Do not return anything, modify board in-place instead.
     */
    solve(board) {

        let numRows = board.length, numCols = board[0].length;
        let queue = [];

        for(let r = 0; r < numRows; r++)
        {
            for(let c = 0; c < numCols; c++)
            {
                if(board[r][c] == 'O' && (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1))
                {
                    queue.push([r,c]);
                    board[r][c] = 'A';
                }
            }
        }

        while(queue.length > 0)
        {
            const [currRow, currCol] = queue.shift();

            const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];

            for(const [r,c] of dirs)
            {
                const nextRow = currRow + r;
                const nextCol = currCol + c;

                if(nextRow >= 0 &&  nextRow < numRows && nextCol >=0 && nextCol < numCols && board[nextRow][nextCol] == 'O')
                {
                    board[nextRow][nextCol] = 'A';
                    queue.push([nextRow, nextCol]);
                }
            }
        }

        for(let r = 0; r < numRows; r++)
        {
            for(let c = 0; c < numCols; c++)
            {
                if(board[r][c] == 'A') board[r][c] = 'O';
                else if(board[r][c] == 'O') board[r][c] = 'X';
            }
        }

        return board;
    }
}
