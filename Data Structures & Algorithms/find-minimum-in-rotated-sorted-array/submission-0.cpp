class Solution {
public:
    int findMin(vector<int> &nums) {

        int leftIndex = 0, rightIndex = nums.size() - 1;

        int len = nums.size();

        while(leftIndex <= rightIndex)
        {
            int mid = leftIndex + (rightIndex - leftIndex)/2;

            if(nums[mid] > nums[len - 1]) leftIndex = mid + 1;
            else rightIndex = mid - 1;
        }

        return nums[leftIndex];
    }
};
