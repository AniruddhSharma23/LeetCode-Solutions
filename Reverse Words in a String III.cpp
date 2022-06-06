class Solution
{
public:
    string reverseWords(string s)
    {
        int k = 0;
        int i = 0;
        for (i; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + k, s.begin() + i);
                k = i + 1;
            }
        }
        reverse(s.begin() + k, s.begin() + i);
        return s;
    }
};