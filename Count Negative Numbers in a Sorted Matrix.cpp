class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size() - 1; // last row index
        int n = grid[0].size();  // number of columns
        int i = 0;
        int k = 0;              // number of neg values
        while (i < n && m >= 0) // start from the last row first column
        {
            if (grid[m][i] < 0) // if it's negative
            {
                k += n - i; // then all the elements ahead of this element in this row will also be negative
                m--;        // thus add n-i and move to the above row
            }
            else
            {
                i++; // if now move to the next element of this row
            }
        }
        return k;
    }
};