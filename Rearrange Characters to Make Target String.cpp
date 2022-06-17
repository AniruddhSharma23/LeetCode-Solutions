class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int k = INT_MAX;
        int ns = s.length();
        int nt = target.length();
        for (char c : s)
            mp1[c]++; // store the occurence of every character of s in mp1
        for (char c : target)
            mp2[c]++; // store the occurence of every character of target in mp2
        for (char c : target)
            k = min(k, mp1[c] / mp2[c]);
        return (k == INT_MAX) ? 0 : k;
    }
};
