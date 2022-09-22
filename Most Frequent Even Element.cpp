class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for (auto x : nums)
            if (x % 2 == 0)
                mp[x]++;
        int ans = -1;
        int m = 0;
        for (auto &x : mp)
            if (m < x.second)
                ans = x.first, m = x.second;
        return ans;
    }
};