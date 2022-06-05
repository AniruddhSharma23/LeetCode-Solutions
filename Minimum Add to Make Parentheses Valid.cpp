class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int k = 0;
        int p = 0;
        for (auto c : s)
        {
            (c == '(') ? k++ : ((k > 0) ? k-- : p++);
        }
        return p + k;
    }
};