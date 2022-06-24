typedef pair<int, char> pr;
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        priority_queue<pr> pq;
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (auto &x : mp)
            pq.push({x.second, x.first});
        string k = "";
        while (!pq.empty())
        {
            auto t = pq.top();
            k += string(t.first, t.second);
            pq.pop();
        }
        return k;
    }
};
