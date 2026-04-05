class Solution {
public:
    bool isAlphaNumeric(char c)
    {
        if((c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9')
        ) return true;

        return false;
    }

    bool isPalindrome(string s) {
        
        int leftIndex = 0, rightIndex = s.length() - 1;

        while(leftIndex < rightIndex)
        {
            if(!isAlphaNumeric(s[leftIndex])) {
                leftIndex += 1;
                continue;
            }
            if(!isAlphaNumeric(s[rightIndex])) {
                rightIndex -= 1;
                continue;
            }

            if((char)tolower(s[leftIndex]) != (char)tolower(s[rightIndex])) return false;

            leftIndex += 1;
            rightIndex -= 1;
        }

        return true;
    }
};
