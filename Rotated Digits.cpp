// 788. Rotated Digits
// Easy.

class Solution {
public:
    map<int, int> rotated = {
        {0, 0},
        {1, 1},
        {8, 8},
        {2, 5},
        {5, 2},
        {6, 9},
        {9, 6}
    };
    bool isGood(int &num)
    {
        int temp = num, mul = 1, d, newNum = 0;
        while(temp != 0)
        {
            d = temp % 10;
            temp /= 10;
            if(rotated.find(d) == rotated.end())
                return false;
            d = rotated[d];
            newNum = (d * mul) + newNum;
            mul *= 10;
        }
        return (newNum != num);
    }
    
    int rotatedDigits(int N) {
        int goodNumbers = 0;
        for(int i = 1; i <= N; ++i)
        {
            if(isGood(i))
                goodNumbers++;
        }
        return goodNumbers;
    }
};