class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        int k = coordinates[0] - 96 + coordinates[1] - '0';
        if (k & 1)
        {
            return true;
        }
        return false;
    }
};