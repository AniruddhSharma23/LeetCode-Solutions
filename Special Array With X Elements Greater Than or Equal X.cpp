class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            int k = n;
            int l = 0;
            int h = n - 1;
            while (h >= l)
            {
                int m = l + (h - l) / 2;
                if (nums[m] >= i)
                {
                    k = m;
                    h = m - 1;
                }
                else
                    l = m + 1;
            }

            if ((n - k) == i)
                return i;
        }
        return -1;
    }
};