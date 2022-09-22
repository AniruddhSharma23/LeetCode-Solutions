class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.length();
        vector<int> r(26, 0);
        vector<int> l(26, 0);
        int ans = 0;
        for (char c : s)
        {
            r[c - 'a']++;
        }
        int rs = 0;
        int ls = 0;
        for (auto x : r)
            if (x > 0)
                rs++;
        for (char c : s)
        {
            r[c - 'a']--;
            if (r[c - 'a'] == 0)
                rs--;
            l[c - 'a']++;
            if (l[c - 'a'] == 1)
                ls++;
            if (ls == rs)
                ans++;
        }
        return ans;
    }
};