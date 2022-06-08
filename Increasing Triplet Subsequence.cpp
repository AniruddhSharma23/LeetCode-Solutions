class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int m1 = nums[0]; // minimum
        int m2 = INT_MAX; // maximum
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > m2)
            {
                return true;
            }
            else if (nums[i] > m1 && nums[i] < m2)
            {
                m2 = nums[i];
            }
            else if (nums[i] < m1)
            {
                m1 = nums[i];
            }
        }
        return false;
    }
};