class Solution {
    /**
     * @param {number} numCourses
     * @param {number[][]} prerequisites
     * @return {boolean}
     */
    canFinish(numCourses, prerequisites) {

        let coursesToClear = new Array(numCourses).fill(0);
        let dependantCoursesList = Array.from({ length: numCourses }, () => []);

        for(let [a,b] of prerequisites)
        {
            coursesToClear[a] += 1;
            dependantCoursesList[b].push(a);
        }

        let queue = [];
        for(let i=0;i<numCourses;i++)
        {
            if(coursesToClear[i] == 0) queue.push(i);
        }

        let completed = 0;
        while(queue.length > 0)
        {
            const c = queue.shift();
            completed += 1;
            for(let neighbour of dependantCoursesList[c])
            {
                coursesToClear[neighbour]--;
                if(coursesToClear[neighbour] == 0){
                    queue.push(neighbour);
                }
            }
        }

        return completed == numCourses;
    }
}
