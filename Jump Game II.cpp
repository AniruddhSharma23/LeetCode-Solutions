/*

Method:

    we follow the tabulation method
    create a dp int array such that
    dp[i] = minimum number of jumps require to reach the end from this index
    now at every ith element we can take 1 to nums[i] number of steps so for every index between 1 to nums[i] we find the index at which we will get minimum number of steps
    then we set the dp[i] = 1+m
    +1 because one step is needed to land to that index at which we found m
    at last we return dp[0] because we want to know the minimum number of steps required to reach end if we start from 0th index

Time Complexity: O(n)
    as the loop runs n times

Space Complexity: O(n)
    as we created a dp array of size n

*/

// Code:

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0); // minimum number of steps to reach end from ith position
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int m = 10000; // variable to store minimum number of steps
            for (int j = 1; j <= nums[i] && j + i < n; j++)
            {
                m = min(dp[j + i], m);
            }
            dp[i] = m + 1;
        }
        return dp[0];
    }
};