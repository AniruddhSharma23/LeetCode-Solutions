class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {
        if (num == 0)
            return "0";
        int sign = (num < 0) ^ (den < 0) ? -1 : 1;
        long long n = abs(n);
        long long d = abs(d);
        unordered_map<int, int> mp;
        string s = "";
        if (sign == -1)
            s += "-";
        long long int i = n / d;
        long long int r = n % d;
        s += to_string(i);
        if (r == 0)
            return s;
        s += ".";
        long long int index = s.size();
        while (r)
        {
            if (mp[r])
            {
                s.insert(mp[r], "(");
                break;
            }
            else
            {
                mp[r] = index;
                r *= 10;
                long long int q = r / d;
                s += to_string(q);
                r %= d;
                index++;
                if (r == 0)
                    return s;
            }
        }
        s += ")";
        return s;
    }
};