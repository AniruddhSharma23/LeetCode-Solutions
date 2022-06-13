class Solution
{
public:
    int sum[10] = {};
    int ans = INT_MAX;
    void distribute(vector<int> &cookies, int n, int k)
    {
        if (n == cookies.size())
        {
            int mx = 0;
            for (int i = 0; i < k; i++)
            {
                mx = max(mx, sum[i]);
            }
            ans = min(ans, mx);
            return;
        }
        for (int i = 0; i < k; i++)
        {
            sum[i] += cookies[n];
            distribute(cookies, n + 1, k);
            sum[i] -= cookies[n];
        }
    }
    int distributeCookies(vector<int> &cookies, int k)
    {
        distribute(cookies, 0, k);
        return ans;
    }
};