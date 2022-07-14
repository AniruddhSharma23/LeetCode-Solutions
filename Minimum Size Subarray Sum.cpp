class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0, s = 0, len = INT_MAX;
        while (r < n)
        {
            s += nums[r++];
            while (s >= target)
            {
                len = min(len, r - l);
                s -= nums[l++];
            }
        }
        return (len == INT_MAX) ? 0 : len;
    }
};