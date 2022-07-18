class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0); // dp[i] = number of arithmetic sequences ending with nums[i]
        if (nums[1] - nums[0] == nums[2] - nums[1])
            dp[2] = 1;
        for (int i = 3; i < n; i++)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        int ans = accumulate(dp.begin(), dp.end(), 0);
        return ans;
    }
};

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int prev_diff = nums[1] - nums[0];
        int diff = 0, count = 0, curr = 0;
        for (int i = 1; i < n - 1; i++)
        {
            diff = nums[i + 1] - nums[i];
            if (diff == prev_diff)
                curr++;
            else
            {
                prev_diff = diff;
                curr = 0;
            }
            count += curr;
        }
        return count;
    }
};