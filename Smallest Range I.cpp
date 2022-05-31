class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int m1 = *max_element(nums.begin(), nums.end());
        int m2 = *min_element(nums.begin(), nums.end());
        if (m1 - (2 * k) <= m2)
        {
            return 0;
        }
        return m1 - m2 - (2 * k);
    }
};