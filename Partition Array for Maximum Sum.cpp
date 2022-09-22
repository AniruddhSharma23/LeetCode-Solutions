class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int curr_max = 0;
            int m = 0;
            for (int j = 1; j <= k && (i - j) >= 0; j++)
            {
                curr_max = max(curr_max, arr[i - j]);
                m = max(m, dp[i - j] + curr_max * j);
            }
            dp[i] = m;
        }
        return dp[n];
    }
};