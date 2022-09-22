class Solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums, vector<int> &multipliers, int n, int m, int l, int k)
    {
        if (dp[l][k] != INT_MIN)
            return dp[l][k];
        int r = n - 1 + l - k;
        if (k == m)
            return 0;
        int a = solve(nums, multipliers, n, m, l + 1, k + 1) + multipliers[k] * nums[l];
        int b = solve(nums, multipliers, n, m, l, k + 1) + multipliers[k] * nums[r];
        return dp[l][k] = max(a, b);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(nums, multipliers, n, m, 0, 0);
    }
};