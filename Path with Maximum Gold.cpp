class Solution {
public:
    // x and y possible directional moves
    int moveX[4] = {0, 1, 0, -1};
    int moveY[4] = {1, 0, -1, 0};
    
    void findGold(int x, int y, int &curr_gold, int &max_gold, vector<vector<int>>& grid)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
        {
            max_gold = max(max_gold, curr_gold);
            return;
        }
        
        int temp = grid[x][y];
        curr_gold += temp;
        grid[x][y] = 0;
        
        for(int k = 0; k < 4; ++k)
        {
            int newX = x + moveX[k], newY = y + moveY[k];
            findGold(newX, newY, curr_gold, max_gold, grid);
        }
        curr_gold -= temp;
        grid[x][y] = temp;
    }
    
    /*
     This can be more optimized by checking if all the cells are visited in one go.
     If all the cells are visited then we can simply exit out of the program because then
     no other path can do more than that (it will always visit all the cells again).
    */
    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = INT_MIN, curr_gold = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] != 0)
                    findGold(i, j, curr_gold, max_gold, grid);
            }
        }
        return max_gold;
    }
};