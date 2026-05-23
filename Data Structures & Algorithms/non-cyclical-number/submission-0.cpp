class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> s;

        while(true)
        {
            s.insert(n);
            int sum = 0;
            while(n > 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            if(sum == 1) return true;
            if(s.count(sum)) return false;

            n = sum;
        }

        return false;
    }
};
