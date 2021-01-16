// 212. Word Search II
// Hard. Faster than 86.13%

class Solution {
public:
    // store the direction of movements in the row and column direction
    const int move_x[4] = {0, 1, 0, -1};
    const int move_y[4] = {1, 0, -1, 0};

    // function to check whether the particular cell is safe in the board
    // a dot ('.') indicated that the cell has already been visited
    bool isSafe(int x, int y, vector<vector<char>>& board)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '.');
    }

    // function to check the words presence using DFS
    void dfs(int i, int j, vector<vector<char>>& board, bool &found, string str, int pos, vector<string> &res)
    {
        // if the last index is reached (pos == str.size() signifies that the control has reached after the last character)
        // then it means we have achieved the desired result
        if(pos == str.size())
        {
            res.push_back(str);
            found = true;
            return;
        }

        if(!isSafe(i, j, board) || str[pos] != board[i][j])
            return;

        char ch = board[i][j];
        board[i][j] = '.';
        for(int k = 0; k < 4; ++k)
        {
            int nextI = i + move_x[k], nextJ = j + move_y[k];
            dfs(nextI, nextJ, board, found, str, pos + 1, res);

            // if string is found then no need to iterate further, so break out
            if(found)
                break;
        }
        // backtrack
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        bool found;
        vector<string> res;
        for(string str : words)
        {
            found = false;
            for(int i = 0; i < board.size(); ++i)
            {
                for(int j = 0; j < board[0].size(); ++j)
                {
                    if(str[0] == board[i][j])
                    {
                        dfs(i, j, board, found, str, 0, res);
                    }

                    // if a word is found then there is no need to find more indices for that
                    if(found)
                        break;
                }
                if(found)
                    break;
            }
        }
        return res;
    }
};