class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num == 0)
            return num;
        bool neg = false;
        if (num < 0)
            neg = true;
        string s = to_string(abs(num));
        sort(s.begin(), s.end());
        if (neg == true)
        {
            reverse(s.begin(), s.end());
        }
        else
        {
            if (s[0] == '0')
            {
                int i = 0;
                while (i < s.length() && s[i] == '0')
                    i++;
                swap(s[i], s[0]);
            }
        }
        return (neg == true) ? -stoll(s) : stoll(s);
    }
};