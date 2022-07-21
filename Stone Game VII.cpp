// Top-Down
class Solution
{
public:
    vector<vector<int>> memo;
    vector<int> preSum;
    int getSum(int i, int j)
    {
        return preSum[j + 1] - preSum[i];
    }
    int dp(int i, int j)
    {
        if (i == j)
            return 0; // only 1 stone, score = 0 -> difference = 0 as well
        if (memo[i][j] != INT_MAX)
            return memo[i][j];
        int s1 = getSum(i + 1, j); // choose ith stone
        int s2 = getSum(i, j - 1); // choose jth stone
        int ans = max(s1 - dp(i + 1, j), s2 - dp(i, j - 1));
        return memo[i][j] = ans;
    }
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        memo.assign(n, vector<int>(n, INT_MAX));
        preSum.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];
        return dp(0, n - 1);
    }
};

// Bottom-Up
class Solution
{
public:
    vector<int> preSum;
    int getSum(int left, int right)
    {
        return preSum[right + 1] - preSum[left];
    }
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        preSum.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int s1 = getSum(i + 1, j); // choose ith stone
                int s2 = getSum(i, j - 1); // choose jth stone
                dp[i][j] = max(s1 - dp[i + 1][j], s2 - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

/*
Method:
* alice is trying to maximize the difference
    * in otherwords, she is trying to maximize her score
* bob is trying to minimize the difference
    * in otherwords, he is trying to maximize his score
* So, in this problem at any given point both alice and bob are trying to get the maximum score possible
*
* Let's say there are n=5 stones
    * now, alice starts first
    * so for the whole process
    * ```alice gain = a1 + a3 + a5```
    * ```bob gain = b2 + b4```
        * where
        * ```a1 = sum obtained by alice in the 1st round```
        * ```b2 = sum obtained by bob in the 2nd round```

    * Now,
    * ```diff = (a1+a3+a5)-(b2+b4) for stones[1,5]```
    * Note that,
    * ```a1>b2>a3>b4>a5```
    * why?
        * because each stone[i]>=1
        * so if
        * ```a1 = stone[i]+....+stone[j]```
        * ```b2 = stone[i+1]+....stone[j] or stone[i]+...stone[j-1]```
        * so it is clear that b2<a1

    * getting back at diff
    * we can rewrite it as
    * ```diff = a1-(b2+b4 -a3-a5)```
        * i.e a1 - (diff for stones[2,5])
        * again,
        * ```diff = a1-(b2-(a3+a5 - b4))```
        * i.e  = a1-(b2- (diff for stones[3,5]))
        * so,
        * ```diff = a1-(b2-(a3-(b4-a5)))```
* in general
* we can say that
* **```diff = current_round_gain - (sub_problem_diff)```**

* Also, Note that,
* **we don't have to keep track of turns**
* why?
    * ```Alice goal: maximize the final diff```
    * ```Bob goal : minimuze the final diff```
    * From this
    * **```final diff = a1-(b2-(a3-(b4-a5))) = a1-(subproblem)```**
    * we can see that
    * Alice wants to
        * maximize a1-subproblem,
        * so Alice wants to maximize a3-subproblem due to the double negation.
    * The same goes for Bob.
        * Bob wants to minimize a1-subproblem = final_diff,
        * so Bob wants to maximize b2-subproblem = diff at bob turn,
        * then maximize b4-subproblem due to double negation.
        * (i.e we can say bob will try to maximize the diff at his turn so that the final diff is as min as possible)
* So,
* we can conclude that
* **goal of bob = minimize the final diff**
* **goal of alice = maximize the final diff**
* ** but at each round both will try to maximize the current diff**


**Implementation:**

* dp[i][j] = alex_sum - bob_sum = difference
* we create a prefixSum array to store the prefixSum
    * prefixSum(i) = sum of all the elements from 0 to i(i not included)
    * prefixSum(j) = sum of all the elements from 0 to j(j not included)
* so if we want to find sum from index i to j
    * sum = prefixSum(j+1)-prefixSum(i)
* if alice chooses ith pile:
    * diff = sum(i-1,j) - dp[i+1][j]
* if alice chooses jth pile:
    * diff = sum(i-1,j) - dp[i+1][j]
* **ans = dp[0][n-1]**
*/