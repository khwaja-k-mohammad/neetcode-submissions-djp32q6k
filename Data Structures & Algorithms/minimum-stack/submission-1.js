class MinStack {
    constructor() {

        this.mainStack = [];
        this.minStack = [];
    }

    /**
     * @param {number} val
     * @return {void}
     */
    push(val) {
        this.mainStack.push(val);
        if(!this.minStack.length || this.minStack.at(-1) >= val) this.minStack.push(val);
    }

    /**
     * @return {void}
     */
    pop() {
        if(!this.mainStack.length) throw new Error("Invalid Command");
        const topVal = this.mainStack.pop();
        if(this.minStack.at(-1) == topVal) this.minStack.pop();
    }

    /**
     * @return {number}
     */
    top() {
        return this.mainStack.at(-1);
    }

    /**
     * @return {number}
     */
    getMin() {
        return this.minStack.at(-1);
    }
}
