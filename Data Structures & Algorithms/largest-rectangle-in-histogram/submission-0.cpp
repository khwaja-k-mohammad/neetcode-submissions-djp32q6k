class Solution {
public:
    vector<int> calculateSmallest(vector<int> &heights, int direction)
    {
        int len = heights.size();
        stack<int> s;
        vector<int> smallest(len);

        int start = direction ? len - 1 : 0;
        int end =  direction ? -1 : len;
        int step = direction ? -1 : 1;

        for(int i=start;i!=end;i+=step)
        {
            if(s.empty()) {
                s.push(i);
                smallest[i] = -1;
            }
            else if(heights[s.top()] < heights[i]) {
                smallest[i] = s.top();
                s.push(i);
            }
            else {
                while(!s.empty() && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }

                smallest[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
        }

        return smallest;
    }
    int largestRectangleArea(vector<int>& heights) {

        int len = heights.size();

        vector<int> smallestToLeft = calculateSmallest(heights, 0);
        vector<int> smallestToRight = calculateSmallest(heights, 1);

        int maxArea = 0;
        for(int i=0;i<len;i++)
        {
            cout<<smallestToLeft[i]<<"  "<<smallestToRight[i]<<endl;
            if(smallestToRight[i] == -1) smallestToRight[i] = len;
            maxArea = max(maxArea, (smallestToRight[i] - smallestToLeft[i] - 1) * heights[i]);
        }

        return maxArea;
    }
};