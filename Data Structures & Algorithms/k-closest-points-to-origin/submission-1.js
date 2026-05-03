/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

class Heapify
{
    constructor()
    {
        this.heap = [];
    }

    push(val)
    {
        const len = this.heap.push(val);
        let index = len - 1;

        while(index > 0)
        {
            const parent = Math.floor((index - 1)/2);
            if(this.heap[index][0] <= this.heap[parent][0]) break;
            let temp = this.heap[parent];
            this.heap[parent] = this.heap[index];
            this.heap[index] = temp;

            index = parent;
        }
    }

    pop()
    {
        if(this.heap.length === 1) return this.heap.pop();
        const topVal = this.heap[0];
        const lastVal = this.heap.pop();
        const len = this.heap.length;

        let index = 0;
        this.heap[0] = lastVal;

        while(index < len)
        {
            let smallest = index;
            const left = (2 * index) + 1;
            const right = (2 * index) + 2;
            if(left < len && this.heap[smallest][0] < this.heap[left][0]) smallest = left;
            if(right < len && this.heap[smallest][0] < this.heap[right][0]) smallest = right;

            if(smallest == index) break;
            let temp = this.heap[index];
            this.heap[index] = this.heap[smallest];
            this.heap[smallest] = temp;

            index = smallest;
        }

        return topVal;
    }
}

class Solution {
    /**
     * @param {number[][]} points
     * @param {number} k
     * @return {number[][]}
     */
    kClosest(points, k) {

        const heapify = new Heapify();

        const dist = [];

        for(const point of points)
        {
            dist.push([point[0] * point[0] + point[1] * point[1], point]);
        }

        for(const point of dist)
        {
            if(heapify.heap.length < k) heapify.push(point);
            else if(heapify.heap[0][0] > point[0])
            {
                    heapify.pop();
                    heapify.push(point);
            }
        }

        const result = [];
        while(heapify.heap.length > 0)
        {
            const point = heapify.pop();
            result.push(point[1]);
        }

        return result;
    }
}
