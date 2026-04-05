class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int startIndex = 0;
        unordered_map<char, int> lastAppearedAt;

        int maxSubLength = 0;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(lastAppearedAt.find(s[i]) != lastAppearedAt.end()) {
                startIndex = max(startIndex, lastAppearedAt[s[i]] + 1);
            }
            
            maxSubLength = max(maxSubLength, i - startIndex + 1);
            lastAppearedAt[s[i]] = i;
        }

        return maxSubLength;
    }
};
