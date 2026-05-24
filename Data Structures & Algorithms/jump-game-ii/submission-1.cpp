class Solution {
public:
    int jump(vector<int>& nums) {
        
        int currIndex = 0, totalJumps = 0, len = nums.size();
        int maxReachableIndex = nums[0];

        if(currIndex == len - 1) return totalJumps;
        
        while(currIndex < len)
        {
            int newMaxIndex = currIndex;
        
            while(currIndex <= min(maxReachableIndex, len - 1))
            {
                newMaxIndex = max(newMaxIndex, currIndex + nums[currIndex]);
                currIndex += 1;
            }

            totalJumps += 1;
            maxReachableIndex = newMaxIndex;
        }

        return totalJumps;
    }
};
