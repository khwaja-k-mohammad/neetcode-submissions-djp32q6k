class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(), currXor = 0, totalXor = 0;
        for(int i=1;i<=n;i++) totalXor ^= i;
        for(int i=0;i<n;i++) currXor ^= nums[i];

        return totalXor ^ currXor;
    }
};
