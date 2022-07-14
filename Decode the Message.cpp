class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        int nk = key.length();
        int nm = message.length();
        unordered_map<char, char> mp;
        int curr = 0;
        for (int i = 0; i < nk; i++)
        {
            if (key[i] != ' ')
            {
                if (mp.find(key[i]) == mp.end())
                {
                    mp[key[i]] = 'a' + curr;
                    curr++;
                }
            }
        }
        string s = "";
        for (auto x : message)
        {
            if (x == ' ')
                s += ' ';
            else
                s += mp[x];
        }
        return s;
    }
};