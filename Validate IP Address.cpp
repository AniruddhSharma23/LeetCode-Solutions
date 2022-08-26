class Solution
{
public:
    bool isIPv4(string s)
    {
        if (count(s.begin(), s.end(), '.') != 3)
            return false;
        vector<string> v = split(s, '.');
        if (v.size() != 4)
            return false;
        for (string x : v)
        {
            int n = x.length();
            if (n == 0 || n > 3)
                return false;
            if (n > 1 && x[0] == '0')
                return false;
            for (char c : x)
                if (!isdigit(c))
                    return false;
            if (stoi(x) > 255)
                return false;
        }
        return true;
    }

    bool isIPv6(string s)
    {
        if (count(s.begin(), s.end(), ':') != 7)
            return false;
        vector<string> v = split(s, ':');
        if (v.size() != 8)
            return false;
        for (string x : v)
        {
            int n = x.length();
            if (n == 0 || n > 4)
                return false;
            for (char c : x)
            {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F'))
                    return false;
            }
        }
        return true;
    }
    vector<string> split(string str, char c)
    {
        vector<string> v;
        string k;
        istringstream in(str);
        while (getline(in, k, c))
        {
            v.push_back(k);
        }
        return v;
    }
    string validIPAddress(string q)
    {
        return isIPv4(q) ? "IPv4" : (isIPv6(q) ? "IPv6" : "Neither");
    }
};