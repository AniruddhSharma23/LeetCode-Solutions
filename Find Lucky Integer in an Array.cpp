class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        vector<int> v;
        for (auto x : mp)
        {
            if (x.first == x.second)
            {
                v.push_back(x.first);
            }
        }
        if (v.size() != 0)
        {
            sort(v.begin(), v.end());
            return v[v.size() - 1];
        }
        return -1;
    }
};