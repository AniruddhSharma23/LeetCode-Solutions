class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        int cnt = 0;
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                if (s[i] == s[j])
                {
                    if (gap == 1 || dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        cnt++;
                    }
                }
                else
                    dp[i][j] = false;
            }
        }
        return cnt;
    }
};