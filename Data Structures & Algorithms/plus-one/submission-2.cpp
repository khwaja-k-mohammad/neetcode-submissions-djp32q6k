class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        

        int len = digits.size(), extra = 1;

        for(int i=len-1;i>=0;i--)
        {
            int currSum = digits[i] + extra;
            digits[i] = currSum % 10;
            extra = currSum / 10;
        }

        if(extra == 1) digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
