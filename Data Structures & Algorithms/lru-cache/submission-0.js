class Node
{
    constructor(key, value)
    {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    /**
     * @param {number} capacity
     */
    constructor(capacity) {
        this.maxSize = capacity;
        this.map = new Map();
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);

        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    addNode(node) {
        node.prev = this.head;
        node.next = this.head.next;

        this.head.next = node;
        node.next.prev = node;
    }

    removeNode(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    /**
     * @param {number} key
     * @return {number}
     */
    get(key) {
        if(!this.map.has(key)) return -1;
        const currNode = this.map.get(key);

        this.removeNode(currNode);
        this.addNode(currNode);

        return currNode.value;
    }

    /**
     * @param {number} key
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        let node = null;
        if(this.map.has(key)) {
            node = this.map.get(key);
            node.value = value;
            this.removeNode(node);
        }
        else node = new Node(key, value);

        this.addNode(node);
        this.map.set(key, node);

        if(this.map.size > this.maxSize)
        {
            const lru = this.tail.prev;
            this.map.delete(lru.key);
            this.removeNode(lru);
        }
    }
}
