class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        int a = 0, b = 0, n = nums.size();
        for (auto x : mp)
            if (x.second % 2 != 0)
                b++;
        a = (n - b) / 2;
        return {a, b};
    }
};