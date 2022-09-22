class Solution
{
public:
    bool isSafe(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if (i == m)
            return j;
        if (isSafe(i, j, m, n))
        {
            if (grid[i][j] == 1)
            {
                if (isSafe(i, j + 1, m, n) && grid[i][j + 1] == 1)
                    return dfs(grid, i + 1, j + 1, m, n);
            }
            else
            {
                if (isSafe(i, j - 1, m, n) && grid[i][j - 1] == -1)
                    return dfs(grid, i + 1, j - 1, m, n);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans;
        for (int j = 0; j < n; j++)
        {
            int k = dfs(grid, 0, j, m, n);
            ans.push_back(k);
        }
        return ans;
    }
};