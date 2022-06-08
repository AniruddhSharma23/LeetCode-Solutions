class Solution
{
public:
    bool isOverlapped(int a1, int a2, int b1, int b2)
    {
        return (a2 > b1) & (b2 > a1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int a = abs((ax2 - ax1) * (ay2 - ay1));
        int b = abs((bx2 - bx1) * (by2 - by1));
        int x = 0;
        int y = 0;
        if (isOverlapped(ax1, ax2, bx1, bx2))
        {
            vector<int> v = {ax1, ax2, bx1, bx2};
            sort(v.begin(), v.end());
            x = (v[2] - v[1]);
        }
        if (isOverlapped(ay1, ay2, by1, by2))
        {
            vector<int> k = {ay1, ay2, by1, by2};
            sort(k.begin(), k.end());
            y = (k[2] - k[1]);
        }
        int s = a + b - (x * y);
        return s;
    }
};