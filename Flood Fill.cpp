class Solution
{
public:
    void dfs(vector<vector<int>> &image, int color, int i, int j, int c)
    {
        int m = image.size();
        int n = image[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != c || image[i][j] == color)
            return;
        image[i][j] = color;
        dfs(image, color, i + 1, j, c);
        dfs(image, color, i - 1, j, c);
        dfs(image, color, i, j + 1, c);
        dfs(image, color, i, j - 1, c);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        dfs(image, color, sr, sc, image[sr][sc]);
        return image;
    }
};