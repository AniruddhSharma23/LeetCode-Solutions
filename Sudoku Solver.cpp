class Solution
{
public:
    bool isSafe(int row, int col, char val, vector<vector<char>> &board)
    {
        for (int p = 0; p < 9; p++)
        {
            if (board[p][col] == val || board[row][p] == val) // check for row and col
                return false;

            // check for square grid of size 3*3
            int rs = row - row % 3;
            int cs = col - col % 3;
            for (int i = rs; i < rs + 3; i++)
            {
                for (int j = cs; j < cs + 3; j++)
                {
                    if (board[i][j] == val)
                        return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.') // if empty
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isSafe(row, col, val, board))
                        {
                            board[row][col] = val;
                            if (solve(board)) // check if by putting above value we get a valid sudoku
                            {
                                return true;
                            }
                            else // backtrack, because the sol isin't valid
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};