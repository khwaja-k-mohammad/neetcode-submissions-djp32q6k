class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        set<vector<int>> s;

        for(int i=0;i<len;i++)
        {
            unordered_map<int, int> mp;
            for(int j=i+1;j<len;j++)
            {
                int target = -1 * (nums[i] + nums[j]);
                if(mp.count(target)) {
                    vector<int> temp = {nums[i], target, nums[j]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                else mp[nums[j]] = 1;
            }
        }

        return vector<vector<int>>(s.begin(), s.end());
    }
};
