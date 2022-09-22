/*

Method:

    we follow the tabulation method
    create a dp boolean array such that
    dp[i] = denotes whether you can reach the end from this index or not
    now at every ith element we can take 1 to nums[i] number of steps so we check if there is any index between 1 to nums[i] where the condition is true if it is
    then we set this dp[i] as true as it's possible to reach the end from this index
    at last we return dp[0] because we want to know whether we can reach the last index starting from the first index

Time Complexity: O(n)
    as the loop runs n times

Space Complexity: O(n)
    as we created a dp array of size n

*/

// Code:

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i] && j + i < n; j++)
            {
                if (dp[j + i])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int farthest = 0, i = 0;
        for (i; i < n; i++)
        {
            if (i > farthest)
                return false;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};