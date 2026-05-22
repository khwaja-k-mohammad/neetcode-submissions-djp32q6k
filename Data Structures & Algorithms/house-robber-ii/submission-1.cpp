class Solution {
public:

    int calcRobbery(vector<int> arr)
    {
        int firstPrev = 0, secondPrev = 0, currSum = 0;
        for(int i=0;i<arr.size();i++)
        {
            currSum = max(arr[i] + secondPrev, firstPrev);
            secondPrev = firstPrev;
            firstPrev = currSum;
        }

        return firstPrev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else return max(
            calcRobbery(vector<int>(nums.begin(), nums.begin() + n - 1)),
            calcRobbery(vector<int>(nums.begin() + 1, nums.end()))
        );
    }
};
