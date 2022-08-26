class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int value;
        node *prev;
        node *next;
        node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node *> mp;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(node *curr)
    {
        node *l = curr->prev;
        node *r = curr->next;
        l->next = r;
        r->prev = l;
    }
    void addNode(node *curr)
    {
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        head->next = curr;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        node *curr = mp[key];
        int val = curr->value;
        mp.erase(key);
        deleteNode(curr);
        addNode(curr);
        mp[key] = head->next;
        return val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// using stl:

class LRUCache
{
public:
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    LRUCache(int capacity) : capacity{capacity}
    {
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        li.splice(li.begin(), li, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            li.splice(li.begin(), li, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (mp.size() == capacity)
        {
            int del_key = li.back().first;
            mp.erase(del_key);
            li.pop_back();
        }
        li.emplace_front(key, value);
        mp[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
