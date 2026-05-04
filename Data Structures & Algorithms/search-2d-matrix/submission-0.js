class Solution {
    /**
     * @param {number[][]} matrix
     * @param {number} target
     * @return {boolean}
     */
    searchMatrix(matrix, target) {

        const numRows = matrix.length;
        const numCols = matrix[0].length;

        let left = 0, right = numRows * numCols - 1;

        while(left <= right)
        {
            const mid = left + Math.floor((right - left)/2);

            const row = Math.floor(mid / numCols);
            const col = mid % numCols;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
}
