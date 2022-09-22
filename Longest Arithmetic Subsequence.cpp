class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[i][j] = length of AP with last element at index j and 2nd last at index i
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = nums[j] - nums[i];
                int k = nums[j] - 2 * d; // 3rd last element
                if (mp.find(k) != mp.end())
                {
                    int pos = mp[k];
                    dp[i][j] = max(dp[i][j], 1 + dp[pos][i]);
                }
                else
                {
                    dp[i][j] = 2;
                }
                ans = max(ans, dp[i][j]);
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};