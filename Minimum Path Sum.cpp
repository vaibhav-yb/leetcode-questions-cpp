// 64. Minimum Path Sum
// Medium. Faster than 95.80%.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();

        // initialize matrix to store the results of subproblems
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <= m; ++i)
            dp[i][0] = INT_MAX;
        for(int j = 0; j <= n; ++j)
            dp[0][j] = INT_MAX;
        
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i == 1 && j == 1)
                    dp[i][j] = grid[0][0];
                // the else section will assign the shortest path sum as it is the sum
                // of current cell and the minimum of either top cell or left cell as
                // can be found from the question description
                else
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};