class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        vector<string> v;
        unordered_map<char, int> mp;
        for (char c : s1)
        {
            mp[c] = 1;
            mp[toupper(c)] = 1;
        }
        for (char c : s2)
        {
            mp[c] = 2;
            mp[toupper(c)] = 2;
        }
        for (char c : s3)
        {
            mp[c] = 3;
            mp[toupper(c)] = 3;
        }
        for (auto c : words)
        {
            int n = c.length();
            int k = 1;
            for (int i = 1; i < n; i++)
            {
                if (mp[c[i]] != mp[c[i - 1]])
                {
                    k = 0;
                    break;
                }
            }
            if (k == 1)
            {
                v.push_back(c);
            }
        }
        return v;
    }
};