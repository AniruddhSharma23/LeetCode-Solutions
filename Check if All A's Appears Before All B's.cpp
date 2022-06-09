class Solution
{
public:
    bool checkString(string s)
    {
        if (s.find('b') == string::npos)
        {
            return true;
        }
        int k = s.find('b');
        string p = s.substr(k + 1);
        if (p.find('a') == string::npos)
        {
            return true;
        }
        return false;
    }
};