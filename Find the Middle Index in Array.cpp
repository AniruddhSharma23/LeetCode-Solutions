class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {

        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;
        int r = s;
        for (int i = 0; i < n; i++)
        {
            r -= nums[i];
            if (i >= 1)
            {
                l += nums[i - 1];
            }
            if (l == r)
            {
                return i;
            }
        }
        return -1;
    }
};