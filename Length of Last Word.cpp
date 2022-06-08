class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int l = s.size() - 1;
        while (l >= 0 && s[l] == ' ')
        {
            l--;
        }
        int k = 0;
        while (l >= 0 && s[l] != ' ')
        {
            l--;
            k++;
        }
        return k;
    }
};