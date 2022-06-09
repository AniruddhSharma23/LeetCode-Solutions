class Solution
{
public:
    string generateTheString(int n)
    {
        string s;
        if (n % 2 == 0)
        {
            s += "b";
            n--;
        }
        s.append(n, 'a');
        return s;
    }
};