class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> dp(len+1, 1);

        int maxLength = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
            }

            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
