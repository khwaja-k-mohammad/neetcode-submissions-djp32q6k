class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(0, nums);
    }

    int dfs(int index, vector<int> &nums)
    {
        if(index >= nums.size()) return 0;

        if(memo[index] != -1) return memo[index];

        memo[index] = max(nums[index] + dfs(index+2, nums), dfs(index+1, nums));
        return memo[index];
    }
};
