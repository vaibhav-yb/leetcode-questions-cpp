// 762. Prime Number of Set Bits in Binary Representation
// Easy. Faster than 42.44%.
class Solution {
public:
    bool isPrime(int num)
    {
        if(num <= 1)
            return false;
        
        for(int i = 2; i <= sqrt(num); ++i)
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    int setBitCount(int num)
    {
        int set_bit_count = 0;
        int i = 1;
        while(i <= num)
        {
            if((i & num) != 0)
                set_bit_count++;
            i = i << 1;
        }
        return set_bit_count;
    }
    int countPrimeSetBits(int L, int R) {
        int primeBitsCount = 0;
        for(int i = L; i <= R; ++i)
        {
            if(isPrime(setBitCount(i)))
                primeBitsCount++;
        }
        return primeBitsCount;
    }
};