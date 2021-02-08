// 821. Shortest Distancce to a Character
// Easy.

class Solution {
public:
    int findMinimumDistance(int i, vector<int> &positions)
    {
        int dist = INT_MAX, temp;
        for(int val : positions)
        {
            temp = dist;
            dist = min(dist, abs(i - val));
            if(dist == temp)
                return dist;
        }
        return dist;
    }
    vector<int> shortestToChar(string s, char c) {
        vector<int> positions, res;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == c)
                positions.push_back(i);
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == c)
                res.push_back(0);
            else
                res.push_back(findMinimumDistance(i, positions));
        }
        return res;
    }
};