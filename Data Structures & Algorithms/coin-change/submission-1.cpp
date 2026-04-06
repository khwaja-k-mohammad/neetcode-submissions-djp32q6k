class Solution {
public:

    unordered_map<int, int> dp;

    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;
        if(dp[amount]) return dp[amount];
        
        int minCoins = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            if(amount < coins[i]) continue;
            else if(amount == coins[i]) return 1;
            else {
                int totalCoins = coinChange(coins, amount - coins[i]);
                if(totalCoins == -1) continue;

                minCoins = min(minCoins, 1 + totalCoins);
            }
        }

        dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return dp[amount];
    }
};
