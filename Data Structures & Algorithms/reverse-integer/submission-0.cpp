class Solution {
public:
    int reverse(int x) {
        
        int result = 0;
        while(x != 0)
        {
            int reminder = x % 10;
            x /= 10;

            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && reminder > 7)) return 0;
            if(result < INT_MIN / 10 || (result == INT_MIN / 10 && reminder < -8)) return 0;

            result = result * 10 + reminder;
        }

        return result;
    }
};
