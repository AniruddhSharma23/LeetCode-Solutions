class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (n == 1 && s[0] == '0')
            return true;
        if (s[0] == '0' || n > 3)
            return false;
        int k = stoi(s);
        if (k >= 0 && k <= 255)
            return true;
        return false;
    }
    void solve(string s, string curr, int i, int cnt, int n, vector<string> &ans)
    {
        if (cnt > 4)
            return;
        if (i == n && cnt == 4)
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string z = curr;
        for (int j = i; j < min(i + 3, n); j++)
        {
            string p = s.substr(i, j - i + 1);
            if (isValid(p))
            {
                z += p + '.';
                solve(s, z, j + 1, cnt + 1, n, ans);
                z = curr;
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.length();
        vector<string> ans;
        string curr = "";
        solve(s, "", 0, 0, n, ans);
        return ans;
    }
};