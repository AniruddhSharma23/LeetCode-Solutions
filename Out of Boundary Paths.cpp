class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        uint dp[51][50][50]; // dp[k][i][j] = no of ways<=k to reach outside of the grid starting from pos=[i][j]
        int mod = 1e9 + 7;
        for (int k = 1; k <= maxMove; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[k][i][j] = (((i == 0) ? 1 : dp[k - 1][i - 1][j])       // move left
                                   + ((i == m - 1) ? 1 : dp[k - 1][i + 1][j]) // move right
                                   + ((j == 0) ? 1 : dp[k - 1][i][j - 1])     // move down
                                   + ((j == n - 1) ? 1 : dp[k - 1][i][j + 1]) // move up
                                   ) %
                                  mod;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};