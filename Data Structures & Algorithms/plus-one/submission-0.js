class Solution {
    /**
     * @param {number[]} digits
     * @return {number[]}
     */
    plusOne(digits) {

        const len = digits.length;
        let extra = 1;

        for(let i=len-1;i>=0;i--)
        {
            const currSum = digits[i] + extra;
            digits[i] = currSum % 10;
            extra = Math.floor(currSum / 10);
        }

        if(extra > 0) digits.unshift(extra);

        return digits;
    }
}
