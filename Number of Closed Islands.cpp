class Solution
{
public:
    bool dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if (grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool b1 = dfs(grid, i + 1, j, m, n);
        bool b2 = dfs(grid, i - 1, j, m, n);
        bool b3 = dfs(grid, i, j + 1, m, n);
        bool b4 = dfs(grid, i, j - 1, m, n);
        return b1 & b2 & b3 & b4;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans += dfs(grid, i, j, m, n) ? 1 : 0;
                }
            }
        }
        return ans;
    }
};