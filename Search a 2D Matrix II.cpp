class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m, n, r, c;
        m = matrix.size();
        n = matrix[0].size();
        r = 0;
        c = n - 1;
        // start from the element at first row and last column
        // if the ele is greater than target  move left i.e. c--
        // if it's smaller then move down i.e r++
        // if we reach the end of the matrix then return false
        while (r >= 0 && r < m && c >= 0 && c < n)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};