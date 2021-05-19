class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
            return 0;
        // we will find median first
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // the median element is the value we have to reach for all the elements
        // either by decrementing it or incrementing it
        int minMoves = 0;
        for(int val : nums)
            minMoves += abs(val - median);
        
        return minMoves;
    }
};