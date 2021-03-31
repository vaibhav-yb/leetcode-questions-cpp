// 14. Longest Common Prefix
// Easy.

class Solution {
public:
    void findAnswer(vector<string> &strs, string &ans)
    {
        char ch = '.';
        for(int i = 0; ; ++i)
        {
            ch = '.';
            for(string s : strs)
            {
                if(i >= s.size())
                    return;
                
                if(ch == '.')
                    ch = s[i];
                
                if(ch != s[i])
                    return;
            }
            ans += ch;
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string ans;
        findAnswer(strs, ans);
        return ans;
    }
};