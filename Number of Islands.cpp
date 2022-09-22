class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 || grid[i][j] == '0')
            return;
        vis[i][j] = 1;
        dfs(grid, vis, i + 1, j, m, n);
        dfs(grid, vis, i - 1, j, m, n);
        dfs(grid, vis, i, j + 1, m, n);
        dfs(grid, vis, i, j - 1, m, n);
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    count++;
                    dfs(grid, vis, i, j, m, n);
                }
            }
        }
        return count;
    }
};