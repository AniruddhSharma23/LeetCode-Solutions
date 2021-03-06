class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        if (n == 1)
        {
            return true;
        }
        unordered_map<char, int> mp;
        for (string s : words)
        {
            for (char c : s)
            {
                mp[c]++;
            }
        }

        for (auto &x : mp)
        {
            if (x.second % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};