/*
Bézout's identity (also called Bézout's lemma) is a theorem in the elementary theory of numbers:

let a and b be nonzero integers and let d be their greatest common divisor. Then there exist integers x
and y such that ax+by=d

In addition, the greatest common divisor d is the smallest positive integer that can be written as ax + by

every integer of the form ax + by is a multiple of the greatest common divisor d
*/

// math:
class Solution
{
public:
    bool canMeasureWater(int x, int y, int t)
    {
        if (x + y == z || x == z || y == z)
            return true;
        if (x + y < z)
            return false;
        int d = __gcd(x, y);
        return (z % d == 0);
    }
};

// bfs:
class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y == z || x == z || y == z)
            return true;
        if (x + y < z)
            return false;
        int m = x + y; // max capacity
        vector<int> v = {x, -x, y, -y};
        queue<int> q;
        q.push(0);
        vector<int> vis(m + 1, 0);
        vis[0] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr == z)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int k = curr + v[i];
                if (k >= 0 && k <= m && vis[k] == 0)
                {
                    q.push(k);
                    vis[k] = 1;
                }
            }
        }
        return false;
    }
};

// dfs based:

class Solution
{
public:
    bool dfs(int x, int y, int z, int m, int curr, vector<int> &vis)
    {
        if (curr < 0 || curr > m || vis[curr] == 1)
            return false;
        if (curr == z)
            return true;
        vis[curr] = 1;
        bool a = dfs(x, y, z, m, curr + x, vis);
        bool b = dfs(x, y, z, m, curr - x, vis);
        bool c = dfs(x, y, z, m, curr + y, vis);
        bool d = dfs(x, y, z, m, curr - y, vis);
        return a || b || c || d;
    }
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y == z || x == z || y == z)
            return true;
        if (x + y < z)
            return false;
        int m = x + y; // max capacity
        vector<int> vis(m + 1, 0);
        return dfs(x, y, z, m, 0, vis);
    }
};