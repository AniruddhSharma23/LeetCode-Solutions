class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int k = 0;
        for (auto x : patterns)
        {
            if (word.find(x) != std::string::npos)
            {
                k++;
            }
        }
        return k;
    }
};