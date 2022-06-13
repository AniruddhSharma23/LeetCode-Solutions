class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        int n = password.length();
        if (n < 8)
        {
            return false;
        }
        int k = 0;
        int l, u, d, s;
        l = u = d = s = 0;
        for (int i = 0; i < n; i++)
        {
            if ((password[i] <= 90 && password[i] >= 65))
            {
                l++;
            }
            if (password[i] <= 122 && password[i] >= 97)
            {
                u++;
            }
            if ((password[i] <= 57 && password[i] >= 48))
            {
                d++;
            }
            if ((password[i] <= 47 && password[i] >= 32) || (password[i] <= 64 && password[i] >= 58) || (password[i] <= 96 && password[i] >= 91) || (password[i] <= 126 && password[i] >= 123))
            {
                s++;
            }
        }
        if (l < 1 || u < 1 || d < 1 || s < 1)
        {
            return false;
        }
        for (int i = 1; i < n; i++)
        {
            if (password[i] == password[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};