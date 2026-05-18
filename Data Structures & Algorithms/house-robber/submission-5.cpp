class Solution {
public:
    int rob(vector<int>& nums) {
        
        int secondPrev = 0, firstPrev = 0;
        for(int i=0;i<nums.size();i++)
        {
            int temp = max(secondPrev + nums[i], firstPrev);
            secondPrev = firstPrev;
            firstPrev = temp;
        }

        return firstPrev;
    }
};
