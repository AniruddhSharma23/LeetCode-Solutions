class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n <= 3)
        {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i < n; i += 6)
        {
            if (n % (i) == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }
    int count(int n)
    {
        int k = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            k++;
        }
        return k;
    }
    int countPrimeSetBits(int left, int right)
    {
        int k = 0;
        for (int i = left; i <= right; i++)
        {
            int p = count(i);
            if (isPrime(p) == true)
            {
                k++;
            }
        }
        return k;
    }
};