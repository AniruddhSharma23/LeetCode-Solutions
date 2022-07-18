class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int ans = 0;
        int max_so_far = values[0] + 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, max_so_far + values[i] - i);
            max_so_far = max(max_so_far, values[i] + i);
        }
        return ans;
    }
};