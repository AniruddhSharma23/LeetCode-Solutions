class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        int k = 0;
        for (int x : s)
        {
            k ^= x;
        }
        int a = k;
        for (int i = 0; i < n; i++)
        {
            a ^= nums[i];
        }
        int d = a;
        for (int i = 1; i <= n; i++)
        {
            k ^= i;
        }
        int m = k;
        vector<int> v;
        v.push_back(d);
        v.push_back(m);
        return v;
    }
};