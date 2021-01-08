// 1636. Sort Array by Increasing Frequency
// Easy.

unordered_map<int, int> mp;
bool cmp(const int &a, const int &b)
{
    if(::mp[a] == ::mp[b])
        return a > b;
    return ::mp[a] < ::mp[b];
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        mp.clear();
        for(int val : nums)
            mp[val]++;
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};