class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] && nums[i] - nums[j] <= k)
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};