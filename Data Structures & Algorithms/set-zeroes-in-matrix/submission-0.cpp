class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int numRows = matrix.size(), numCols = matrix[0].size(), rfr = 0, rfc = 0;

        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<numCols;j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0) rfr = 1;
                    if(j == 0) rfc = 1;

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1;i<numRows;i++)
        {
            for(int j=1;j<numCols;j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(rfr) {
            for(int i=0;i<numCols;i++) matrix[0][i] = 0;
        }

        if(rfc) {
            for(int i=0;i<numRows;i++) matrix[i][0] = 0;
        }
    }
};
