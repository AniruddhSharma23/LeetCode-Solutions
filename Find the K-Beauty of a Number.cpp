class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string s = to_string(num);
        int n = s.length();
        int p = 0;
        for (int i = 0; i <= n - k; i++)
        {
            int d = 0;
            for (int j = i; j < i + k; j++)
            {
                d *= 10;
                d += s[j] - '0';
            }
            if (d != 0 && num % d == 0)
            {
                p++;
            }
        }
        return p;
    }
};