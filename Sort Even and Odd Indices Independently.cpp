class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> e;
        vector<int> o;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                o.push_back(nums[i]);
            }
            else
            {
                e.push_back(nums[i]);
            }
        }
        sort(o.begin(), o.end(), greater<int>());
        sort(e.begin(), e.end());
        int e1 = 0;
        int o1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = e[e1];
                e1++;
            }
            else
            {
                nums[i] = o[o1];
                o1++;
            }
        }
        return nums;
    }
};