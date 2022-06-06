class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_map<char, int> mp;
        for (char c : brokenLetters)
        {
            mp[c]++;
        }
        int n = text.length();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            int p = 0;
            while (text[i] != ' ')
            {
                if (mp.find(text[i]) != mp.end())
                {
                    p = -1;
                }
                i++;
            }
            if (p != -1)
            {
                k++;
            }
        }
        return k;
    }
};