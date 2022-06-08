class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v(2);
        v[0] = -1;
        v[1] = -1;
        if (v.size() == 0)
        {
            return v;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            if ((nums[l] == target) && (nums[r] == target))
            {
                v[0] = l;
                v[1] = r;
                return v;
            }
            else if ((nums[l] != target) && (nums[r] == target))
            {
                v[1] = r;
                l++;
            }
            else if ((nums[l] == target) && (nums[r] != target))
            {
                v[0] = l;
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        return v;
    }
};