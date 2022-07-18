class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1)); // dp[i][j] = max sum that a player can obtain if he start from index i and M = j
        vector<int> remaining(n + 1, 0);                   // sum of the piles from index i to the end
        for (int i = n - 1; i >= 0; i--)
            remaining[i] = remaining[i + 1] + piles[i];
        for (int i = 0; i <= n; i++)
            dp[i][n] = remaining[i];
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                for (int x = 1; x <= 2 * j && i + x <= n; x++)
                {
                    dp[i][j] = max(dp[i][j], remaining[i] - dp[i + x][max(j, x)]);
                }
            }
        }
        return dp[0][1];
    }
};

/*
 * Approach:
 * ```dp[i][j] = max sum that a player can obtain if he start from index i and M = j```
 * Let the sum of alex = alex_sum
 * Let the sum of bob = bob_sum
 * now let's suppose we are at ith pile and its the turn of alex and current```M = j```
 * which means all the ```(0,1.....,i-1) piles are already used```
 * ```let the sum of remaining piles = S```
 * alex can choose between 1 to 2*j number of piles
 * now there can be several cases
 * if alex choose 1 pile only
 * i.e. ```x=1```
 * so, ```bob_sum = dp[i+1][max(j,1)]```
 * as ```dp[i+1][max(j,1)] = max sum that a player can obtain if he start from index i+1 and M = max(j,1)```
 * if alex choose 2 piles only
 * i.e. ```x=2```
 * so, ```bob_sum = dp[i+2][max(j,2)]```
 * if alex choose 2*j piles
 * i.e. ```x=2*j```
 * so, ```bob_sum = dp[i+2*j][max(j,2*j)]```
 * now for each case
 * the sum remaining for alex =
 * ```alex_sum = S-bob_sum```
 * we want alex to win so we want alex_sum to be as max as possible
 * so we will choose the value of x(from 1 to 2*j) such that the alex_sum is as large as possible
 * ```our ans will be stored in dp[0][1]```
 * as we start from index=0 and with M=1
 */