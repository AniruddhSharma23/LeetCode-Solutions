class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        vector<int> v;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        for (auto &q : queries)
        {
            int k = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            v.push_back(k);
        }
        return v;
    }
};