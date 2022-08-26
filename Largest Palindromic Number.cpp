class Solution
{
public:
    string largestPalindromic(string num)
    {
        int n = num.length();
        vector<int> v(10, 0);
        for (char c : num)
            v[c - '0']++;
        bool check = false;
        char mid = '#';
        string s = "";
        for (int i = 9; i >= 0; i--)
        {
            if (s == "" && i == 0)
                continue;
            while (v[i] > 1)
            {
                s.push_back(i + '0');
                v[i] -= 2;
            }
            if (v[i] == 1 && check == false)
            {
                mid = i + '0';
                check = true;
            }
        }
        string k = string(s.rbegin(), s.rend());
        if (mid == '#' && s == "")
            return "0";
        if (mid != '#')
            s.push_back(mid);
        s = s + k;
        return s;
    }
};