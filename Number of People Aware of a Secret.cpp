class Solution
{
public:
    int k = 1;
    int mod = 1e9 + 7;
    int curr = 1;
    void solve(int n, int delay, int forget)
    {
        while (curr <= n)
        {
            if (curr > delay && curr <= forget)
            {
                k = (k + 1) % mod;
                solve(n - curr + 1, delay, forget);
            }
            if (curr > forget)
            {
                k = (k - 1) % mod;
                return;
            }
            curr++;
        }
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {

        solve(n, delay, forget);
        return k % mod;
    }
};