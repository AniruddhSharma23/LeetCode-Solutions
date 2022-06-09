class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int a = 0;
        int b = 0;
        for (char c : moves)
        {
            switch (c)
            {
            case 'U':
                a++;
                break;
            case 'D':
                a--;
                break;
            case 'L':
                b++;
                break;
            case 'R':
                b--;
                break;
            }
        }
        return ((a == 0) && (b == 0));
    }
};