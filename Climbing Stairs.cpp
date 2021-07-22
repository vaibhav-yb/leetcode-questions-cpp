// 70. Climbing Stairs
// Easy.

class Solution {
public:
    int waysCount(vector<int> &steps, int n)
    {
        if(steps[n] != -1)
            return steps[n];
        
        return steps[n] = waysCount(steps, n-1) + waysCount(steps, n-2);
    }
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        
        vector<int> steps(n+1, -1);
        steps[1] = 1;
        steps[2] = 2;
        
        return waysCount(steps, n);
    }
};