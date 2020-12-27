// 128. Longest Consecutive Sequence
// faster than 12.28%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int val : nums)
            pq.push(val);
        
        int prev = INT_MIN, curr_count = 0, max_count = INT_MIN;
        while(!pq.empty())
        {
            int ele = pq.top();
            pq.pop();
            if(ele == prev)
                continue;
            else if(ele == prev + 1)
                curr_count++;
            else
            {
                max_count = max(max_count, curr_count);
                curr_count = 1;
            }
            prev = ele;
        }
        max_count = max(max_count, curr_count);
        return max_count;
    }
};