class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int startIndex = 0;
        unordered_map<char, int> lastAppearedAt;

        int maxSubLength = 0;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(! lastAppearedAt[s[i]] || lastAppearedAt[s[i]] - 1 < startIndex) {
                lastAppearedAt[s[i]] = i + 1;
            }
            else {
                maxSubLength = max(maxSubLength, i - startIndex);
                startIndex = lastAppearedAt[s[i]];
                lastAppearedAt[s[i]] = i + 1;
            }
        }

        maxSubLength = max(maxSubLength, i - startIndex);

        return maxSubLength;
    }
};
