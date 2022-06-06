class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int n = s.length();
        int k = -1;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                k = max(k, mp[s[i]] - i - 1);
            }
        }
        return k;
    }
};