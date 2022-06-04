class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int k = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int m1 = 0;
                int m2 = 0;
                for (int p = 0; p < n; p++)
                {
                    m2 = max(m2, grid[p][j]);
                    m1 = max(m1, grid[i][p]);
                }
                int m = min(m1, m2);
                k += m - grid[i][j];
            }
        }
        return k;
    }
};