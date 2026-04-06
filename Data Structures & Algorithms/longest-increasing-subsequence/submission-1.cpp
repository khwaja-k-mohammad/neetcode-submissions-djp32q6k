class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size(), longestis = 1;
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i=1;i<len;i++)
        {
            if(nums[i] > dp.back())
            {
                dp.push_back(nums[i]);
                longestis += 1;
            }
            else {
                int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[index] = nums[i];
            }
        }

        return longestis;
    }
};
