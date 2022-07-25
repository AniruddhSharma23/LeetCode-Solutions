class TrieNode
{
public:
    TrieNode *child[2];
    TrieNode()
    {
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};
class Solution
{

public:
    TrieNode *newNode; // root of the trie

    void insert(int x)
    {
        TrieNode *t = newNode;
        bitset<32> bt(x);
        for (int i = 31; i >= 0; i--)
        {
            if (t->child[bt[i]] == NULL)
                t->child[bt[i]] = new TrieNode();
            t = t->child[bt[i]];
        }
    }
    int findMaximumXOR(vector<int> &nums)
    {
        newNode = new TrieNode();
        for (auto &x : nums)
            insert(x);
        int ans = 0;
        for (auto x : nums)
            ans = max(ans, maxXOR(x));
        return ans;
    }
    int maxXOR(int x)
    {
        TrieNode *t = newNode;
        bitset<32> bt(x);
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (t->child[!bt[i]])
            {
                ans += 1 << i;
                t = t->child[!bt[i]];
            }
            else
                t = t->child[bt[i]];
        }
        return ans;
    }
};