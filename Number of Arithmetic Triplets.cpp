class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (mp.find(x + diff) != mp.end())
            {
                int j = mp[x + diff];
                if (j > i)
                {
                    if (mp.find(x + 2 * diff) != mp.end())
                        if (mp[x + 2 * diff] > j)
                            ans++;
                }
            }
        }
        return ans;
    }
};