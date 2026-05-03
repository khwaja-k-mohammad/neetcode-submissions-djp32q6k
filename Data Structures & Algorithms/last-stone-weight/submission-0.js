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
            if(this.heap[index] <= this.heap[parent]) break;
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
            if(left < len && this.heap[smallest] < this.heap[left]) smallest = left;
            if(right < len && this.heap[smallest] < this.heap[right]) smallest = right;

            if(smallest == index) break;
            let temp = this.heap[index];
            this.heap[index] = this.heap[smallest];
            this.heap[smallest] = temp;

            index = smallest;
        }

        return topVal;
    }
};

class Solution {

    lastStoneWeight(stones) 
    {
        const heapify = new Heapify();

        for(const stone of stones) {
            heapify.push(stone);
        }

        while(heapify.heap.length > 1)
        {
            const x = heapify.pop();
            const y = heapify.pop();

            heapify.push(Math.abs(x-y));
        }

        return heapify.heap[0];
    }
};
