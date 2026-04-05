class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int len = nums.size();
        int leftIndex = 0, rightIndex = len - 1;

        while(leftIndex <= rightIndex)
        {
            int midIndex = leftIndex + (rightIndex - leftIndex)/2;

            if(nums[midIndex] == target) return midIndex;

            if(nums[midIndex] > nums[len - 1])
            {
                if(nums[midIndex] < target) leftIndex = midIndex + 1;
                else if(target < nums[0]) leftIndex = midIndex + 1;
                else rightIndex = midIndex - 1;
            }
            else {
                if(nums[midIndex] > target) rightIndex = midIndex - 1;
                else if(target > nums[len - 1]) rightIndex = midIndex - 1;
                else leftIndex = midIndex + 1;
            }
        }

        return nums[leftIndex] == target ? leftIndex : -1;
    }
};
