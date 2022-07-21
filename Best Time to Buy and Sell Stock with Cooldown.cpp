class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ti0 = 0;
        int ti1 = INT_MIN;
        int ti_pre = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            int ti0_old = ti0;
            ti0 = max(ti0, ti1 + prices[i]);
            ti1 = max(ti1, ti_pre - prices[i]);
            ti_pre = ti0_old;
        }
        return ti0;
    }
};