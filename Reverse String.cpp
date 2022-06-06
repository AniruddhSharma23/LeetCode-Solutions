class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l, h, n;
        n = s.size();
        l = 0;
        h = n - 1;
        while (l < h)
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
    }
};