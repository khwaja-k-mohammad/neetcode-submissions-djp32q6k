class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prefix = 1, suffix = 1, maxResult = INT_MIN;
        int len = nums.size();

        for(int i=0;i<len;i++)
        {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[len-i-1];

            maxResult = max(maxResult, max(prefix, suffix));
        }

        return maxResult;
    }
};
