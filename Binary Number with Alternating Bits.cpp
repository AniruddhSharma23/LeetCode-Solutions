class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int k = n & 1;
        n /= 2;
        while (n > 0)
        {
            if ((n & 1) == k)
            {
                return false;
            }
            k = n & 1;
            n /= 2;
        }
        return true;
    }
};