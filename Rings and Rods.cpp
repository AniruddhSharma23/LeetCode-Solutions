class Solution
{
public:
    int countPoints(string rings)
    {
        int n = rings.length();
        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < n - 1; i += 2)
        {
            mp[rings[i + 1] - '0'].push_back(rings[i]);
        }
        int k = 0;
        for (auto x : mp)
        {
            vector<char> v;
            v = x.second;
            int r, b, g;
            r = b = g = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == 'R')
                {
                    r++;
                }
                else if (v[i] == 'G')
                {
                    g++;
                }
                else
                {
                    b++;
                }
            }
            if (r >= 1 && b >= 1 && g >= 1)
            {
                k++;
            }
        }
        return k;
    }
};