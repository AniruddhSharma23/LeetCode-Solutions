class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        int pos = 0, neg = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                pos = 0;
                neg = 0;
            }
            else if (nums[i] < 0)
            {
                int temp = pos;
                pos = (neg != 0) ? neg + 1 : 0;
                neg = pos + 1;
            }
            else
            {
                if (neg)
                    neg++;
                pos++;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};