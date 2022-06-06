class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == key)
            {
                mp[nums[i + 1]]++;
            }
        }
        int m = 0;
        int k = 0;
        for (auto &x : mp)
        {
            if (x.second > m)
            {
                m = x.second;
                k = x.first;
            }
        }
        return k;
    }
};