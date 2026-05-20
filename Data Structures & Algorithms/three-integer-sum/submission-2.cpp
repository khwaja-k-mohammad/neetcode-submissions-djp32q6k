class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i=0;i<nums.size();i++)
        {
            int l = i+1, r = nums.size() - 1;

            if(i>0 && nums[i] == nums[i-1]) continue;
            while(l < r)
            {
                int currSum = nums[l] + nums[r];
                int target = -1 * nums[i];

                if(currSum < target) l+=1;
                else if(currSum > target) r-=1;
                else {
                    result.push_back({ nums[i], nums[l], nums[r]});
                    int lVal = nums[l++], rVal = nums[r--];
                    while(l < r && lVal == nums[l]) l++;
                }
            }
        }

        return result;
    }
};
