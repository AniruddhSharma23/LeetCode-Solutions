class Solution
{
public:
    bool isPrefix(string s, string x)
    {
        int ns = s.length();
        int nx = x.length();
        int i = 0;
        int j = 0;
        while (i < ns && j < nx)
        {
            if (s[i] != x[j])
            {
                return false;
            }
            i++;
            j++;
        }
        return (j == nx);
    }
    int prefixCount(vector<string> &words, string pref)
    {
        int k = 0;
        for (auto s : words)
        {
            if (isPrefix(s, pref))
            {
                k++;
            }
        }
        return k;
    }
};