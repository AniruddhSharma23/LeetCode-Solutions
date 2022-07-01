class Solution
{
public:
    void solve(int i, int n, string s, vector<string> &ans, string digits, vector<string> &values)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }
        int number = digits[i] - '0';
        int len = values[number].length();
        for (int j = 0; j < len; j++)
        {
            s.push_back(values[number][j]);
            solve(i + 1, n, s, ans, digits, values);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        vector<string> values = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        if (n == 0)
            return {};
        solve(0, n, "", ans, digits, values);
        return ans;
    }
};