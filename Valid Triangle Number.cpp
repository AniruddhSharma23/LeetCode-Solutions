class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        for (int k = 2; k < n; k++)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    s += (j - i);
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return s;
    }
};