class Solution
{
public:
    int minimumMoves(string s)
    {
        int n = s.length();
        int k = 0;
        int i;
        while (i < n)
        {
            if (s[i] == 'X')
            {
                k++;
                i += 3;
            }
            else
                i++;
        }
        return k;
    }
};