class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int n1 = words1.size();
        int n2 = words2.size();
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for (auto x : words1)
        {
            mp1[x]++;
        }
        for (auto x : words2)
        {
            mp2[x]++;
        }
        int k = 0;
        for (auto &x : mp1)
        {
            string s = x.first;
            if (mp2.find(s) != mp2.end() && mp1[s] == 1 && mp2[s] == 1)
            {
                k++;
            }
        }
        return k;
    }
};