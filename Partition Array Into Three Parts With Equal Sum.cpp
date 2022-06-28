class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int d = sum % 3;
        if (d != 0)
            return false;
        int s = sum / 3;
        int pref = 0;
        bool first, second, third;
        first = second = third = false;
        for (auto x : arr)
        {
            pref += x;
            if (!first && pref == s)
                first = true;
            else if (first && !second && pref == 2 * s)
                second = true;
            else if (first && second && pref == 3 * s)
                third = true;
        }
        return (first && second && third);
    }
};