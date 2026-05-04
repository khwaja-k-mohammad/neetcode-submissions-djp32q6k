class Solution {

    findMin(nums) {
        
        let left = 0, right = nums.length - 1, len = nums.length - 1;

        while(left <= right)
        {
            const mid = left + Math.floor((right - left)/2);

            if(nums[mid] >= nums[0] && nums[mid] <= nums[len]) right = mid - 1;
            else if(nums[mid] >= nums[0] && nums[mid] >= nums[len]) left = mid + 1;
            else if(nums[mid] <= nums[0] && nums[mid] <= nums[len]) right = mid - 1;
        }

        return nums[left];
    }
}
