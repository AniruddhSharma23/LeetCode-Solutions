class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = 1;
            while (j < n)
            {
                if (s[j] - s[i] == 1)
                {
                    k++;
                    j++;
                    i++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, k);
        }
        return ans;
    }
};