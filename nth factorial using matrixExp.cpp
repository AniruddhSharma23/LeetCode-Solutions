typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int mod = 1e9 + 7;

vvl matrixMultiplication(const vvl &a, const vvl &b)
{
    int n = a.size();
    int m = b[0].size();
    vvl c(n, vl(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
vvl matrixExponent(const vvl &a, int n)
{
    if (n == 1)
        return a;
    vvl c = matrixExponent(a, n / 2);
    vvl d = matrixMultiplication(c, c);
    if (n % 2 == 1)
        d = matrixMultiplication(d, a);
    return d;
}
int Solution::solve(int n)
{
    if (n == 1 || n == 2)
        return 1;
    vvl a = {{1, 1}, {1, 0}};
    vvl b = {{1}, {1}};
    return matrixMultiplication(matrixExponent(a, n - 2), b)[0][0];
}
