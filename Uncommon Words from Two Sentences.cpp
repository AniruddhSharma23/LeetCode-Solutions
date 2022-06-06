class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> mp;
        stringstream ss{s1 + " " + s2};
        string k;
        while (ss >> k)
        {
            mp[k]++;
        }
        vector<string> v;
        for (auto &x : mp)
        {
            if (x.second == 1)
            {
                v.push_back(x.first);
            }
        }
        return v;
    }
};