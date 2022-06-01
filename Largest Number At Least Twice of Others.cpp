class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        int p = 0;
        int m = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (m < 2 * nums[i] && m != nums[i])
            {
                return -1;
            }
            if (m == nums[i])
            {
                p = i;
            }
        }
        return p;
    }
};