class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> v;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                v.push_back(i);
            }
        }
        int nv = v.size();
        vector<int> p;
        for (int i = 0; i < n; i++)
        {
            int m = INT_MAX;
            for (int j = 0; j < nv; j++)
            {
                m = min(abs(i - v[j]), m);
            }
            p.push_back(m);
        }
        return p;
    }
};