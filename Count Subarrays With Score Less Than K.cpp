class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long t = 0;
        int n = nums.size();
        int i = 0;
        int j;
        long long s = nums[0];
        long long ne = 1;
        for (j = 1; j < n; i++)
        {
            while ((s * ne) >= k && i < j - 1)
            {
                s -= nums[i];
                ne--;
                i++;
            }
            if ((s * ne) < k)
            {
                t++;
            }
            if (j < n)
            {
                s += nums[j];
                ne++;
            }
        }
    }
};