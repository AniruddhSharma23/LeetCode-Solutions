class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // store the wordDict in a set
        int n = s.length();
        vector<bool> dp(n + 1, false); // dp[i] = whether a valid word ends at index i-1 or not
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--) // move back from i
            {
                if (dp[j] == true) // a valid word ends at j-1
                {
                    string k = s.substr(j, i - j); // substring from index=j to index=i-1
                    // k = new invalid word sequence (s[j..i-1]), if we find it in st we declare it as a valid word
                    if (st.find(k) != st.end())
                    {
                        dp[i] = true;
                        break; // move to the next i
                    }
                }
            }
        }
        return dp[n]; // whether a valid word ends at n-1 or not
    }
};
