class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int k = count(s.begin(), s.end(), letter);
        int n = s.length();
        return (k * 100) / n;
    }
};