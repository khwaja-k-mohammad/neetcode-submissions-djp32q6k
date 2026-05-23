class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int index = 1;
        
        vector<int> currVal = intervals[0];

        while(index < n)
        {
            if(intervals[index][0] >= currVal[0] && intervals[index][0] <= currVal[1])
            {
                vector<int> temp = { currVal[0], max(currVal[1], intervals[index][1])};
                currVal = temp;
            }
            else {
                result.push_back(currVal);
                currVal = intervals[index];
            }

            index += 1;
        }

        result.push_back(currVal);

        return result;
    }
};
