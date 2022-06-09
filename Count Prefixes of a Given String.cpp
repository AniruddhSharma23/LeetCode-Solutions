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
    int countPrefixes(vector<string> &words, string s)
    {
        int k = 0;
        for (auto x : words)
        {
            if (isPrefix(s, x))
            {
                k++;
            }
        }
        return k;
    }
};