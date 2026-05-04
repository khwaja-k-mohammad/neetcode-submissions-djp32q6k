class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const freqMap = {};

        for(const num of nums)
        {
            if(!freqMap[num]) freqMap[num] = 1;
            else freqMap[num] += 1;
        }

        let bucket = [];
        for(let key in freqMap)
        {
            const freq = freqMap[key];
            if(!bucket[freq]) bucket[freq] = [];
            bucket[freq].push(Number(key));
        }

        const result = [];
        for(let i=bucket.length - 1; i >= 0; i--)
        {
            if(bucket[i]) result.push(...bucket[i]);
            if(result.length == k) break;
        }

        return result;
    }
}
