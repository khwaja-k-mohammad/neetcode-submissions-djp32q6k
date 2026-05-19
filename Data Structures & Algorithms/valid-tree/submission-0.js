class Solution {
    /**
     * @param {number} n
     * @param {number[][]} edges
     * @returns {boolean}
     */
    validTree(n, edges) {

        const adjList = Array.from({ length: n}, () => []);

        for(let i=0;i<edges.length;i++)
        {
            const v1 = edges[i][0], v2 = edges[i][1];
            adjList[v1].push(v2);
            adjList[v2].push(v1);
        }

        let queue = [];
        let visited = new Map();

        queue.push([-1, 0]);

        while(queue.length > 0)
        {
            const list = queue.shift();

            const parent = list[0];
            const currNode = list[1];
            visited.set(currNode,true);

            for(let i=0;i<adjList[currNode].length;i++)
            {
                const nextNode = adjList[currNode][i];
                if(nextNode == parent) continue;
                else if(visited.get(nextNode)) return false;
                else queue.push([currNode, nextNode]);
            }
        }

        return visited.size == n ? true : false;
    }
}
