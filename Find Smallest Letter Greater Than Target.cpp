class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char c = letters[0];
        int k = target - '0';
        for (int i = 0; i < letters.size(); i++)
        {
            if ((letters[i] - '0' - k) > 0)
            {
                c = letters[i];
                break;
            }
        }
        return c;
    }
};