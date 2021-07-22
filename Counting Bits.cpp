// 338. Counting Bits
// Easy.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        int rangeEnd = 1, rangeBeg = -1;
        
        for(int i = 1; i <= n; ++i)
        {
            if(i == rangeEnd)
            {
                bits[i] = 1;
                rangeBeg = rangeEnd;
                rangeEnd *= 2;
            }
            else
            {
                if(i % 2 != 0)
                    bits[i] = bits[i-1] + 1;
                else
                    bits[i] = bits[i - rangeBeg] + 1;
            }
        }
        return bits;
    }
};