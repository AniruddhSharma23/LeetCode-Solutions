class Solution
{
public:
    int mod = 1e9 + 7;
    int primes(int n)
    {
        vector<bool> check(n + 1, true);
        for (int i = 2; i * i <= n; i++)
            if (check[i] == true)
                for (int j = i * i; j <= n; j += i)
                    check[j] = false;
        int cnt = 0;
        for (int i = 2; i <= n; i++)
            if (check[i] == true)
                cnt++;
        return cnt;
    }
    long long fact(int n)
    {
        if (n == 0)
            return 1;
        return (n * fact(n - 1)) % mod;
    }
    int numPrimeArrangements(int n)
    {
        int p = primes(n);
        int np = n - p;
        long long ans = (fact(p) % mod * fact(np) % mod) % mod;
        return ans;
    }
};