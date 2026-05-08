class Solution {
    /**
     * @param {number[][]} matrix
     * @return {number[]}
     */
    spiralOrder(matrix) {
        
        let m = matrix.length, n = matrix[0].length;

        let rs = 0, re = m-1, cs = 0, ce = n-1;

        const result = [];
        while(rs <= re && cs <= ce)
        {
            for(let i=cs;i<=ce;i++)
            {
                result.push(matrix[rs][i]);
            }
            rs+=1;

            if(rs > re || cs > ce) break;

            for(let i=rs; i<=re; i++)
            {
                result.push(matrix[i][ce]);
            }
            ce-=1;

            if(rs > re || cs > ce) break;

            for(let i=ce; i>=cs; i--)
            {
                result.push(matrix[re][i]);
            }
            re-=1;

            if(rs > re || cs > ce) break;

            for(let i=re; i>=rs; i--)
            {
                result.push(matrix[i][cs]);
            }
            cs+=1;
        }

        return result;
    }
}
