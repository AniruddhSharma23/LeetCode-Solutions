class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int p = 1;
        int n = nums.size();
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                z++;
            }
            else
            {
                p *= nums[i];
            }
        }

        vector<int> v(n, 0);
        if (z > 1)
        {
            return v;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                v[i] = p;
            }
            else
            {
                if (z == 0)
                {
                    v[i] = p / nums[i];
                }
                else
                {
                    v[i] = 0;
                }
            }
        }
        return v;
    }
};