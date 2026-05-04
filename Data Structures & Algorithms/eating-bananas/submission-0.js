class Solution {

    calculateTotalHours(piles, k)
    {
        let total = 0;
        for(const pile of piles)
        {
            total += (pile % k === 0) ? pile / k : Math.floor(pile / k) + 1;
        }

        return total;
    }

    minEatingSpeed(piles, h) {

        let left = 0, right = 1e9;

        while(left <= right)
        {
            const mid = left + Math.floor((right - left)/2);

            if(this.calculateTotalHours(piles, mid) <= h) right = mid - 1;
            else left = mid + 1;
        } 

        return left;
    }
};
