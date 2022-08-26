class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (auto val : nums)
                if (val <= i)
                    dp[i] += dp[i - val];
        return dp[target];
    }
};

/*
Approach:
dp[i][j] = number of combinations we can get with sum=i for coins from 1 to j
ans = dp[sum][n]
dp[i][j] = dp[i][j-1]
ignore the jth coin
let th
dp[i][j] = dp[i-val][j]
add the number of combination we can get with sum = i-val for coins from 1 to j
*/
