class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    maxProduct(nums) {

        let prefix = 1, suffix = 1, maxResult = -Infinity;
        const len = nums.length;

        for(let i=0;i<len;i++)
        {
            if(prefix === 0 || prefix == -0) prefix = 1;
            if(suffix === 0 || suffix == -0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[len-i-1];

            maxResult = Math.max(maxResult, Math.max(prefix, suffix));
        }

        return maxResult == -0 ? 0 : maxResult;
    }
}
