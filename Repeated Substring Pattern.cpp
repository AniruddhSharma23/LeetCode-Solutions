class Solution
{
private:
    int kmp_algo(string s)
    {
        int len = 0, i = 1, n = s.size();
        vector<int> kmp(n, 0);
        while (i < n)
        {
            if (s[i] == s[len])
            {
                kmp[i++] = ++len;
            }
            else
            {
                if (len)
                    len = kmp[len - 1];
                else
                    kmp[i++] = 0;
            }
        }
        return kmp.back();
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        int len = kmp_algo(s);
        int lps = n - len;
        return (len % lps == 0 and len != 0);
    }
};