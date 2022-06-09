class Solution
{
public:
    string sortString(string s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        vector<char> v;
        for (char c : s)
        {
            if (mp.find(c) == mp.end())
            {
                v.push_back(c);
            }
            mp[c]++;
        }
        vector<int> p;
        sort(v.begin(), v.end());
        p = v;
        reverse(p.begin(), p.end());
        string k = "";
        int i = 0;
        while (k.size() < s.size())
        {
            if (i % 2 == 0)
            {
                for (char c : v)
                {
                    if (mp[c] > 0)
                    {
                        k += c;
                        mp[c]--;
                    }
                }
            }
            else
            {
                for (char c : p)
                {
                    if (mp[c] > 0)
                    {
                        k += c;
                        mp[c]--;
                    }
                }
            }
        }
        return k;
    }
};