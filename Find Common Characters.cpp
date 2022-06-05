class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int n = words.size();
        map<char, int> mp;
        for (auto c : words[0])
        {
            mp[c]++;
        }
        map<char, int> m1;
        for (auto &k : words)
        {
            m1.clear();
            for (auto c : k)
            {
                m1[c]++;
            }
            for (auto &x : mp)
            {

                x.second = min(x.second, m1[x.first]);
            }
        }
        vector<string> v;
        string s;
        for (auto &x : mp)
        {
            while (x.second != 0)
            {
                s = x.first;
                v.push_back(s);
                x.second--;
            }
        }
        return v;
    }
};