class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyDate = 0, sellDate = 1;

        int maxProfit = 0;
        while(sellDate < prices.size())
        {
            if(prices[buyDate] >= prices[sellDate])
            {
                buyDate = sellDate;
            }
            else {
                maxProfit = max(maxProfit, prices[sellDate] - prices[buyDate]);
            }
            
            sellDate += 1;
        }

        return maxProfit;
    }
};
