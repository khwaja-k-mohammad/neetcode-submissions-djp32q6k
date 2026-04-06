class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len = nums.size();

        int twoHousesBehind = 0;
        int oneHouseBehind = nums[0];
        int currMaxVal = nums[0];

        for(int i=2;i<=len;i++)
        {
            currMaxVal = max(twoHousesBehind + nums[i-1], oneHouseBehind);
            twoHousesBehind = oneHouseBehind;
            oneHouseBehind = currMaxVal;
        }

        return currMaxVal;
    }
};
