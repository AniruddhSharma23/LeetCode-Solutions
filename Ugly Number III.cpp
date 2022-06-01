class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long m = max(a, max(b, c));
        long long m1 = min(a, (min(c, b)));
        long long i = m1;
        long long k = 0;
        while (i < n * m)
        {
            if (i % a == 0 || i % b == 0 || i % c == 0)
            {
                k++;
            }
            if (k == n)
            {
                break;
            }
            i++;
        }
        return i;
    }
};