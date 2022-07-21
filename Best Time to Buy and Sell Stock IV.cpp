class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (k >= n / 2)
        {
            int ti0 = 0;
            int ti1 = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                int ti0_old = ti0;
                ti0 = max(ti0, ti1 + prices[i]);
                ti1 = max(ti1, ti0_old - prices[i]);
            }
            return ti0;
        }
        vector<int> ti0(k + 1, 0);
        vector<int> ti1(k + 1, INT_MIN);
        for (int i = 0; i < n; i++)
        {
            for (int j = k; j > 0; j--)
            {
                ti0[j] = max(ti0[j], ti1[j] + prices[i]);
                ti1[j] = max(ti1[j], ti0[j - 1] - prices[i]);
            }
        }
        return ti0[k];
    }
};