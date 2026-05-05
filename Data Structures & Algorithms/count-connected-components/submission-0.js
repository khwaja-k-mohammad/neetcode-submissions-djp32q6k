class Solution {
    /**
     * @param {number} n
     * @param {number[][]} edges
     * @returns {number}
     */
    countComponents(n, edges) {

        let adjList = Array.from({ length: n}, () => []);

        for(const [u, v] of edges)
        {
            adjList[u].push(v);
            adjList[v].push(u);
        }

        let queue = [];
        let count = 0;
        const visited = new Array(n + 1).fill(false);

        for(let i=0;i<n;i++)
        {
            if(visited[i]) continue;

            queue.push(i);
            count+=1;

            while(queue.length > 0)
            {
                const vertex = queue.shift();

                visited[vertex] = true;

                for(const neighbour of adjList[vertex])
                {
                    if(!visited[neighbour]) queue.push(neighbour);
                }
            }
        }

        return count;
    }
}
