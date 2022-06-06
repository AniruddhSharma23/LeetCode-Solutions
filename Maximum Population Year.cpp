class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int k = 1e5;
        int m = 0;
        int n = logs.size();
        unordered_map<int, int> mp;
        for (auto x : logs)
        {
            auto b = x[0];
            auto d = x[1];
            for (auto j = b; j < d; j++)
            {
                mp[j]++;
            }
        }
        for (auto &x : mp)
        {
            if (m < x.second)
            {
                k = x.first;
                m = x.second;
            }
            else if (m == x.second)
            {
                k = min(k, x.first);
            }
        }
        return k;
    }
};