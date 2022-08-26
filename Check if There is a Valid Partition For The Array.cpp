class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[1] = nums[0] == nums[1];
        for (int i = 2; i < n; i++)
        {
            bool x = (nums[i] == nums[i - 1]);
            bool y = ((nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) || (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1));
            dp[i] = (x && ((i - 2) >= 0 ? dp[i - 2] : true) || y && ((i - 3) >= 0 ? dp[i - 3] : true));
        }
        return dp[n - 1];
    }
};