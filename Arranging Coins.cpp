class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long l = 1, r = 1000000, m;
        while (l <= r)
        {
            m = (r + l) / 2;
            if (m * (m + 1) / 2 == n)
            {
                return m;
            }
            if (m * (m + 1) / 2 > n)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l - 1;
    }
};