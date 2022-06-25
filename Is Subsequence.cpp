class Solution
{
public:
    int lcs(string s, string t, int m, int n)
    {
        int a[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    a[i][j] = 0;
                }
                else
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        a[i][j] = 1 + a[i - 1][j - 1];
                    }
                    else
                    {
                        a[i][j] = max(a[i - 1][j], a[i][j - 1]);
                    }
                }
            }
        }
        return a[m][n];
    }
    bool isSubsequence(string s, string t)
    {

        return lcs(s, t, s.length(), t.length()) == s.length();
    }
};