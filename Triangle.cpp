// 120. Triangle
// Medium. faster than 73.01%.
// Solution implemented using same space as the given 'triangle' vector

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector< vector<int> > res;
        int min_path_sum = INT_MAX;
        res = triangle;
        for(int i = 0; i < res.size(); ++i)
        {
            for(int j = 0; j < res[i].size(); ++j)
            {
                if(i == 0)
                    res[i][j] = triangle[i][j];
                else
                {
                    int l = INT_MAX, r = INT_MAX;
                    if(j - 1 >= 0)
                        l = res[i-1][j-1];
                    if(j < i)
                        r = res[i-1][j];
                    
                    res[i][j] = triangle[i][j] + min(l, r);
                }
            }
        }
        
        for(int j = 0; j < triangle[m-1].size(); ++j)
            min_path_sum = min(min_path_sum, res[m-1][j]);
        
        return min_path_sum;
    }
};