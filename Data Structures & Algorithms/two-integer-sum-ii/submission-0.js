class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {

        let left = 0, right = numbers.length - 1;

        while(left < right)
        {
            if(numbers[left] + numbers[right] == target) return [left+1, right+1];
            else if(numbers[left] + numbers[right] < target) left += 1;
            else right -= 1;
        }

        return [-1, -1];
    }
}
