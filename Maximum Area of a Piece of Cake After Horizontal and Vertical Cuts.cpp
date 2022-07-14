class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        auto nh = horizontalCuts.size();
        auto nv = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        auto hmax = max(horizontalCuts[0], h - horizontalCuts[nh - 1]);
        auto vmax = max(verticalCuts[0], w - verticalCuts[nv - 1]);
        for (auto i = 0; i < nh - 1; i++)
            hmax = max(hmax, horizontalCuts[i + 1] - horizontalCuts[i]);
        for (auto j = 0; j < nv - 1; j++)
            vmax = max(vmax, verticalCuts[j + 1] - verticalCuts[j]);
        return (long)hmax * vmax % 1000000007;
    }
};