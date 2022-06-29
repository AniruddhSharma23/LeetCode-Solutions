class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> mp;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (mp.find(s[i]) == mp.end())
            {
                mp[s[i]]++;
            }
            else
            {
            }
        }
    }
};