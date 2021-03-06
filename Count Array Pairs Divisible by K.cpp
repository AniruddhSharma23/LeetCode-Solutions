class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        long long p = 0;
        unordered_map<int, int> mp;
        for (auto ele : nums)
        {
            long long gcd = __gcd(k, ele);
            long long x = k / gcd;

            for (auto it : mp)
                if (it.first % x == 0)
                    p += it.second;
            mp[gcd]++;
        }
        return p;
    }
};