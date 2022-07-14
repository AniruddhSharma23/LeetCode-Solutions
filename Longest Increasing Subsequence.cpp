class Solution
{
public:
    int findCeil(vector<int> &tail, int x)
    {
        int k = tail.size();
        int l = 0, r = k - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (tail[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tail(1, nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > tail.back())
                tail.push_back(nums[i]);
            else
                tail[findCeil(tail, nums[i])] = nums[i];
        }
        return tail.size();
    }
};

// dp solution

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};
