class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if (n == 0 || (n == 1 && nums[0] == val))
        {
            return 0;
        }
        while (l <= r)
        {
            if (nums[r] == val)
            {
                r--;
            }
            else if (nums[l] == val)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            else
            {
                l++;
            }
        }
        return l;
    }
};