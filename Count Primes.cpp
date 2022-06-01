class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> v(n + 1, 1);
        int k = 0;
        v[0] = 0;
        v[1] = 0;
        for (int i = 2; i < sqrt(n); i++)
        {

            for (int j = 2 * i; j <= n; j += i)
            {
                v[j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                k++;
            }
        }
        return k;
    }
};