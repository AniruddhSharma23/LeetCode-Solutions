class Solution
{
public:
    string maximumTime(string time)
    {
        char a, b, c, d;
        a = time[0];
        b = time[1];
        c = time[3];
        d = time[4];
        if (a == '?' && b == '?')
        {
            a = '2';
            b = '3';
        }
        else if (a == '?')
        {
            (b - '0' < 4) ? a = '2' : a = '1';
        }
        else if (b == '?')
        {
            (a - '0' == 2) ? b = '3' : b = '9';
        }
        if (c == '?')
            c = '5';
        if (d == '?')
            d = '9';
        time[0] = a;
        time[1] = b;
        time[3] = c;
        time[4] = d;
        return time;
    }
};