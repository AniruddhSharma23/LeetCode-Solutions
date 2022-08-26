class Solution
{
public:
    string nearestPalindromic(string s)
    {
        int n = s.length();
        if (n == 1)
            return to_string(stol(s) - 1);
        vector<long> v;
        long a = pow(10, n - 1) - 1;
        long b = pow(10, n) + 1;
        v.push_back(a);
        v.push_back(b);
        int m = (n + 1) / 2;
        long prefix = stol(s.substr(0, m));
        vector<long> cases = {prefix, prefix - 1, prefix + 1};
        for (auto x : cases)
        {
            string postfix = to_string(x);
            if (n % 2 == 1)
                postfix.pop_back();
            reverse(postfix.begin(), postfix.end());
            string k = to_string(x) + postfix;
            v.push_back(stol(k));
        }
        long diff = LONG_MAX;
        long res;
        long x = stol(s);
        for (auto k : v)
        {
            if (k != x && diff > abs(k - x))
            {
                diff = abs(k - x);
                res = k;
            }
            else if (diff == abs(k - x))
                res = min(res, k);
        }
        return to_string(res);
    }
};