class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string s;
        int k = abs(num);
        while (k > 0)
        {
            s.push_back(k % 7 + '0');
            k /= 7;
        }
        reverse(s.begin(), s.end());
        if (num < 0)
        {
            s.insert(s.begin(), '-');
        }
        return s;
    }
};