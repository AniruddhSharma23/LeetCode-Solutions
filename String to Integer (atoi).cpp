class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        int index = 0;
        while (index < n && s[index] == ' ')
            index++;
        bool isneg = false;
        if (index < n)
        {
            if (s[index] == '-')
            {
                isneg = true;
                index++;
            }
            else if (s[index] == '+')
                index++;
        }
        int k = 0;
        while (index < n && isdigit(s[index]))
        {
            int d = s[index] - '0';
            if (k > INT_MAX / 10 || (k == INT_MAX / 10 && d > 7))
            {
                return isneg ? INT_MIN : INT_MAX;
            }
            k = k * 10 + d;
            index++;
        }
        return isneg ? -k : k;
    }
};