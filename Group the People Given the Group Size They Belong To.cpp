class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> v;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
            if (mp[groupSizes[i]].size() == groupSizes[i])
            {
                v.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]] = {};
            }
        }
        return v;
    }
};