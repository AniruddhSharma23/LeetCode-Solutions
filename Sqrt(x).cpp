class Solution
{
public:
    int mySqrt(int x)
    {
        long long l = 1;
        long long r = x;
        long long k = 0;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            long long sq = m * m;
            if (sq == x)
            {
                return m;
            }
            else if (sq > x)
            {
                r = m - 1;
            }
            else
            {
                k = m;
                l = m + 1;
            }
        }
        return k;
    }
};