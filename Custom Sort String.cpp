class Solution
{
public:
    string customSortString(string order, string s)
    {
        int n = order.length();
        int m = s.length();
        unordered_map<char, int> ms;
        for (char c : s)
            ms[c]++;
        string k = "";
        for (char c : order)
        {
            if (ms.find(c) != ms.end())
            {
                while (ms[c]--)
                    k += c;
                ms[c] = -1;
            }
        }
        for (char c : s)
        {
            if (ms[c] != -1)
                k += c;
        }
        return k;
    }
};