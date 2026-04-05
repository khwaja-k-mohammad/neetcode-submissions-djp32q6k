class Solution {
public:
    int climbStairs(int n) {

        int oneStepBehind = 1;
        int twoStepBehind = 1;
        int currVal = 1;

        for(int i=2;i<=n;i++) {
            currVal = oneStepBehind + twoStepBehind;
            twoStepBehind = oneStepBehind;
            oneStepBehind = currVal;
        }

        return currVal;
    }
};
