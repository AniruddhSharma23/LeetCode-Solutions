class Solution
{
public:
    double knightProbability(int n, int k, int r, int c)
    {
        if (k == 0)
            return 1.0;
        vector<vector<double>> v1(n, vector<double>(n, 0.0));
        vector<int> dx = {1, -1, 2, -2, 1, -1, 2, -2};
        vector<int> dy = {2, 2, 1, 1, -2, -2, -1, -1};
        v1[r][c] = 1.0;
        while (k--)
        {
            vector<vector<double>> v2(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    double prob = v1[i][j] / 8.0;
                    for (int z = 0; z < 8; z++)
                    {
                        int x = i + dx[z];
                        int y = j + dy[z];
                        if (x >= 0 && x < n && y >= 0 && y < n)
                            v2[x][y] += prob;
                    }
                }
            }
            v1 = v2;
        }
        double ans = 0.0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans += v1[i][j];
        return ans;
    }
};

// DP recursive:

class Solution
{
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;

public:
    double knightProbability(int N, int K, int r, int c)
    {
        if (dp.count(r) && dp[r].count(c) && dp[r][c].count(K))
            return dp[r][c][K];
        if (r < 0 || r >= N || c < 0 || c >= N)
            return 0;
        if (K == 0)
            return 1;
        double total = knightProbability(N, K - 1, r - 1, c - 2) + knightProbability(N, K - 1, r - 2, c - 1) + knightProbability(N, K - 1, r - 1, c + 2) + knightProbability(N, K - 1, r - 2, c + 1) + knightProbability(N, K - 1, r + 1, c + 2) + knightProbability(N, K - 1, r + 2, c + 1) + knightProbability(N, K - 1, r + 1, c - 2) + knightProbability(N, K - 1, r + 2, c - 1);
        double res = total / 8;
        dp[r][c][K] = res;
        return res;
    }
};