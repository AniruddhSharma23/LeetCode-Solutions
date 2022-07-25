class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        char ans;
        for (char c : s)
        {
            mp[c]++;
            if (mp[c] > 1)
            {
                ans = c;
                break;
            }
        }
        return ans;
    }
};