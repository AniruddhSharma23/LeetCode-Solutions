class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string k = "";
        while (columnNumber--)
        {
            k.push_back(columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        reverse(k.begin(), k.end());
        return k;
    }
};