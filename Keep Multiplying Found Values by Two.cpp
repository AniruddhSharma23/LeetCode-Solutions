class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(original) != mp.end())
            {
                original *= 2;
            }
            else
            {
                break;
            }
        }
        return original;
    }
};