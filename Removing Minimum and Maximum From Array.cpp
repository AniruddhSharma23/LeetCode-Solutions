class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int mini = min(mx, mn);
        int maxi = max(mx, mn);
        int p1 = maxi + 1;
        int p2 = n - mini;
        int p3 = (mini + 1) + (n - maxi);
        return min(p1, min(p2, p3));
    }
};