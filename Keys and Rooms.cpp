class Solution
{
public:
    void dfs(vector<vector<int>> &rooms, vector<bool> &vis, int u)
    {
        vis[u] = true;
        for (auto v : rooms[u])
            if (vis[v] == false)
                dfs(rooms, vis, v);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, vis, 0);
        for (auto x : vis)
            if (x == false)
                return false;
        return true;
    }
};