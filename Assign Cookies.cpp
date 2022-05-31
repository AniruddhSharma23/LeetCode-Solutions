class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ng = g.size();
        int ns = s.size();
        if (ns == 0)
        {
            return 0;
        }
        int j = 0;
        int k = 0;
        int i = 0;
        while (i < ns && j < ng)
        {
            if (s[i] >= g[j])
            {
                k++;
                j++;
            }
            i++;
        }

        return k;
    }
};