// 1493. Longest Subarray of 1's After Deleting One Element
// Medium
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // if array is empty then the longest resultant array size will obviously be 0
        if(nums.empty())
            return -1;
        int prev_len = -1, len = 0, max_len = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            // keep increasing the length
            len++;
            
            // if zero is encountered then change the length of the window
            // according to the info whether a zero has occured earlier or not
            if(nums[i] == 0)
            {
                if(prev_len == -1)
                    prev_len = len;
                else
                {
                    max_len = max(max_len, len - 1);
                    len -= prev_len;
                    prev_len = len;
                }
            }
        }
        max_len = max(max_len, len);
        
        // the max_length contains the length including the zero (the element to be deleted)
        // so we return a value 1 less than the max_length
        return (max_len - 1);
    }
};