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

        if(extra > 0) {
            vector<int> result;
            result.reserve(len + 1);

            result.push_back(extra);
            result.insert(result.end(), digits.begin(), digits.end());
            return result;
        }
        else return digits;
    }
};
