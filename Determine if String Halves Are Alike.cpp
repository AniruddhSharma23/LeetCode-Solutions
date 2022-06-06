class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int k = 0;
        int n = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                (i < n / 2) ? k++ : k--;
            }
        }

        return (k == 0);
    }
};