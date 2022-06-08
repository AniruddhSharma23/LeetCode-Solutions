class Solution
{
public:
    int trailingZeroes(int n)
    {
        int k = 5;
        int z = 0;
        while ((n / k) > 0)
        {
            z += n / k;
            k *= 5;
        }
        return z;
    }
};