class LRUCache
{
public:
    list<pair<int, int>> C;
    unordered_map<int, list<pair<int, int>>::iterator> M;
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (M.count(key))
        { // key present
            auto it = M[key];
            C.splice(C.begin(), C, it); // bring to front
            return C.front().second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        { // key already present (already brought to front)
            C.front().second = value;
            return;
        }
        if (C.size() >= capacity)
        { // remove least recently used element
            int key_to_remove = C.back().first;
            C.pop_back();
            M.erase(key_to_remove);
        }
        C.push_front({key, value});
        M[key] = C.begin();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */