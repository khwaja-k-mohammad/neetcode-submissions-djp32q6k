class Solution {
    /**
     * @param {number[][]} times
     * @param {number} n
     * @param {number} k
     * @return {number}
     */
    networkDelayTime(times, n, k) {
        
        let dist = Array(n+1).fill(Infinity);

        dist[k] = 0;

        for(let i=1; i<n; i++)
        {
            for(const [u,v,time] of times)
            {
                if(dist[u]!==Infinity && dist[u] + time < dist[v]) dist[v] = dist[u] + time;
            }
        }

        const res = Math.max(...dist.slice(1));

        return res == Infinity ? -1 : res;
    };
}
