class Solution
{
public:
    int convert(string &s)
    {
        return s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4];
    }
    int convertTime(string current, string correct)
    {
        int d = convert(correct) - convert(current), k = 0;
        k += (d / 60) + ((d % 60) / 15) + ((d % 15) / 5) + (d % 5);
        return k;
    }
};

/*
class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int h1 = (current[0] - '0') * 10 + (current[1] - '0');
        int m1 = (current[3] - '0') * 10 + (current[4] - '0');
        int h2 = (correct[0] - '0') * 10 + (correct[1] - '0');
        int m2 = (correct[3] - '0') * 10 + (correct[4] - '0');

        if (h1 > h2 || (h1 == h2 && m1 > m2))
            return -1;
        if (h1 == h2 && m1 == m2)
            return 0;

        int k = 0;
        if (m1 <= m2)
        {
            int d = m2 - m1;
            k += (h2 - h1);
            k += d / 15;
            d %= 15;
            k += d / 5;
            d %= 5;
            k += d;
        }
        else
        {
            int d = 60 - m1 + m2;
            k += (h2 - h1 - 1);
            k += d / 15;
            d %= 15;
            k += d / 5;
            d %= 5;
            k += d;
        }
        return k;
    }
};
*/