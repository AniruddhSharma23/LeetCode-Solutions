class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> v;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp[nums[i][j]]++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (mp[nums[0][i]] == n)
            {
                v.push_back(nums[0][i]);
            }
        }

        sort(v.begin(), v.end());
        return v;
    }
};