class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        unordered_map<int, unordered_set<int>> mp;
        int n = logs.size();
        for (int i = 0; i < n; i++)
        {
            mp[logs[i][0]].insert(logs[i][1]);
        }
        unordered_map<int, int> mp2;
        for (auto x : mp)
        {
            mp2[x.second.size()]++;
        }
        vector<int> v(k, 0);
        for (int i = 1; i <= k; i++)
        {
            if (mp2.find(i) != mp2.end())
            {
                v[i - 1] = mp2[i];
            }
        }
        return v;
    }
};