class Solution
{
public:
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;
        vis[i][j] = 1;
        return 1 + dfs(grid, vis, i + 1, j, m, n) + dfs(grid, vis, i - 1, j, m, n) + dfs(grid, vis, i, j + 1, m, n) + dfs(grid, vis, i, j - 1, m, n);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    int k = dfs(grid, vis, i, j, m, n);
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};