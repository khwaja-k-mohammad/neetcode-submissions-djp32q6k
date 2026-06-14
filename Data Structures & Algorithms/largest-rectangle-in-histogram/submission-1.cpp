class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int totalBars = heights.size();
        vector<int> smallerToLeft(totalBars);
        vector<int> smallerToRight(totalBars);

        smallerToLeft[0] = -1;
        smallerToRight[totalBars - 1] = totalBars;

        for(int i=1;i<totalBars;i++)
        {
            int p = i - 1;
            while(p >= 0 && heights[p] >= heights[i])
                p = smallerToLeft[p];

            smallerToLeft[i] = p;
        }

        for(int i=totalBars - 2; i>=0; i--)
        {
            int p = i + 1;
            while(p < totalBars && heights[p] >= heights[i])
                p = smallerToRight[p];

            smallerToRight[i] = p;
        }

        int maxArea = 0;
        for(int i=0;i<totalBars;i++)
        {
            maxArea = max(maxArea, heights[i] * (smallerToRight[i] - smallerToLeft[i] - 1));
        }

        return maxArea;
    }
};
