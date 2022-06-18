class Solution
{
public:
    int lengthofPrefix(string &s, int &n)
    {
        vector<int> lps(n);
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < n)
        {
            if (s[i] == s[len])
                lps[i++] = ++len;
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }
        return len;
    }
    string longestPrefix(string s)
    {
        int n = s.length();
        int k = lengthofPrefix(s, n);
        return s.substr(0, k);
    }
};