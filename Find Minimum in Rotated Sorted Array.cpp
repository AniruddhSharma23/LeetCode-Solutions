class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if (nums[r] > nums[0])
        {
            return nums[0];
        }
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= nums[0])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[0])
            {
                r = m;
            }
        }
        return nums[l];
    }
};