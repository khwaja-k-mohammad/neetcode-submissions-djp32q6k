class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int oneStepBack = 0, twoStepsBack = 0;

        for(int i=2;i<=cost.size();i++)
        {
            int minVal = min(cost[i-1] + oneStepBack, cost[i-2] + twoStepsBack);

            twoStepsBack = oneStepBack;
            oneStepBack = minVal;
        }

        return oneStepBack;
    }
};
