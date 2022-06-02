class Solution
{
public:
    void radixSort(vector<int> &v, int n)
    {
        int m = *max_element(v.begin(), v.end());
        for (int exp = 1; m / exp > 0; exp *= 10)
        {
            countingSort(v, n, exp);
        }
    }

    void countingSort(vector<int> &v, int n, int exp)
    {
        vector<int> p(10, 0);
        for (int i = 0; i < n; i++)
        {
            int k = (int)(v[i] / exp) % 10;
            p[k]++;
        }
        for (int i = 1; i < 10; i++)
        {
            p[i] += p[i - 1];
        }
        vector<int> q(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int k = (int)(v[i] / exp) % 10;
            q[p[k] - 1] = v[i];
            p[k]--;
        }
        v = q;
    }

    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return abs(nums[0] - nums[1]);
        }
        radixSort(nums, n);
        int m = 0;
        for (int i = 1; i < n; i++)
        {
            m = max(m, nums[i] - nums[i - 1]);
        }
        return m;
    }
};