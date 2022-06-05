class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        vector<int> a = nums;
        vector<int> b = nums;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        return (a == nums || b == nums);
    }
};