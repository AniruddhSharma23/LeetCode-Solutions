class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> v;
        int k = 0;
        while (n--)
        {
            if ((to_string(n)).find('0') == string::npos && (to_string(k)).find('0') == string::npos)
                return v = {k, n};
            k++;
        }
        return v;
    }
};