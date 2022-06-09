class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int n = word.find(ch);
        reverse(word.begin(), word.begin() + n);
        return word;
    }
};