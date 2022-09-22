class Solution
{
public:
    int cnt = 0;
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return;
        if (grid1[i][j] != 1)
            cnt++;
        grid2[i][j] = 0;
        dfs(grid1, grid2, i + 1, j, m, n);
        dfs(grid1, grid2, i - 1, j, m, n);
        dfs(grid1, grid2, i, j + 1, m, n);
        dfs(grid1, grid2, i, j - 1, m, n);
        return;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    cnt = 0;
                    dfs(grid1, grid2, i, j, m, n);
                    if (cnt == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};