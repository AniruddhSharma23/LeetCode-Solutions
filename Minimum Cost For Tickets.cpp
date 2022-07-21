class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(366, 0);
        unordered_set st(days.begin(), days.end());
        for (int i = 1; i < 366; i++)
        {
            if (st.find(i) == st.end()) // non-travel day
                dp[i] = dp[i - 1];
            else
            {
                int a = dp[i - 1] + costs[0];          // cost 1 day before + cost of 1 day pass
                int b = dp[max(0, i - 7)] + costs[1];  // cost 7 days before + cost of 7 day pass
                int c = dp[max(0, i - 30)] + costs[2]; // cost 30 days before + cost of 30 day pass
                dp[i] = min({a, b, c});
            }
        }
        return dp[365];
    }
};