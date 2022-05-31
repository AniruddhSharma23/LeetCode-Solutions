class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {

        int n = arr.size();
        if (n == 0)
        {
            return {};
        }
        vector<int> v(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        sort(v.begin(), v.end());
        mp[v[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = mp[v[i - 1]] + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};