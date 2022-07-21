class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[n - 1][0];
    }
};
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

/*
**Approach:**

* ```dp[i] = max profit on the ith day```
* at the ith day, we have three choices
    * 1. buy
    * 2. sell
    * 3. rest
* we will try each of these option and see in which case we get the max profit
* we can't perform multiple transaction at a same time
* which means
    * if we decide to buy on the i-th day, there should be 0 stock held in our hand before we buy
    * if we decide to sell on the i-th day, there should be exactly 1 stock held in our hand before we sell.
* So, we can divide our problem in two subparts
    * ```dp[i][0] = the maximum profit at the end of the i-th day and with 0 stock in our hand AFTER taking the action```
    * ```dp[i][1] = the maximum profit at the end of the i-th day and with 1 stock in our hand AFTER taking the action```
* **for dp[i][0]:**
    * the actions taken on the i-th day can only be rest and sell, since we have 0 stock in our hand at the end of the day.
    * if we choose to rest
        * profit at ith day = profit at (i-1)day when we have 0 stocks in our hand after taking the action
        * ```dp[i][0] = dp[i-1][0]```
    * if we choose to sell
        * profit at ith day = profit at (i-1)day when we have 1 stocks in our hand after taking the action + prices[i]
        * ```dp[i][0] = dp[i-1][1]+prices[i]```
    * so final profit
        * ```dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])```
* **for dp[i][1]:**
    * the actions taken on the i-th day can only be rest and buy, since we have 1 stock in our hand at the end of the day.
    * if we choose to rest
        * profit at ith day = profit at (i-1)day when we have 1 stocks in our hand after taking the action
        * ```dp[i][1] = dp[i-1][1]```
    * if we choose to sell
        * profit at ith day = profit at (i-1)day when we have 0 stocks in our hand after taking the action - prices[i]
        * ```dp[i][1] = dp[i-1][0]-prices[i]```
    * so final profit
        * ```dp[i][0] = max(dp[i-1][1],dp[i-1][0]-prices[i])```
* **The final equations are:**
    * **```dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])```**
    * **```dp[i][0] = max(dp[i-1][1],dp[i-1][0]-prices[i])```**
* Now, we have to pay the fee at each transaction
* the profit after buying or selling the stock on the i-th day should be subtracted by this amount, therefore the new recurrence relations will be either
    * **```dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])```**
    * **```dp[i][0] = max(dp[i-1][1],dp[i-1][0]-prices[i]-fee)```**
    * or
    * **```dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]-fee)```**
    * **```dp[i][0] = max(dp[i-1][1],dp[i-1][0]-prices[i])```**
* Note we have two options as for when to subtract the fee.
    * This is because each transaction is characterized by two actions coming as a pair
        * buy and sell.
* The fee can be paid either when we buy the stock (corresponds to the first set of equations) or when we sell it (corresponds to the second set of equations)
* **```ans = dp[n-1][0]```**
    * we always have larger profit if we end up with 0 stock in hand
*/
