class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int newVal = carry + digits[i];
            carry = newVal / 10;
            digits[i] = newVal % 10;
        }
        if (carry != 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};