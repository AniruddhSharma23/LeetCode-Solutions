class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int inf = 10000000000;
        int dp[100][100] = {};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    dp[i][j] = inf;
                    for (int k = 0; k < n; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + grid[i][j] + moveCost[grid[i - 1][k]][j]);
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[m - 1][i]);
        }
        return ans;
    }
};