class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto x : mp)
        {
            v.push_back(x.first);
        }
        sort(v.begin(), v.end());
        int p = 0;
        for (int i = 1; i < v.size() - 1; i++)
        {
            p += mp[v[i]];
        }
        return p;
    }
};