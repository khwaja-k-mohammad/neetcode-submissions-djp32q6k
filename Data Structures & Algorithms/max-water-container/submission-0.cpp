class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int len = heights.size();

        int leftIndex = 0, rightIndex = len - 1;

        int maxArea = 0;
        while(leftIndex < rightIndex)
        {
            maxArea = max(maxArea, (rightIndex - leftIndex) * min(heights[leftIndex], heights[rightIndex]));
            
            if(heights[leftIndex] < heights[rightIndex])
            {
                leftIndex += 1;
            }
            else if(heights[leftIndex > heights[rightIndex]]) {
                rightIndex -= 1;
            }
            else {
                leftIndex += 1;
                rightIndex -= 1;
            }
        }

        return maxArea;
    }
};
