class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxLen = 0, maxIndex = 0;

        for(int k=1;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                int j = i + k - 1;
                if(s[i] == s[j]) {
                    if (k <= 2) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }

                if(dp[i][j] && maxLen < k) {
                    maxLen = k;
                    maxIndex = i;
                }

            }

        }

        return s.substr(maxIndex, maxLen);
    }

};
