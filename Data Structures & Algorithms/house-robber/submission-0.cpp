class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> dp(nums.size() + 1);

        dp[0] = nums[0];
        for(int i=1;i<len;i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[len-1];
    }
};
