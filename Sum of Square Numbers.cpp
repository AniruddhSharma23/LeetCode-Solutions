class Solution
{
public:
    bool isPerfect(long int k)
    { // function that return true if we found the sqrt of k
        if (k == 0 || k == 1)
            return true;
        long int l = 0;
        long int r = k / 2; // sqrt of a number is always less than its half
        while (l <= r)
        {
            long int m = l + (r - l) / 2;
            if (m * m < k)
                l = m + 1;
            else if (m * m == k)
                return true;
            else
                r = m - 1;
        }
        return false;
    }
    bool judgeSquareSum(int c)
    {
        if (c <= 2)
            return true; // c==0 then a=0,b=0 || c==1 then a=1,b=0 || c==2 then a=1,b=1
        for (long int i = 0; i * i <= c; i++)
        {
            long int k = c - (i * i);
            // check if k is a perfect square or not
            if (isPerfect(k))
            {
                return true;
            }
        }
        return false;
    }
};