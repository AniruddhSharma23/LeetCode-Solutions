class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);
        v[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            v[i] = nums[i] + v[i - 1];
        }
        int m = *min_element(v.begin(), v.end());
        if (m <= 0)
        {
            return abs(m) + 1;
        }
        return 1;
    }
};