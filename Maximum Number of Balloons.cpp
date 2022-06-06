class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mp;
        int n = text.length();
        mp['b'] = mp['a'] = mp['l'] = mp['o'] = mp['n'] = 0;
        for (char c : text)
        {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
                mp[c]++;
        }
        int k = 0;
        while (mp['b'] >= 1 && mp['a'] >= 1 && mp['l'] >= 2 && mp['o'] >= 2 && mp['n'] >= 1)
        {
            k++;
            mp['b']--;
            mp['a']--;
            mp['l'] -= 2;
            mp['o'] -= 2;
            mp['n']--;
        }
        return k;
    }
};