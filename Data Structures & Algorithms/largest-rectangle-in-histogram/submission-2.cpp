class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> s;
        heights.push_back(0);
        int totalBars = heights.size(), maxArea = 0;

        for(int i=0;i<totalBars;i++)
        {
            if(s.empty()) s.push(i);
            else {
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    int lastIndex = s.top();
                    s.pop();

                    int leftSmaller = s.empty() ? -1 : s.top();
                    maxArea = max(maxArea, heights[lastIndex] * (i - leftSmaller - 1));
                }

                s.push(i);
            }
        }

        return maxArea;
    }
};
