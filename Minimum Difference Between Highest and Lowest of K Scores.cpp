class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = INT_MAX;
        for (int i = 0; i <= n - k; i++)
        {
            m = min(nums[i + k - 1] - nums[i], m);
        }
        return m;
    }
};