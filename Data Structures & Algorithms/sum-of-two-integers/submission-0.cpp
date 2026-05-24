class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = 0, carry = 0;
        for(int i=0;i<32;i++)
        {
            int bita = a & 1;
            int bitb = b & 1;
            int temp = bita ^ bitb ^ carry;

            sum |= (temp << i);
            a >>= 1;
            b >>= 1;

            if((bita & bitb) || (bitb & carry) || (carry & bita)) carry = 1;
            else carry = 0;
        }

        return sum;
    }
};
