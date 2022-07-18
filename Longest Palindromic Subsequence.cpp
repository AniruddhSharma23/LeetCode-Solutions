class Solution
{
public:
    int lcs(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s)
    {
        string k = s;
        reverse(s.begin(), s.end());
        return lcs(s, k);
    }
};