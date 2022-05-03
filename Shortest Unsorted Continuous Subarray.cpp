class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int i, n, l, r;
        l = -1;
        r = -1;
        n = nums.size();
        vector<int> v;
        v = nums;
        sort(v.begin(), v.end());
        if (v == nums)
        {
            return 0;
        }
        for (i = 0; i < n; i++)
        {
            if (v[i] != nums[i] && l != -1)
            {
                r = i;
            }
            else if (v[i] != nums[i] && l == -1)
            {
                l = i;
            }
        }
        return r - l + 1;
    }
};