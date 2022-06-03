class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int p = 0;
        int m = 1;
        while (i < n)
        {
            if (nums[i] == 0)
            {
                p++;
            }
            if (p > k)
            {
                while (p > k)
                {
                    if (nums[j] == 0)
                    {
                        p--;
                    }
                    j++;
                }
            }
            else
            {
                m = max(i - j + 1, m);
            }
            i++;
        }
        return m;
    }
};