class Solution
{
public:
    typedef pair<int, int> pi;
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<pi> profit;
        int n = costs.size();
        for (int i = 0; i < n; i++)
        {
            auto x = costs[i];
            profit.push_back(make_pair(x[1] - x[0], i));
        }
        sort(profit.begin(), profit.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int index = profit[i].second;
            ans += (i < n / 2) ? costs[index][1] : costs[index][0];
        }
        return ans;
    }
};