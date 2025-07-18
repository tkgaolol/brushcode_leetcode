class Solution {
public:
    bool backtracking(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1'; k<='9'; k++)
                    {
                        if(isValid(i, j, k, board))
                        {
                            board[i][j] = k;
                            if (backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char num, vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == num || board[row][i] == num)
                return false;
        }
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for(int i = startrow; i < startrow + 3; i++)
        {
            for(int j = startcol; j < startcol + 3; j++)
            {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};