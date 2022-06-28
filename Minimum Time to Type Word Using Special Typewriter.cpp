class Solution
{
public:
    int minTimeToType(string word)
    {
        int n = word.length();
        int k = 0;
        int tpos = 1;
        for (char c : word)
        {
            int cpos = c - 96;
            int d = abs(cpos - tpos);
            k += min(d, 26 - d);
            k++;
            tpos = cpos;
        }
        return k;
    }
};