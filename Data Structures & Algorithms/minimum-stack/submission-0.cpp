class MinStack {
public:
        stack<int> mainStack;
        stack<int> minStack;
    MinStack() {

    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || minStack.top() >= val) minStack.push(val);
    }
    
    void pop() {
        int topVal = mainStack.top();
        mainStack.pop();
        if(minStack.top() == topVal) minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
