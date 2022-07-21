class Solution
{
public:
    int countPalindromicSubsequences(string s)
    {
    }
};
/*
**Approach:**

```dp[i][j] = no of palindromic subsequence in a string s with starting index=i and ending index=j```
if(s[i]==s[j])
dp[i][j] = 1+dp[i][j-1] + dp[i+1][j]
*/
