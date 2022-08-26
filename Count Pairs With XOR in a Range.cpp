struct TrieNode
{
    TrieNode *child[2];
    int cnt;
    TrieNode()
    {
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};
void insert(TrieNode *root, int n)
{
    bitset<32> bt(n);
    for (int i = 31; i >= 0; i--)
    {
        int x = bt[i];
        if (!root->child[x])
            root->child[x] = new TrieNode();
        root->child[x]->cnt += 1;
        root = root->child[x];
    }
}

class Solution
{
private:
    int calc(TrieNode *root, int n, int k)
    {
        int cntPairs = 0;
        bitset<32> bn(n);
        bitset<32> bk(k);
        for (int i = 31; i >= 0 && root; i--)
        {
            int x = bn[i];
            int y = bk[i];
            if (y == 0)
            {
                root = root->child[x];
                continue;
            }
            if (root->child[x])
                cntPairs += root->child[x]->cnt;
            root = root->child[1 - x];
        }
        return cntPairs;
    }

public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        TrieNode *root = new TrieNode();
        int cnt = 0;
        for (auto &num : nums)
        {
            cnt += calc(root, num, high + 1) - calc(root, num, low);
            insert(root, num);
        }

        return cnt;
    }
};