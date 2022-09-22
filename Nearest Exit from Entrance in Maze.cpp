class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &e)
    {
        int m = maze.size();
        int n = maze[0].size();
        queue<array<int, 3>> q;
        q.push({e[0], e[1], 0});
        vector<vector<int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (!q.empty())
        {
            int i = q.front()[0];
            int j = q.front()[1];
            int steps = q.front()[2];
            q.pop();
            if ((i != e[0] || j != e[1]) && (i == 0 || j == 0 || i == m - 1 || j == n - 1))
                return steps;
            for (int k = 0; k < 4; k++)
            {
                int i1 = i + d[k][0];
                int j1 = j + d[k][1];

                if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && maze[i1][j1] == '.')
                {
                    maze[i1][j1] = '+';
                    q.push({i1, j1, steps + 1});
                }
            }
        }
        return -1;
    }
};