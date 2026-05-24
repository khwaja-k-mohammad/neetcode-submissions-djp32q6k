class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;

    int k;
    KthLargest(int k, vector<int>& nums) {
        
        this -> k = k;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(pq.size() < k) pq.push(nums[i]);
            else if(pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        
        if(pq.size() < this -> k) {
            pq.push(val);
        }
        else if(pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
    }
};
