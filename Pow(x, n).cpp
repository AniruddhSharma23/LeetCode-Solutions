class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        double res = 1;
        if (n < 0)
            x = 1 / x;
        long num = abs(n);
        while (num)
        {
            if (num & 1)
            {
                res *= x;
            }
            x *= x;
            num >>= 1;
        }
        return res;
    }
};