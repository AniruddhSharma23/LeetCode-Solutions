class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<int, int> mp;
        int k = 0;
        for (char x : s)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            if ((x.second) % 2 == 1)
            {
                k += 1;
            }
        }
        if (k > 1)
        {
            return s.length() - k + 1;
        }
        else
        {
            return s.length();
        }
    }
};