// 79. Word Search
// Medium. Faster than 99.79%

/*
 * NOTE: The solution achieved 99% speed accuracy from 49% just after changing word to
 *       &word because there was no harm in working on the original value 
 */

class Solution {
public:
    const int moveX[4] = {0, 1, 0, -1};
    const int moveY[4] = {1, 0, -1, 0};
    bool isSafe(int x, int y, vector<vector<char>>& board)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '.');
    }
    void dfs(int i, int j, vector<vector<char>>& board, string &word, int pos, bool &found)
    {
        if(pos == word.size())
        {
            found = true;
            return;
        }
        
        if(!isSafe(i, j, board) || word[pos] != board[i][j])
            return;
        
        char ch = board[i][j];
        board[i][j] = '.';
        for(int k = 0; k < 4; ++k)
        {
            int x = i + moveX[k], y = j + moveY[k];
            dfs(x, y, board, word, pos + 1, found);
            if(found)
                return;
        }
        // backtrack
        board[i][j] = ch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                    dfs(i, j, board, word, 0, found);
                
                if(found)
                    return found;
            }
        }
        return found;
    }
};