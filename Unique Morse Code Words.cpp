class Solution
{
public:
    string s[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int uniqueMorseRepresentations(vector<string> &words)
    {
        set<string> st;
        for (int i = 0; i < words.size(); i++)
        {
            string k;
            for (int j = 0; j < words[i].size(); j++)
            {
                k = k + s[words[i][j] - 'a'];
            }
            st.insert(k);
        }
        return st.size();
    }
};