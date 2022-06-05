class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int l = 0, r = matrix.size() - 1;

        while (l < r)
        {
            for (int i = 0; i < r - l; i++)
            {
                int top = l, bottom = r;

                // save top left.
                int topleft = matrix[top][l + i];

                // move bottom left to top left (left edge)
                matrix[top][l + i] = matrix[bottom - i][l];

                // move bottom right to bottom left (bottom edge)
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move top right to bottom right (right edge)
                matrix[bottom][r - i] = matrix[top + i][r];

                // apply saved top left to top right (top edge)
                matrix[top + i][r] = topleft;
            }
            l++, r--; // shrink the circle.
        }
    }
};