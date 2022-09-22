class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> odd_before(n);
        vector<int> even_before(n);
        vector<int> odd_after(n);
        vector<int> even_after(n);
        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < n; i++)
        {
            odd_before[i] = odd_sum;
            even_before[i] = even_sum;
            if (i % 2 == 0)
                even_sum += nums[i];
            else
                odd_sum += nums[i];
        }
        odd_sum = 0, even_sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            odd_after[i] = odd_sum;
            even_after[i] = even_sum;
            if (i % 2 == 0)
                even_sum += nums[i];
            else
                odd_sum += nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (odd_before[i] + even_after[i] == odd_after[i] + even_before[i])
                ans++;
        }
        return ans;
    }
};