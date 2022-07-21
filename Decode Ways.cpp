/*
**Brute-force: Recursion**

**Approach:**
* at every index in the string we have got 2 choices :
    * Pick only current element as a single value between [1-9]
    * Pick 2 elements i.e current as well as next element to make a couple. This value will be [10, 26]
* Thus we solve the problem recursively with the above 2 choices
* and whenever we reach the end i.e index >= n simply return 1, which means that we have got one way to decode the string.
*
* **Case 1: single character**
    * we can't take '0'
    * elements in range [1,9] is covered here in this case
    * so we recursively call for index+1
* **Case 2: Two characters**
    * we need to check
    * idx+1 < n , mean we are no going out of bounds.
    * we have two subparts
    * -> s[idx] == '1' && s[idx+1] <= '9' , here range [10, 19] is covered
    * -> s[idx] == '2' && s[idx+1] < '7' , here range [20, 26] is covered
    * Now, in this case, we need to increment index+2, since we have already included next element along with current element
* **Base Case:**
    * if index>=n
    * we have reach the end so we found a way to decode it so return 1
*/
class Solution
{
public:
    int calc(string s, int index)
    {
        int n = s.length();
        if (index >= n)
            return 1;
        int ways = 0;
        if (s[index] != '0')
            ways = calc(s, index + 1);
        if ((index + 1 < n) && ((s[index] == '1' && s[index + 1] <= '9') || (s[index] == '2' && s[index + 1] <= '6')))
            ways += calc(s, index + 2);
        return ways;
    }
    int numDecodings(string s)
    {
        int n = s.length();
        return calc(s, 0);
    }
};

/*
**DP-Solution**

**Top-down Approach:**

* ```dp[i] = ways to decode substring of s starting with index = i```

**Approach:**

* the idea is same but you can notice that there are many repetitive calls in the above code
* so we will store the ways in a dp array
* If its value already exist no need to calcuate again. Just return dp[i].
*/
class Solution
{
public:
    vector<int> dp;
    int calc(string s, int index)
    {
        int n = s.length();
        if (index < n && s[index] == '0')
            return 0;
        if (index >= n)
            return 1;
        if (dp[index] != -1)
            return dp[index];
        int ways = 0;
        if (s[index] != '0')
            ways = calc(s, index + 1);
        if ((index + 1 < n) && ((s[index] == '1' && s[index + 1] <= '9') || (s[index] == '2' && s[index + 1] <= '6')))
            ways += calc(s, index + 2);
        return dp[index] = ways;
    }
    int numDecodings(string s)
    {
        int n = s.length();
        dp.assign(n, -1);
        return calc(s, 0);
    }
};
/*
 * Time Complexity: O(N)
 * Space Complexity: O(N)
Bottom-up Approach:**
*/

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // no string
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
                dp[i] = dp[i + 1];
            if ((i + 1 < n) && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] <= '6')))
                dp[i] += dp[i + 2];
        }
        return dp[0]; // ways to decode the substring of s starting from index=0 i.e string s
    }
};
/*
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

/*
** Optimized Bottom-up Approach:**

* we can see that we only need 3 parameters
* Current state, let name dp corresponding to dp[i]
* Last state, let name dp1 corresponding to dp[i+1]
* Last twice state, let name dp2 corresponding to dp[i+2]
* so we store them in 3 variables
*/
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        int dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
                dp = dp1;
            if ((i + 1 < n) && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] <= '6')))
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
/*
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
