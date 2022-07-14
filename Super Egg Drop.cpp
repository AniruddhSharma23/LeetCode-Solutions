class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1) // 1 egg and j floors
                    dp[i][j] = j;
                else if (j == 1) // i number of eggs and 1 floor
                    dp[i][j] = 1;
                else
                {
                    int ans = INT_MAX, temp = 0, l = 0, h = j;
                    while (l <= h)
                    {
                        int m = l + (h - l) / 2;
                        int it_break = dp[i - 1][m - 1];
                        int doesnot_break = dp[i][j - m];
                        temp = 1 + max(it_break, doesnot_break);
                        if (it_break < doesnot_break)
                            l = m + 1;
                        else
                            h = m - 1;
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[k][n];
    }
};
/*
 * Let’s say we drop the egg from the xth floor
 * It breaks
 * Now we need to check for (x-1) floors only and we have (e-1) eggs left
 * So call dp[i - 1][x - 1]
 * Doesn’t break:
 * Now we need to check for (f-x) floors and we have (e) eggs remaining
 * So call dp[e][f-x]
 * We need to consider the worst case so we take the max of above two cases
 * Now we can drop it from any floor from 0 to n
 * So we calculate the number of trials needed if we drop from xth floor where x goes from 0 to n
 * And as we want minimum number of trials so we take the minimum of all these values
 * I.e. ans = min(ans, 1+ max( dp[i - 1][x - 1], dp[e][f-x] ))
 * +1 because we already drop a egg
 */