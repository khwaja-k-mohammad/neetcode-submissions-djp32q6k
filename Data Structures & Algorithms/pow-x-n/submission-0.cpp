class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return myPow((double)(1/x), n * -1);
        if(n == 0) return 1;
        
        if(n % 2) return x * myPow(x, n-1);
        else return myPow(x, n/2) * myPow(x, n/2);
    }
};
