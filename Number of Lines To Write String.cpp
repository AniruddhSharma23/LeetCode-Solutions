class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int n = s.length();
        int a = 1;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            k += widths[s[i] - 97];
            if (k > 100)
            {
                a++;
                k = 0;
                i--;
            }
        }
        return {a, k};
    }
};