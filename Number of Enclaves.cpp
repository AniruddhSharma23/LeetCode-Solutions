class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j, m, n) + dfs(grid, i - 1, j, m, n) + dfs(grid, i, j + 1, m, n) + dfs(grid, i, j - 1, m, n);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int t = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                t += grid[i][j];

        int k = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                    k += dfs(grid, i, j, m, n);
        return t - k;
    }
};