class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> res;
        int i = num.size() - 1, carry = k;
        while (i >= 0 || carry)
        {
            if (i >= 0)
                carry += num[i--];
            res.push_back(carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};