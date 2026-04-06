class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxJump = -1, len = nums.size();

        for(int i=0;i<len;i++)
        {
            if(i == len-1) return true;

            maxJump = max(maxJump, i+nums[i]);
            if(maxJump <= i) return false;
        }

        return true;
    }
};
