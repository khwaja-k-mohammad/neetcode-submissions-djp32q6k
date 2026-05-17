class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> s;
        vector<int> result(temperatures.size(), 0);

        for(int i=0;i<temperatures.size();i++)
        {
            if(!s.empty()) {
                while(!s.empty() && temperatures[s.top()] < temperatures[i])
                {
                    int prevDay = s.top();
                    s.pop();
                    result[prevDay] = i - prevDay;
                }
            }

            s.push(i);
        }

        return result;
    }
};
