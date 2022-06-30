class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> freq;
        unordered_map<int, int> unique_freq;
        for (char c : s)
            freq[c]++;
        int k = 0;
        for (auto &x : freq)
        {
            int f = x.second; // frequency
            if (unique_freq[f] != 0)
            {
                while (f > 0 && unique_freq[f] != 0)
                {
                    f--;
                    k++;
                }
            }
            if (f > 0)
                unique_freq[f]++;
        }
        return k;
    }
};