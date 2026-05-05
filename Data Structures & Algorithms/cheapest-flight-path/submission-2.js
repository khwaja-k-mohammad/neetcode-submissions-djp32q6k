class Solution {
    /**
     * @param {number} n
     * @param {number[][]} flights
     * @param {number} src
     * @param {number} dst
     * @param {number} k
     * @return {number}
     */
    findCheapestPrice(n, flights, src, dst, k) {

        let dist = Array(n).fill(Infinity);
        
        dist[src] = 0;

        for(let i=0;i<=k;i++)
        {
            const temp = [...dist];
            for(const [from, to, cost] of flights)
            {
                if(dist[from] !== Infinity && dist[from] + cost < temp[to])
                {
                    temp[to] = dist[from] + cost;
                }
            }

            dist = temp;
        }

        return dist[dst] == Infinity ? -1 : dist[dst];
    }
}
