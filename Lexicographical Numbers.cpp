class Trie
{
public:
    vector<Trie *> v;
    int data;
    bool isEnd;
    Trie()
    {
        v = vector<Trie *>(10, NULL);
        data = -1;
        isEnd = false;
    }
};
class Solution
{
    void insert(Trie *node, int a)
    {
        Trie *root = node;
        string key = to_string(a);
        for (auto &x : key)
        {
            int i = x - '0';
            if (root->v[i] == NULL)
                root->v[i] = new Trie();
            root = root->v[i];
        }
        root->isEnd = true;
        root->data = a;
    }
    vector<int> ans;
    void search(Trie *root)
    {
        if (root->isEnd)
            ans.push_back(root->data);
        for (int i = 0; i < 10; i++)
            if (root->v[i])
                search(root->v[i]);
    }

public:
    vector<int> lexicalOrder(int n)
    {
        ans.clear();
        Trie *root = new Trie();
        for (int i = 1; i <= n; i++)
            insert(root, i);
        search(root);
        return ans;
    }
};