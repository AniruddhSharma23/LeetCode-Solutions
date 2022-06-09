class Solution
{
public:
    int calc(string s)
    {
        int n = 0;
        for (char c : s)
        {
            n = n * 10 + (c - 'a');
        }
        return n;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        int a = calc(firstWord);
        int b = calc(secondWord);
        int c = calc(targetWord);
        return ((a + b) == c);
    }
};